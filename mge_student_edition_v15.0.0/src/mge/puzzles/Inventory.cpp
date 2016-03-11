#include "Inventory.h"
#include "mge/core/PhysicsWorld.hpp"

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
        PhysicsWorld::GetInstance()->AddColliderToObject(obj.GO->GOSizeX, obj.GO->GOSizeY, obj.GO->GOSizeZ, obj.GO->GORotation, obj.GO->GOPositionToPlace, obj.GO);
        World::GetInstance()->remove(obj.GO);
        return true;
    }
    return false;
}

Inventory::~Inventory()
{
    //ctor
}

