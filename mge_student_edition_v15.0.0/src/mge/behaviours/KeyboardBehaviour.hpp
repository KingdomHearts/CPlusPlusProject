#ifndef KEYBOARDBEHAVIOUR_H
#define KEYBOARDBEHAVIOUR_H
#include "mge/core/Mesh.hpp"
#include "mge/behaviours/AbstractBehaviour.hpp"
#include <SFML/Graphics.hpp>
#include <mge/core/World.hpp>
#include <mge/materials/AbstractMaterial.hpp>
#include <mge/materials/TextureMaterial.hpp>
#include <vector>
#include <iostream>

struct BoundMesh
{
    GameObject* GO;
    std::string IDname;
    Mesh* mesh;
    bool pickedUp;
    glm::vec3 PositionToPlace;
};

class KeyboardBehaviour : public AbstractBehaviour
{
    public:
        static KeyboardBehaviour* GetInstance();
        void BindMeshToButton(int pNumberToBind, Mesh* pMesh, glm::vec3 pPositionToPlace, GameObject* pGO);
        virtual void update( float step );
    protected:
    private:
        KeyboardBehaviour();
        std::vector<BoundMesh> BindArray;
        static KeyboardBehaviour* KeyBoardInstance;
        void PickUpObject();
        void PlaceObject();
        void CreateGameObject(Mesh* pMesh, glm::vec3 pPosition, std::string pIDname);
};

#endif // KEYBOARDBEHAVIOUR_H
