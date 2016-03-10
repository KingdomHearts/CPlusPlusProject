#include "Inventory.h"

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
        World::GetInstance()->remove(obj.GO);
        return true;
    }
    return false;
}

Inventory::~Inventory()
{
    //ctor
}

