#include "MouseBehaviour.hpp"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "mge/core/Timer.hpp"

// position
    glm::vec3 position = glm::vec3( 0, 3, -3 );
    // horizontal angle : toward -Z
    float horizontalAngle = 3.14f;
    // vertical angle : 0, look at the horizon
    float verticalAngle = 0.0f;
    // Initial Field of View
    float initialFoV = 0.0f;

    float speed = 5.0f; // 3 units / second
    float mouseSpeed = 0.05f;
    bool startup = true;
    sf::Vector2i mousePos;

MouseBehaviour::MouseBehaviour(GameObject* pCameraPosition,Camera* pCamera, float pDistance):AbstractBehaviour()
{
    _cameraPosition = pCameraPosition;
    _emptyChild = new GameObject("EmptyChild");
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
    if(_owner->getParent() != _cameraPosition){
        _owner->setParent(_cameraPosition);
    }
    if(_emptyChild->getParent() != _cameraPosition){
        _emptyChild->setParent(_cameraPosition);
    }

    /**
     * Mouse controls
     */
    /**
    if(sf::Mouse::getPosition().x <= sf::VideoMode::getDesktopMode().width / 2 - 1)
    {
        _emptyChild->getParent()->rotate(0.04f,glm::vec3(0,1.0f,0));
    }
    else if (sf::Mouse::getPosition().x > sf::VideoMode::getDesktopMode().width / 2 + 1)
    {
        _emptyChild->getParent()->rotate(0.04f,glm::vec3(0,-1.0f,0));
    }
    if(sf::Mouse::getPosition().y <= sf::VideoMode::getDesktopMode().height / 2 - 1)
    {
        _owner->rotate(0.05f,glm::vec3(1.0f,0,0));
    }
    else if (sf::Mouse::getPosition().y > sf::VideoMode::getDesktopMode().height / 2 + 1)
    {
        _owner->rotate(0.05f,glm::vec3(-1.0f,0,0));
    }
    /**/

    // Screen sizes
    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;

    if(!startup)
    {
        mousePos = sf::Mouse::getPosition();
        //sf::Mouse::setPosition(sf::Vector2i(width / 2, height / 2));
    }
    else
    {
        startup = false;
        mousePos = sf::Vector2i(width / 2, height / 2);
        //sf::Mouse::setPosition(sf::Vector2i(width / 2, height / 2));
    }
    sf::Mouse::setPosition(sf::Vector2i(width / 2, height / 2));
    //sf::Mouse::setPosition(width / 2, height / 2);

    // Compute new orientation
    horizontalAngle += mouseSpeed * Timer::deltaTime() * float(width /2 - mousePos.x );
    std::cout << horizontalAngle << std::endl;
    verticalAngle   += mouseSpeed * Timer::deltaTime() * float(height/2 - mousePos.y );



    // Direction : Spherical coordinates to Cartesian coordinates conversion
    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );

    // Right vector
    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - 3.14f/2.0f),
        0,
        cos(horizontalAngle - 3.14f/2.0f)
    );

    // Up vector : perpendicular to both direction and right
    glm::vec3 up = glm::cross( right, direction );

    _owner->setTransform(glm::inverse (glm::lookAt(position, position+direction, up)));
    _camera->ViewMatrix = glm::lookAt(position, position+direction, up);

    /**
     * Keyboard controls
     */
     /**
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _cameraPosition->translate(glm::vec3(0,0,-0.1f));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _cameraPosition->translate(glm::vec3(0,0,0.1f));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _cameraPosition->translate(glm::vec3(-0.1f,0,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _cameraPosition->translate(glm::vec3(0.1f,0,0));
    }
    /**/

    direction.y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position += direction * Timer::deltaTime() * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position -= direction * Timer::deltaTime() * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position -= right * Timer::deltaTime() * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position += right * Timer::deltaTime() * speed;
    }

/**
    // Move forward
 2 if (glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS){
 3     position += direction * deltaTime * speed;
 4 }
 5 // Move backward
 6 if (glfwGetKey( GLFW_KEY_DOWN ) == GLFW_PRESS){
 7     position -= direction * deltaTime * speed;
 8 }
 9 // Strafe right
10 if (glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
11     position += right * deltaTime * speed;
12 }
13 // Strafe left
14 if (glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
15     position -= right * deltaTime * speed;
16 }
/**/


}
