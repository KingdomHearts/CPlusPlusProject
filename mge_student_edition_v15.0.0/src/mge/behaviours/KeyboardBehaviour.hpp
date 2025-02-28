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
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <list>

struct BoundMesh
{
    GameObject* GO;
    std::string IDname;
    Mesh* mesh;
    bool pickedUp;
    glm::mat4 PositionToPlace;
    AbstractMaterial* textureMaterial;
};

class KeyboardBehaviour : public AbstractBehaviour
{
    public:
        static KeyboardBehaviour* GetInstance();
        void BindMeshToButton(Mesh* pMesh,AbstractMaterial* pTextureMaterial ,glm::mat4 pFinalPosition, GameObject* pGO);
        virtual void update( float step );

        static bool GetKey(sf::Keyboard::Key);
		static bool GetKeyDown(sf::Keyboard::Key);
		static bool GetLeftMouseDown();
    protected:
    private:
        KeyboardBehaviour();
        std::vector<BoundMesh> BindArray;
        static KeyboardBehaviour* KeyBoardInstance;
        static bool LeftMousePressed;
        void PickUpObject();
        void PlaceObject();
        void CreateGameObject(Mesh* pMesh,glm::mat4 pFinalPosition, std::string pIDname, int pIndex, AbstractMaterial* pTextureMaterial);

        static std::list<sf::Keyboard::Key> * keysPressed;
};

#endif // KEYBOARDBEHAVIOUR_H
