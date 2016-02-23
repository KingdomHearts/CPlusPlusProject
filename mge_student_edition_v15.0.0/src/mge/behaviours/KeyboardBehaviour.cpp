#include "KeyboardBehaviour.hpp"
#include <cassert>
#include <algorithm>
#include <iostream>

KeyboardBehaviour* KeyboardBehaviour::KeyBoardInstance = NULL;
KeyboardBehaviour::KeyboardBehaviour():AbstractBehaviour()
{

	//ctor
	KeyboardBehaviour::KeyBoardInstance = this;
}

KeyboardBehaviour* KeyboardBehaviour::GetInstance()
{
    return KeyboardBehaviour::KeyBoardInstance;
}

void KeyboardBehaviour::BindMeshToButton(int pNumberToBind, Mesh* pMesh, glm::vec3 pPositionToPlace, GameObject* pGO)
{
    BoundMesh* boundMesh;
    switch(pNumberToBind)
    {
        case 1:
            boundMesh = new BoundMesh();
            std::cout << "Case 1" << std::endl;
            boundMesh->GO = pGO;
            std::cout << pGO->getName() << std::endl;
            boundMesh->mesh = pMesh;
            std::cout << boundMesh->mesh << std::endl;
            boundMesh->IDname = pGO->getName();
            std::cout << boundMesh->IDname << std::endl;
            boundMesh->pickedUp = false;
            std::cout << boundMesh->pickedUp << std::endl;
            boundMesh->PositionToPlace = pPositionToPlace;
            std::cout << boundMesh->PositionToPlace << std::endl;
            std::cout << "Before List 1" << std::endl;
            BindArray.push_back(boundMesh);
            std::cout << "End Case 1" << std::endl;
            break;
        case 2:
            boundMesh = new BoundMesh();
            std::cout << "Case 2" << std::endl;
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 3:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 4:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 5:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 6:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 7:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 8:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 9:
            boundMesh = new BoundMesh();
            boundMesh->GO = pGO;
            boundMesh->mesh = pMesh;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
        case 0:
            boundMesh = new BoundMesh();
            boundMesh->mesh = pMesh;
            boundMesh->GO = pGO;
            boundMesh->IDname = pGO->getName();
            boundMesh->pickedUp = false;
            boundMesh->PositionToPlace = pPositionToPlace;
            BindArray.push_back(boundMesh);
            break;
    }
    std::cout << "Case Ended" << std::endl;
}


void KeyboardBehaviour::update(float step)
{
    PickUpObject();
    PlaceObject();
}

void KeyboardBehaviour::PickUpObject()
{
    /**/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && BindArray.at(0)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(0)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(0)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(0)->PositionToPlace;
        InventoryList.at(0) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && BindArray.at(1)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(1)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(1)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(1)->PositionToPlace;
        InventoryList.at(1) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && BindArray.at(2)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(2)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(2)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(2)->PositionToPlace;
        InventoryList.at(2) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && BindArray.at(3)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(3)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(3)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(3)->PositionToPlace;
        InventoryList.at(3) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && BindArray.at(4)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(4)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(4)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(4)->PositionToPlace;
        InventoryList.at(4) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && BindArray.at(5)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(5)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(5)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(5)->PositionToPlace;
        InventoryList.at(5) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && BindArray.at(6)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(6)->GO;
        BoundMesh* inventoryMesh = new BoundMesh();
        inventoryMesh->mesh = BindArray.at(6)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(6)->PositionToPlace;
        InventoryList.at(6) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && BindArray.at(7)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(7)->GO;
        BoundMesh* inventoryMesh = new BoundMesh;
        inventoryMesh->mesh = BindArray.at(7)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(7)->PositionToPlace;
        InventoryList.at(7) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && BindArray.at(8)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(8)->GO;
        BoundMesh* inventoryMesh = new BoundMesh;
        inventoryMesh->mesh = BindArray.at(8)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(8)->PositionToPlace;
        InventoryList.at(8) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && BindArray.at(9)->pickedUp == false)
    {
        GameObject * GO = BindArray.at(8)->GO;
        BoundMesh* inventoryMesh = new BoundMesh;
        inventoryMesh->mesh = BindArray.at(9)->mesh;
        inventoryMesh->pickedUp = true;
        inventoryMesh->IDname = GO->getName();
        inventoryMesh->PositionToPlace = BindArray.at(9)->PositionToPlace;
        InventoryList.at(9) = inventoryMesh;
        World::GetInstance()->remove(GO);
        delete GO;
    }
    /**/
}

void KeyboardBehaviour::PlaceObject()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && InventoryList.at(0)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(0)->mesh, InventoryList.at(0)->PositionToPlace, InventoryList.at(0)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && InventoryList.at(1)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(1)->mesh, InventoryList.at(1)->PositionToPlace, InventoryList.at(1)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && InventoryList.at(2)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(2)->mesh, InventoryList.at(2)->PositionToPlace, InventoryList.at(2)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && InventoryList.at(3)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(3)->mesh, InventoryList.at(3)->PositionToPlace, InventoryList.at(3)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && InventoryList.at(4)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(4)->mesh, InventoryList.at(4)->PositionToPlace, InventoryList.at(4)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && InventoryList.at(5)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(5)->mesh, InventoryList.at(5)->PositionToPlace, InventoryList.at(5)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && InventoryList.at(6)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(6)->mesh, InventoryList.at(6)->PositionToPlace, InventoryList.at(6)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && InventoryList.at(7)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(7)->mesh, InventoryList.at(7)->PositionToPlace, InventoryList.at(7)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && InventoryList.at(8)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(8)->mesh, InventoryList.at(8)->PositionToPlace, InventoryList.at(8)->IDname);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && InventoryList.at(9)->pickedUp == true)
    {
        CreateGameObject(InventoryList.at(9)->mesh, InventoryList.at(9)->PositionToPlace, InventoryList.at(9)->IDname);
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
