#include "MouseBehaviour.hpp"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>
#include "mge/core/Timer.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"
#include "mge/puzzles/Inventory.h"
#include <SFML/Window.hpp>


MouseBehaviour::MouseBehaviour(GameObject* pCameraPosition,Camera* pCamera, float pDistance):AbstractBehaviour()
{
    _cameraPosition = pCameraPosition;
    _camera = pCamera;
    //ctor
}

MouseBehaviour::~MouseBehaviour()
{

}

void MouseBehaviour::update(float step)
{
    if(KeyboardBehaviour::GetKeyDown(sf::Keyboard::F))
    {
        Hud();
    }
    if(KeyboardBehaviour::GetKey(sf::Keyboard::Q) && _fredActive)
    {
        if(_scrollers->getLocalPosition().y > 0.243) return;
        _scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, _scrollers->getLocalPosition().y + 0.001, _scrollers->getLocalPosition().z));
    }
    if(KeyboardBehaviour::GetKey(sf::Keyboard::E) && _fredActive)
    {
        if(_scrollers->getLocalPosition().y < -0.283) return;
        _scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, _scrollers->getLocalPosition().y - 0.001, _scrollers->getLocalPosition().z));
    }

    Looking();
    PickUpObject();
    //Position needs to be changed
    sf::Listener::setPosition(_cameraPosition->getLocalPosition().x,_cameraPosition->getLocalPosition().y,_cameraPosition->getLocalPosition().z);
    sf::Listener::setDirection(_direction.x,_direction.y,_direction.z);
}

void MouseBehaviour::Hud()
{
    if(!_fredActive)
    {
        _fredActive = true;

        Mesh* mesh;
        AbstractMaterial* textureMaterial;
        GameObject* GO;

        /**Borders*/
        mesh = Mesh::load("mge/HUD/Borders.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Borders.png"));
        GO = new GameObject ("Borders", glm::vec3(-0.55, -0.35, -1));
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.04, 0.05, 0.1));
        _borders = GO;
        _camera->add(GO);
        /**/

        /**Button*/
        mesh = Mesh::load("mge/HUD/Button.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Button.png"));
        GO = new GameObject ("Button", glm::vec3(0.7, -0.5, -1));
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.04, 0.05, 0.1));
        _button = GO;
        _camera->add(GO);
        /**/


        /**Inventory Box*
        mesh = Mesh::load("mge/HUD/Inventory Box.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Inventory Box.png"));
        GO = new GameObject ("InventoryBox", glm::vec3(-0.56, 0.05, -0.9));
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.04, 0.05, 0.1));
        _inventoryBox = GO;
        _camera->add(GO);
        /**/
        for(int i=0;i<10;i++)
        {
            /**Inventory Box*/
            mesh = Mesh::load("mge/HUD/Inventory Box.obj");
            textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Inventory Box.png"));
            GO = new GameObject ("InventoryBox" + i, glm::vec3(-0.56, 0.05 - (i*0.2), -0.9));
            GO->setMesh (mesh);
            GO->setMaterial(textureMaterial);
            GO->scale(glm::vec3(0.04, 0.05, 0.1));
            _inventoryBox = GO;
            _camera->add(GO);
            /**/
        }


        /**Progress Bar Empty*/
        mesh = Mesh::load("mge/HUD/Progress Bar Empty.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Progress Bar Empty.png"));
        GO = new GameObject ("ProgressBar", glm::vec3(0.65, 0.5, -1));
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.04, 0.05, 0.1));
        _progressBar = GO;
        _camera->add(GO);
        /**/

        /**Scroller*/
        mesh = Mesh::load("mge/HUD/Scroller.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Scroller.png"));
        GO = new GameObject ("Scroller", _scrollerPosition);
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.0345, 0.045, 0.1));
        _scrollers = GO;
        _camera->add(GO);
        /**/

        std::cout << "Fred Activated" << std::endl;
    }
    else if(_fredActive)
    {
        _fredActive = false;

        _scrollerPosition = _scrollers->getLocalPosition();
        World::GetInstance()->remove(_borders);
        World::GetInstance()->remove(_button);
        World::GetInstance()->remove(_inventoryBox);
        World::GetInstance()->remove(_progressBar);
        World::GetInstance()->remove(_scrollers);
        std::cout << "Fred Deactivated" << std::endl;

    }
    /**/

}

void MouseBehaviour::PickUpObject()
{
    if(KeyboardBehaviour::GetLeftMouseDown())
    {
        GameObject* Test = PhysicsWorld::GetInstance()->ScreenPosToWorldRay(_camera);
        if(Test != NULL && Test->IsInteractive() == true)
        {
            std::cout << "Hitting a Interactive Model: " << Test->getName() << std::endl;
            Inventory::GetInstance()->PlaceObjectInInventory(Test->getName());
        }
        else
        {
            std::cout << "Nothing Hit" << std::endl;
        }
    }
}

void MouseBehaviour::Looking()
{
    if(KeyboardBehaviour::GetKey(sf::Keyboard::LShift))
    {
        _speed = _debugSpeed;
    }else{
        _speed = _walkingSpeed;
    }

    // Screen sizes
    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;

    if(!_startup)
    {
        _mousePos = sf::Mouse::getPosition();
    }
    else
    {
        _startup = false;
        _mousePos = sf::Vector2i(width / 2, height / 2);
    }
    sf::Mouse::setPosition(sf::Vector2i(width / 2, height / 2));

    // Compute new orientation
    _horizontalAngle += _mouseSpeed * Timer::deltaTime() * float(width /2 - _mousePos.x );
    _verticalAngle   += _mouseSpeed * Timer::deltaTime() * float(height/2 - _mousePos.y );

    // Direction : Spherical coordinates to Cartesian coordinates conversion
    _direction = glm::vec3(
        cos(_verticalAngle) * sin(_horizontalAngle),
        sin(_verticalAngle),
        cos(_verticalAngle) * cos(_horizontalAngle)
    );

    // Right vector
    glm::vec3 right = glm::vec3(
        sin(_horizontalAngle - 3.14f/2.0f),
        0,
        cos(_horizontalAngle - 3.14f/2.0f)
    );

    // Up vector : perpendicular to both _direction and right
    glm::vec3 up = glm::cross( right, _direction );

    _owner->setTransform(glm::inverse (glm::lookAt(_position, _position+_direction, up)));
    _camera->ViewMatrix = glm::lookAt(_position, _position+_direction, up);

    /**
     * Keyboard controls
     */

    _direction.y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _position += _direction * Timer::deltaTime() * _speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _position -= _direction * Timer::deltaTime() * _speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _position -= right * Timer::deltaTime() * _speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _position += right * Timer::deltaTime() * _speed;
    }

}
