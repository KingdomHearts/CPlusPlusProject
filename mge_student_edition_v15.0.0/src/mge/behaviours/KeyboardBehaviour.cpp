#include "KeyboardBehaviour.hpp"
#include <cassert>
#include <algorithm>
#include <iostream>

KeyboardBehaviour* KeyboardBehaviour::KeyBoardInstance = NULL;
KeyboardBehaviour::KeyboardBehaviour():AbstractBehaviour()
{
	//ctor

}

KeyboardBehaviour* KeyboardBehaviour::GetInstance()
{
    if (KeyboardBehaviour::KeyBoardInstance == NULL)
        KeyboardBehaviour::KeyBoardInstance = new KeyboardBehaviour();

    return KeyboardBehaviour::KeyBoardInstance;
}

void KeyboardBehaviour::BindMeshToButton(int pNumberToBind, Mesh* pMesh, glm::vec3 pPositionToPlace, GameObject* pGO)
{
    BoundMesh boundMesh;

    std::cout << "Case 1" << std::endl;
    boundMesh.IDname = pGO->getName();
    boundMesh.GO = pGO;
    boundMesh.mesh = pMesh;
    boundMesh.PositionToPlace = pPositionToPlace;
    boundMesh.pickedUp = false;
    std::cout << "Before List 1" << std::endl;
    BindArray = std::vector<BoundMesh>();
    std::cout << BindArray.size() << std::endl;
    BindArray.push_back(boundMesh);
    std::cout << "After List 1" << std::endl;
}


void KeyboardBehaviour::update(float step)
{
    PickUpObject();
    PlaceObject();
}

void KeyboardBehaviour::PickUpObject()
{
    /**/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && BindArray.at(0).pickedUp == false)
    {
        GameObject * GO = BindArray.at(0).GO;
        BindArray.at(0).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && BindArray.at(1).pickedUp == false)
    {
        GameObject * GO = BindArray.at(1).GO;
        BindArray.at(1).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && BindArray.at(2).pickedUp == false)
    {
        GameObject * GO = BindArray.at(2).GO;
        BindArray.at(2).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && BindArray.at(3).pickedUp == false)
    {
        GameObject * GO = BindArray.at(3).GO;
        BindArray.at(3).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && BindArray.at(4).pickedUp == false)
    {
        GameObject * GO = BindArray.at(4).GO;
        BindArray.at(4).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && BindArray.at(5).pickedUp == false)
    {
        GameObject * GO = BindArray.at(5).GO;
        BindArray.at(5).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && BindArray.at(6).pickedUp == false)
    {
        GameObject * GO = BindArray.at(6).GO;
        BindArray.at(6).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && BindArray.at(7).pickedUp == false)
    {
        GameObject * GO = BindArray.at(7).GO;
        BindArray.at(7).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && BindArray.at(8).pickedUp == false)
    {
        GameObject * GO = BindArray.at(8).GO;
        BindArray.at(8).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && BindArray.at(9).pickedUp == false)
    {
        GameObject * GO = BindArray.at(9).GO;
        BindArray.at(9).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    /**/
}

void KeyboardBehaviour::PlaceObject()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && BindArray.at(0).pickedUp == true)
    {
        CreateGameObject(BindArray.at(0).mesh, BindArray.at(0).PositionToPlace, BindArray.at(0).IDname);
        BindArray.at(0).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && BindArray.at(1).pickedUp == true)
    {
        CreateGameObject(BindArray.at(1).mesh, BindArray.at(1).PositionToPlace, BindArray.at(1).IDname);
        BindArray.at(1).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && BindArray.at(2).pickedUp == true)
    {
        CreateGameObject(BindArray.at(2).mesh, BindArray.at(2).PositionToPlace, BindArray.at(2).IDname);
        BindArray.at(2).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && BindArray.at(3).pickedUp == true)
    {
        CreateGameObject(BindArray.at(3).mesh, BindArray.at(3).PositionToPlace, BindArray.at(3).IDname);
        BindArray.at(3).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && BindArray.at(4).pickedUp == true)
    {
        CreateGameObject(BindArray.at(4).mesh, BindArray.at(4).PositionToPlace, BindArray.at(4).IDname);
        BindArray.at(4).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && BindArray.at(5).pickedUp == true)
    {
        CreateGameObject(BindArray.at(5).mesh, BindArray.at(5).PositionToPlace, BindArray.at(5).IDname);
        BindArray.at(5).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && BindArray.at(6).pickedUp == true)
    {
        CreateGameObject(BindArray.at(6).mesh, BindArray.at(6).PositionToPlace, BindArray.at(6).IDname);
        BindArray.at(6).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && BindArray.at(7).pickedUp == true)
    {
        CreateGameObject(BindArray.at(7).mesh, BindArray.at(7).PositionToPlace, BindArray.at(7).IDname);
        BindArray.at(7).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && BindArray.at(8).pickedUp == true)
    {
        CreateGameObject(BindArray.at(8).mesh, BindArray.at(8).PositionToPlace, BindArray.at(8).IDname);
        BindArray.at(8).pickedUp = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && BindArray.at(9).pickedUp == true)
    {
        CreateGameObject(BindArray.at(9).mesh, BindArray.at(9).PositionToPlace, BindArray.at(9).IDname);
        BindArray.at(9).pickedUp = false;
    }
}

void KeyboardBehaviour::CreateGameObject(Mesh* pMesh, glm::vec3 pPosition, std::string pIDname)
{
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/bricks.jpg"));
    GameObject* GO = new GameObject (pIDname, glm::vec3(0,0,0));
    GO->setMesh (pMesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);

    GO->setLocalPosition(pPosition);
}
