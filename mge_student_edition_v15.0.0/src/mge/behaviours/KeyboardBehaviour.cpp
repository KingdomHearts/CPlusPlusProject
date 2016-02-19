#include "KeyboardBehaviour.hpp"
#include <cassert>
#include <algorithm>
#include <iostream>

KeyboardBehaviour* KeyboardBehaviour::KeyBoardInstance = NULL;

KeyboardBehaviour::KeyboardBehaviour()
{
	//ctor
	KeyboardBehaviour::KeyBoardInstance = this;
}

KeyboardBehaviour* KeyboardBehaviour::GetInstance()
{
    return KeyboardBehaviour::KeyBoardInstance;
}

void KeyboardBehaviour::BindMeshToButton(int pNumberToBind, Mesh pMesh)
{
    switch(pNumberToBind)
    {
        case 1:
            BindArray.at(1) = &pMesh;
            break;
        case 2:
            BindArray.at(2) = &pMesh;
            break;
        case 3:
            BindArray.at(3) = &pMesh;
            break;
        case 4:
            BindArray.at(4) = &pMesh;
            break;
        case 5:
            BindArray.at(5) = &pMesh;
            break;
        case 6:
            BindArray.at(6) = &pMesh;
            break;
        case 7:
            BindArray.at(7) = &pMesh;
            break;
        case 8:
            BindArray.at(8) = &pMesh;
            break;
        case 9:
            BindArray.at(9) = &pMesh;
            break;
        case 0:
            BindArray.at(0) = &pMesh;
            break;
    }
}
