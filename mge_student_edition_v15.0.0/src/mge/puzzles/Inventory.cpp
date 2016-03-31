#define NULL __null
#include "Inventory.h"
#include "mge/core/PhysicsWorld.hpp"
#include "mge/puzzles/Rebuild.h"

Inventory* Inventory::InventoryInstance = NULL;

Inventory* Inventory::GetInstance()
{
    if(Inventory::InventoryInstance == NULL){
        Inventory::InventoryInstance = new Inventory();
    }
    return Inventory::InventoryInstance;
}

Inventory::Inventory()
{
    //ctor
}

bool Inventory::PlaceObjectInInventory(std::string pName)
{
    GameObject* gameObject;
    for (int i = 0; i < World::GetInstance()->getChildCount(); i++) {
        gameObject = World::GetInstance()->getChildAt(i);

        if (gameObject->getName() == pName)
        {
            break;
        }
        else
        {
            gameObject = NULL;
        }
    }
    if(gameObject != NULL)
    {
        InventoryObject obj;
        obj.GO = gameObject;
        obj.pPositionToPlace = gameObject->TransformToPlace;
        InventoryList.push_back(obj);
        //Place the Collider in the Next Position
        PhysicsWorld::GetInstance()->DynamicsWorld->removeRigidBody(obj.GO->RigidBody);
        PhysicsWorld::GetInstance()->AddColliderToObject(obj.GO->GOSizeX, obj.GO->GOSizeY, obj.GO->GOSizeZ, obj.GO->GORotation, obj.GO->GOPositionToPlace, 0, obj.GO);
        World::GetInstance()->remove(obj.GO);
        return true;
    }
    return false;
}

bool Inventory::PlaceObjectInWorld(std::string pName)
{
    bool foundObject;
    int index;
    InventoryObject invObject;
    for (int i = 0; i < Inventory::GetInstance()->InventoryList.size(); i++) {
        invObject = Inventory::GetInstance()->InventoryList.at(i);
        index = i;
        if (invObject.GO->getName() == pName)
        {
            foundObject = true;
            break;
        }
        else
        {
            foundObject = false;
        }
    }
    if(foundObject == true)
    {
        World::GetInstance()->remove(invObject.GO);
        World::GetInstance()->add(invObject.GO);
        invObject.GO->setTransform(invObject.pPositionToPlace);
        //Rebuild::GetInstance()->UpdatePuzzle(invObject.GO->puzzleNameString,invObject.GO->getLocalPosition(),invObject.GO);
        //Audio * audio = new Audio("",0);
        //audio->PlaySound("Plop.wav");
        InventoryList.erase(InventoryList.begin()+index);

    }
    return false;
}

Inventory::~Inventory()
{
    //ctor
}

