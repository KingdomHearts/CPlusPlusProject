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

void KeyboardBehaviour::update(float step)
{
    PickUpObject();
    PlaceObject();
}

void KeyboardBehaviour::PickUpObject()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && BindArray.at(0).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(0).mesh;
        InventoryList.at(0) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && BindArray.at(1).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(1).mesh;
        InventoryList.at(1) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && BindArray.at(2).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(2).mesh;
        InventoryList.at(2) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && BindArray.at(3).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(3).mesh;
        InventoryList.at(3) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && BindArray.at(4).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(4).mesh;
        InventoryList.at(4) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && BindArray.at(5).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(5).mesh;
        InventoryList.at(5) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && BindArray.at(6).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(6).mesh;
        InventoryList.at(6) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && BindArray.at(7).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(7).mesh;
        InventoryList.at(7) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && BindArray.at(8).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(8).mesh;
        InventoryList.at(8) = *mesh;
        delete mesh;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && BindArray.at(9).pickedUp == false)
    {
        Mesh * mesh = BindArray.at(9).mesh;
        InventoryList.at(9) = *mesh;
        delete mesh;
    }
}

void KeyboardBehaviour::PlaceObject()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && BindArray.at(0).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && BindArray.at(1).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && BindArray.at(2).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && BindArray.at(3).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && BindArray.at(4).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && BindArray.at(5).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && BindArray.at(6).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && BindArray.at(7).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && BindArray.at(8).pickedUp == true)
    {

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && BindArray.at(9).pickedUp == true)
    {

    }
}

void KeyboardBehaviour::BindMeshToButton(int pNumberToBind, Mesh pMesh)
{
    BoundMesh boundMesh;
    switch(pNumberToBind)
    {
        case 1:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(1) = boundMesh;
            break;
        case 2:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(2) = boundMesh;
            break;
        case 3:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(3) = boundMesh;
            break;
        case 4:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(4) = boundMesh;
            break;
        case 5:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(5) = boundMesh;
            break;
        case 6:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(6) = boundMesh;
            break;
        case 7:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(7) = boundMesh;
            break;
        case 8:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(8) = boundMesh;
            break;
        case 9:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(9) = boundMesh;
            break;
        case 0:
            boundMesh.mesh = &pMesh;
            boundMesh.pickedUp = true;
            BindArray.at(0) = boundMesh;
            break;
    }
}
