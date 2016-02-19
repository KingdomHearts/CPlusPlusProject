#ifndef KEYBOARDBEHAVIOUR_H
#define KEYBOARDBEHAVIOUR_H
#include "mge/core/Mesh.hpp"

class KeyboardBehaviour
{
    public:
        KeyboardBehaviour();

        static KeyboardBehaviour* GetInstance();
        void BindMeshToButton(int pNumberToBind, Mesh pMesh);
    protected:
    private:
        std::vector<Mesh*> BindArray;
        static KeyboardBehaviour* KeyBoardInstance;
};

#endif // KEYBOARDBEHAVIOUR_H
