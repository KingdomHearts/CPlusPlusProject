#ifndef KEYBOARDBEHAVIOUR_H
#define KEYBOARDBEHAVIOUR_H
#include "mge/core/Mesh.hpp"
#include "mge/behaviours/AbstractBehaviour.hpp"
#include <SFML/Graphics.hpp>

struct BoundMesh
{
    Mesh* mesh;
    bool pickedUp;
};

class KeyboardBehaviour : public AbstractBehaviour
{
    public:
        KeyboardBehaviour();

        static KeyboardBehaviour* GetInstance();
        void BindMeshToButton(int pNumberToBind, Mesh pMesh);

        virtual void update( float step );
    protected:
    private:
        std::vector<BoundMesh> BindArray;
        std::vector<Mesh> InventoryList;
        static KeyboardBehaviour* KeyBoardInstance;
        void PickUpObject();
        void PlaceObject();
};

#endif // KEYBOARDBEHAVIOUR_H
