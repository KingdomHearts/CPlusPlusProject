#include "KeyboardBehaviour.hpp"
#include <cassert>
#include <algorithm>
#include <iostream>

std::list<sf::Keyboard::Key> * KeyboardBehaviour::keysPressed = new std::list<sf::Keyboard::Key>();

KeyboardBehaviour* KeyboardBehaviour::KeyBoardInstance = NULL;
KeyboardBehaviour::KeyboardBehaviour():AbstractBehaviour()
{
	//ctor

}

bool KeyboardBehaviour::GetKey(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}


bool KeyboardBehaviour::GetKeyDown(sf::Keyboard::Key key)
{
	if (sf::Keyboard::isKeyPressed(key) && std::find(keysPressed->begin(), keysPressed->end(), key) == keysPressed->end())
	{
		keysPressed->push_back(key);

		std::cout << "Key Pushed" << std::endl;
		return true;
	}
	else if (!sf::Keyboard::isKeyPressed(key))
	{
		keysPressed->remove(key);
		return false;
	}
	return false;

}

KeyboardBehaviour* KeyboardBehaviour::GetInstance()
{
    if (KeyboardBehaviour::KeyBoardInstance == NULL)
        KeyboardBehaviour::KeyBoardInstance = new KeyboardBehaviour();

    return KeyboardBehaviour::KeyBoardInstance;
}

void KeyboardBehaviour::BindMeshToButton(Mesh* pMesh, AbstractMaterial* pTextureMaterial,glm::mat4 pFinalPosition, GameObject* pGO)
{
    BoundMesh boundMesh;

    boundMesh.IDname = pGO->getName();
    boundMesh.GO = pGO;
    boundMesh.mesh = pMesh;
    boundMesh.PositionToPlace = pFinalPosition;
    boundMesh.pickedUp = false;
    boundMesh.textureMaterial = pTextureMaterial;
    BindArray.push_back(boundMesh);
}


void KeyboardBehaviour::update(float step)
{
    PlaceObject();
    PickUpObject();
}

void KeyboardBehaviour::PickUpObject()
{
    /**/
    if(BindArray.size() > 0 && GetKeyDown(sf::Keyboard::Num0) && BindArray.at(0).pickedUp == false)
    {
        std::cout << "Taking Object" << std::endl;
        GameObject * GO = BindArray.at(0).GO;
        BindArray.at(0).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 1 && GetKeyDown(sf::Keyboard::Num1) && BindArray.at(1).pickedUp == false)
    {
        std::cout << "Taking Object" << std::endl;
        GameObject * GO = BindArray.at(1).GO;
        BindArray.at(1).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 2 && GetKeyDown(sf::Keyboard::Num2) && BindArray.at(2).pickedUp == false)
    {
        GameObject * GO = BindArray.at(2).GO;
        BindArray.at(2).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 3 && GetKeyDown(sf::Keyboard::Num3) && BindArray.at(3).pickedUp == false)
    {
        GameObject * GO = BindArray.at(3).GO;
        BindArray.at(3).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 4 && GetKeyDown(sf::Keyboard::Num4) && BindArray.at(4).pickedUp == false)
    {
        GameObject * GO = BindArray.at(4).GO;
        BindArray.at(4).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 5 && GetKeyDown(sf::Keyboard::Num5) && BindArray.at(5).pickedUp == false)
    {
        GameObject * GO = BindArray.at(5).GO;
        BindArray.at(5).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 6 && GetKeyDown(sf::Keyboard::Num6) && BindArray.at(6).pickedUp == false)
    {
        GameObject * GO = BindArray.at(6).GO;
        BindArray.at(6).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 7 && GetKeyDown(sf::Keyboard::Num7) && BindArray.at(7).pickedUp == false)
    {
        GameObject * GO = BindArray.at(7).GO;
        BindArray.at(7).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 8 && GetKeyDown(sf::Keyboard::Num8) && BindArray.at(8).pickedUp == false)
    {
        GameObject * GO = BindArray.at(8).GO;
        BindArray.at(8).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    else if(BindArray.size() > 9 && GetKeyDown(sf::Keyboard::Num9) && BindArray.at(9).pickedUp == false)
    {
        GameObject * GO = BindArray.at(9).GO;
        BindArray.at(9).pickedUp = true;
        World::GetInstance()->remove(GO);
    }
    /**/
}

void KeyboardBehaviour::PlaceObject()
{
    if(BindArray.size() > 0 && BindArray.at(0).pickedUp == true && GetKeyDown(sf::Keyboard::Num0))
    {
        std::cout << "Placing Object" << std::endl;
        CreateGameObject(BindArray.at(0).mesh, BindArray.at(0).PositionToPlace, BindArray.at(0).IDname, 0, BindArray.at(0).textureMaterial);
        BindArray.at(0).pickedUp = false;
    }
    else if(BindArray.size() > 1 && BindArray.at(1).pickedUp == true && GetKeyDown(sf::Keyboard::Num1))
    {
        std::cout << "Placing Object" << std::endl;
        CreateGameObject(BindArray.at(1).mesh, BindArray.at(1).PositionToPlace, BindArray.at(1).IDname, 1, BindArray.at(1).textureMaterial);
        BindArray.at(1).pickedUp = false;
    }
    else if(BindArray.size() > 2 && BindArray.at(2).pickedUp == true && GetKeyDown(sf::Keyboard::Num2))
    {
        CreateGameObject(BindArray.at(2).mesh, BindArray.at(2).PositionToPlace, BindArray.at(2).IDname, 2, BindArray.at(2).textureMaterial);
        BindArray.at(2).pickedUp = false;
    }
    else if(BindArray.size() > 3 && BindArray.at(3).pickedUp == true && GetKeyDown(sf::Keyboard::Num3))
    {
        CreateGameObject(BindArray.at(3).mesh, BindArray.at(3).PositionToPlace, BindArray.at(3).IDname, 3, BindArray.at(3).textureMaterial);
        BindArray.at(3).pickedUp = false;
    }
    else if(BindArray.size() > 4 && BindArray.at(4).pickedUp == true && GetKeyDown(sf::Keyboard::Num4))
    {
        CreateGameObject(BindArray.at(4).mesh, BindArray.at(4).PositionToPlace, BindArray.at(4).IDname, 4, BindArray.at(4).textureMaterial);
        BindArray.at(4).pickedUp = false;
    }
    else if(BindArray.size() > 5 && BindArray.at(5).pickedUp == true && GetKeyDown(sf::Keyboard::Num5))
    {
        CreateGameObject(BindArray.at(5).mesh, BindArray.at(5).PositionToPlace, BindArray.at(5).IDname, 5, BindArray.at(5).textureMaterial);
        BindArray.at(5).pickedUp = false;
    }
    else if(BindArray.size() > 6 && BindArray.at(6).pickedUp == true && GetKeyDown(sf::Keyboard::Num6))
    {
        CreateGameObject(BindArray.at(6).mesh, BindArray.at(6).PositionToPlace, BindArray.at(6).IDname, 6, BindArray.at(6).textureMaterial);
        BindArray.at(6).pickedUp = false;
    }
    else if(BindArray.size() > 7 && BindArray.at(7).pickedUp == true && GetKeyDown(sf::Keyboard::Num7))
    {
        CreateGameObject(BindArray.at(7).mesh, BindArray.at(7).PositionToPlace, BindArray.at(7).IDname, 7, BindArray.at(7).textureMaterial);
        BindArray.at(7).pickedUp = false;
    }
    else if(BindArray.size() > 8 && BindArray.at(8).pickedUp == true && GetKeyDown(sf::Keyboard::Num8))
    {
        CreateGameObject(BindArray.at(8).mesh, BindArray.at(8).PositionToPlace, BindArray.at(8).IDname, 8, BindArray.at(8).textureMaterial);
        BindArray.at(8).pickedUp = false;
    }
    else if(BindArray.size() > 9 && BindArray.at(9).pickedUp == true && GetKeyDown(sf::Keyboard::Num9))
    {
        CreateGameObject(BindArray.at(9).mesh, BindArray.at(9).PositionToPlace, BindArray.at(9).IDname, 9, BindArray.at(9).textureMaterial);
        BindArray.at(9).pickedUp = false;
    }
}

void KeyboardBehaviour::CreateGameObject(Mesh* pMesh, glm::mat4 pFinalPosition, std::string pIDname, int pIndex, AbstractMaterial* pTextureMaterial)
{
    GameObject* Go = new GameObject (pIDname, glm::vec3(0,0,0));
    Go->setMesh (pMesh);
    Go->setMaterial(pTextureMaterial);
    World::GetInstance()->add(Go);
    Go->setTransform(pFinalPosition);
    BindArray.at(pIndex).GO = Go;
}
