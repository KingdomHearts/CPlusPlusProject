#include "MouseBehaviour.hpp"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "mge/core/Timer.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"



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
    Looking();
    sf::Listener::setPosition(_cameraPosition->getLocalPosition().x,_cameraPosition->getLocalPosition().y,_cameraPosition->getLocalPosition().z);
    sf::Listener::setDirection(-_camera->getWorldPosition().x,0,-_camera->getWorldPosition().z);
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
    glm::vec3 direction(
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

    // Up vector : perpendicular to both direction and right
    glm::vec3 up = glm::cross( right, direction );

    _owner->setTransform(glm::inverse (glm::lookAt(_position, _position+direction, up)));
    _camera->ViewMatrix = glm::lookAt(_position, _position+direction, up);

    /**
     * Keyboard controls
     */

    direction.y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _position += direction * Timer::deltaTime() * _speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _position -= direction * Timer::deltaTime() * _speed;
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
