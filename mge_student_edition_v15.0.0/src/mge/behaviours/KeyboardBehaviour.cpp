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

void KeyboardBehaviour::BindMeshToButton(int pNumberToBind)
{
    switch(pNumberToBind)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
            break;
        case 0:
            break;
    }
}
