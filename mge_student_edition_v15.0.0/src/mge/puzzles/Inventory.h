#ifndef INVENTORY_H
#define INVENTORY_H

#include "mge/core/GameObject.hpp"
#include "mge/core/AbstractGame.hpp"
#include <vector>
#include "mge/core/World.hpp"

/**/
struct InventoryObject
{
    GameObject* GO;
    glm::mat4 pPositionToPlace;
};
/**/

class Inventory
{
    public:
        Inventory();
        static Inventory* GetInstance();
        std::vector<InventoryObject> InventoryList;
        bool PlaceObjectInInventory(std::string pName);
        bool PlaceObjectInWorld(std::string pName);
        virtual ~Inventory();
    protected:
    private:
        static Inventory* InventoryInstance;
};

#endif // INVENTORY_H
