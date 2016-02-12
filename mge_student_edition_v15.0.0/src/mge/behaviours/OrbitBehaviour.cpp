#include "OrbitBehaviour.hpp"
#include <SFML/Graphics.hpp>

OrbitBehaviour::OrbitBehaviour(GameObject* pCameraPosition, float pDistance):AbstractBehaviour()
{
    _cameraPosition = pCameraPosition;
    _emptyChild = new GameObject("EmptyChild");
    //ctor
}

OrbitBehaviour::~OrbitBehaviour()
{
    //dtor
}

void OrbitBehaviour::update(float step)
{

    //std::cout << sf::Mouse::getPosition().x << std::endl;
    if(_owner->getParent() != _cameraPosition){
        _owner->setParent(_cameraPosition);
    }
    if(_emptyChild->getParent() != _cameraPosition){
        _emptyChild->setParent(_cameraPosition);
    }
    /**/
    if(sf::Mouse::getPosition().x <= 930)
    {
        //_owner->translate(glm::vec3(-0.05f,0,0));

        //glm::vec3 forward = glm::normalize(_owner->getLocalPosition() - _target->getLocalPosition());
        //glm::vec3 right = glm::cross (glm::vec3(0,1,0), forward);
        //glm::vec3 up = glm::cross (forward, right);

       // _owner->setTransform(
       //   glm::mat4 (glm::vec4(right,0), glm::vec4(up,0), glm::vec4(forward,0), glm::vec4(_owner->getLocalPosition(),1) )
        //);
        //_owner->rotate(0,01f,glm::vec3(-0.05f,0,0));

        //_owner->rotate(0.01f,glm::vec3(0,0.05f,0));
        _emptyChild->getParent()->rotate(0.01f,glm::vec3(0,0.05f,0));
    }
    else if (sf::Mouse::getPosition().x > 990)
    {
        //_owner->translate(glm::vec3(0.05f,0,0));


        //_owner->rotate(0.01f,glm::vec3(0,-0.05f,0));

        _emptyChild->getParent()->rotate(0.01f,glm::vec3(0,-0.05f,0));
    }
    if(sf::Mouse::getPosition().y <= 510)
    {
        //_owner->translate(glm::vec3(0,-0.05f,0));

        _owner->rotate(0.01f,glm::vec3(0.05f,0,0));
        //_owner->rotate(0.01f,glm::vec3(0.05f,0,0));
    }
    else if (sf::Mouse::getPosition().y > 570)
    {
        //_owner->translate(glm::vec3(0,0.05f,0));

        _owner->rotate(0.01f,glm::vec3(-0.05f,0,0));
        //_owner->rotate(0.01f,glm::vec3(-0.05f,0,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //_owner->translate(glm::vec3(0,0,-0.1f));
        _cameraPosition->translate(glm::vec3(0,0,-0.1f));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _cameraPosition->translate(glm::vec3(0,0,0.1f));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //_owner->translate(glm::vec3(0,0,-0.1f));
        _cameraPosition->translate(glm::vec3(-0.1f,0,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _cameraPosition->translate(glm::vec3(0.1f,0,0));
    }

    //test




    //glm::vec3 distance = _target->getWorldPosition() - _owner->getWorldPosition();
    //float length = sqrtf(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);


}
