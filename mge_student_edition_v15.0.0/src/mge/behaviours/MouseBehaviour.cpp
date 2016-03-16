#include "MouseBehaviour.hpp"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>
#include "mge/core/Timer.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"
#include "mge/puzzles/Inventory.h"
#include <SFML/Window.hpp>
#include "mge/PlayerProgress.h"

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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		std::cout << "left In mouse" << std::endl;
		_startGame = true;
		//LuaLoader::GetInstance()->SetStartGame("true");
	}
	if (_startGame == true)
	{
		if (_fredActive)
		{
			float sizeInv = Inventory::GetInstance()->InventoryList.size();
			if (sizeInv == 0) sizeInv = 1;
			_scrollAmount = 0.526 / sizeInv;
		}

		UpdatePositionFromRigidBody(step);

        /**
		if(Inventory::GetInstance()->InventoryList.size() >= 1 && _inventoryBox1Filled || _inventoryBox2Filled)
        {
            Mesh* mesh;
            AbstractMaterial* textureMaterial;
            GameObject* GO;

            if(_inventoryBox1Filled)
            {
                World::GetInstance()->remove(_inventoryItem1);
            }
            if(_inventoryBox2Filled)
            {
                World::GetInstance()->remove(_inventoryItem2);
            }

            if(Inventory::GetInstance()->InventoryList.size() >= 1)
            {
                InventoryObject InvObj = Inventory::GetInstance()->InventoryList.at(0);
                GO = new GameObject ("InventoryItem2", glm::vec3(-0.437, 0.11, -0.7));
                GO->setMesh (InvObj.GO->getMesh());
                GO->setMaterial(InvObj.GO->getMaterial());

                GO->scale(glm::vec3(0.015, 0.015, 0.015));
                _inventoryItem1 = GO;
                _camera->add(GO);
                _inventoryBox1Filled = true;
            }

            if(Inventory::GetInstance()->InventoryList.size() >= 2)
            {
                InventoryObject InvObj = Inventory::GetInstance()->InventoryList.at(1);
                GO = new GameObject ("InventoryItem2", glm::vec3(-0.437, -0.11, -0.7));
                GO->setMesh (InvObj.GO->getMesh());
                GO->setMaterial(InvObj.GO->getMaterial());
                GO->scale(glm::vec3(0.015, 0.015, 0.015));
                _inventoryItem2 = GO;
                _camera->add(GO);
                _inventoryBox2Filled = true;
            }

        }
        /**/

		if (KeyboardBehaviour::GetKeyDown(sf::Keyboard::F) && _fredPickedup)
		{
			Hud();
		}
		if (KeyboardBehaviour::GetKeyDown(sf::Keyboard::Q) && _fredActive)
		{
			if (_scrollers->getLocalPosition().y > 0.243) return;
			_scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, _scrollers->getLocalPosition().y + _scrollAmount, _scrollers->getLocalPosition().z));
			if (_scrollers->getLocalPosition().y > 0.243) _scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, 0.243, _scrollers->getLocalPosition().z));
		}
		if (KeyboardBehaviour::GetKeyDown(sf::Keyboard::E) && _fredActive)
		{
			if (_scrollers->getLocalPosition().y < -0.283) return;
			_scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, _scrollers->getLocalPosition().y - _scrollAmount, _scrollers->getLocalPosition().z));
			if (_scrollers->getLocalPosition().y < -0.283) _scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, -0.283, _scrollers->getLocalPosition().z));
		}

		Looking();
		PickUpObject();
		//Position needs to be changed
		sf::Listener::setPosition(_position.x, _position.y, _position.z);
		sf::Listener::setDirection(_direction.x, _direction.y, _direction.z);
		PlayerProgress::GetInstance()->Position = _position;
		if (KeyboardBehaviour::GetKeyDown(sf::Keyboard::L))
		{
			_position = PlayerProgress::GetInstance()->LoadGame();
		}
	}
}

void MouseBehaviour::UpdatePositionFromRigidBody(float pStep)
{
    PhysicsWorld::GetInstance()->DynamicsWorld->stepSimulation(pStep, 10);
    btTransform tr = _owner->RigidBody->getCenterOfMassTransform();
    btVector3 vec = tr.getOrigin();
    //std::cout << "current RigidBodyPosition is: " << vec.getX() << "," << vec.getY() << "," << vec.getZ() << std::endl;
    _owner->setLocalPosition(glm::vec3(vec.getX(), vec.getY(), vec.getZ()));
}

void MouseBehaviour::UpdateRigidBodyFromPosition()
{
    btTransform tr = _owner->RigidBody->getCenterOfMassTransform();
    tr.setOrigin(btVector3(_position.x, _position.y, _position.z));
    _owner->RigidBody->setCenterOfMassTransform(tr);
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


        /**Inventory Box 1*/
        mesh = Mesh::load("mge/HUD/Inventory Box.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Inventory Box.png"));
        GO = new GameObject ("InventoryBox2", glm::vec3(-0.5, 0.02, -0.8));
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.04, 0.05, 0.1));
        _inventoryBox1 = GO;
        _camera->add(GO);/**/
        /**Inventory item 1*/
        if(Inventory::GetInstance()->InventoryList.size() >= 1)
        {
            InventoryObject InvObj = Inventory::GetInstance()->InventoryList.at(0);
            GO = new GameObject ("InventoryItem2", glm::vec3(-0.437, 0.11, -0.7));
            GO->setMesh (InvObj.GO->getMesh());
            GO->setMaterial(InvObj.GO->getMaterial());

            /**
            std::cout << "SIZE x Inventory: "<< InvObj.GO->GOSizeX << std::endl;
            float Scalar = 1;
            if((0.03 / InvObj.GO->GOSizeX) < Scalar) Scalar = 0.03 / InvObj.GO->GOSizeX;
            if((0.03 / InvObj.GO->GOSizeY) < Scalar) Scalar = 0.03 / InvObj.GO->GOSizeY;
            if((0.03 / InvObj.GO->GOSizeZ) < Scalar) Scalar = 0.03 / InvObj.GO->GOSizeZ;
            GO->scale(glm::vec3(Scalar, Scalar, Scalar));
            /**/

            GO->scale(glm::vec3(0.0005, 0.0005, 0.0005));
            _inventoryItem1 = GO;
            _camera->add(GO);
            _inventoryBox1Filled = true;
        }
        /**/

        /**Inventory Box 2*/
        mesh = Mesh::load("mge/HUD/Inventory Box.obj");
        textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Inventory Box.png"));
        GO = new GameObject ("InventoryBox2", glm::vec3(-0.5, 0.02 - 0.2, -0.8));
        GO->setMesh (mesh);
        GO->setMaterial(textureMaterial);
        GO->scale(glm::vec3(0.04, 0.05, 0.1));
        _inventoryBox2 = GO;
        _camera->add(GO);/**/
        /**Inventory item 1*/
        if(Inventory::GetInstance()->InventoryList.size() >= 2)
        {
            InventoryObject InvObj = Inventory::GetInstance()->InventoryList.at(1);
            GO = new GameObject ("InventoryItem2", glm::vec3(-0.437, -0.11, -0.7));
            GO->setMesh (InvObj.GO->getMesh());
            GO->setMaterial(InvObj.GO->getMaterial());

            float Scalar = 1;
            if(0.05 / GO->GOSizeX < Scalar) Scalar = 1 / GO->GOSizeX;
            if(0.05 / GO->GOSizeY < Scalar) Scalar = 1 / GO->GOSizeY;
            if(0.05 / GO->GOSizeZ < Scalar) Scalar = 1 / GO->GOSizeZ;
            GO->scale(glm::vec3(Scalar, Scalar, Scalar));

            //GO->scale(glm::vec3(0.015, 0.015, 0.015));
            _inventoryItem2 = GO;
            _camera->add(GO);
            _inventoryBox2Filled = true;
        }
        /**/

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
        World::GetInstance()->remove(_inventoryBox1);
        if(_inventoryBox1Filled)
        {
            World::GetInstance()->remove(_inventoryItem1);
            _inventoryBox1Filled = false;
        }
        World::GetInstance()->remove(_inventoryBox2);
        if(_inventoryBox2Filled)
        {
            World::GetInstance()->remove(_inventoryItem2);
            _inventoryBox2Filled = false;
        }
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
        GameObject* ObjectHitTest = PhysicsWorld::GetInstance()->ScreenPosToWorldRay(_camera);
        if(ObjectHitTest != NULL && ObjectHitTest->IsInteractive() == true)
        {
            std::cout << "Interactive Gameobject Hit: " << ObjectHitTest->getName() << std::endl;
            bool wasNotInInventory = true;
            for(int i = 0; i < Inventory::GetInstance()->InventoryList.size(); i++)
            {
                InventoryObject obj = Inventory::GetInstance()->InventoryList.at(i);
                if(obj.GO->getName() == ObjectHitTest->getName())
                {
                    std::cout << "Placing Object In World" << std::endl;
                    Inventory::GetInstance()->PlaceObjectInWorld(ObjectHitTest->getName());
                    wasNotInInventory = false;
                    break;
                }
                wasNotInInventory = true;
            }
            if(wasNotInInventory == true)
            {
                if(ObjectHitTest->getName() == "FRED")
                {
                    _fredPickedup = true;
                   LuaLoader::GetInstance()->PushFredToLua();
                   PhysicsWorld::GetInstance()->DynamicsWorld->removeRigidBody(ObjectHitTest->RigidBody);
                   World::GetInstance()->remove(ObjectHitTest);
                }
                else
                {
                std::cout << "Placing Object In Inventory" << std::endl;
                    Inventory::GetInstance()->PlaceObjectInInventory(ObjectHitTest->getName());
                }
            }
            }
        else if(ObjectHitTest != NULL)
        {
            std::cout << "Static Gameobject Hit: " << ObjectHitTest->getName() << std::endl;
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
        UpdateRigidBodyFromPosition();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _position -= _direction * Timer::deltaTime() * _speed;
        UpdateRigidBodyFromPosition();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _position -= right * Timer::deltaTime() * _speed;
        UpdateRigidBodyFromPosition();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _position += right * Timer::deltaTime() * _speed;
        UpdateRigidBodyFromPosition();
    }

}
