#include "Rebuild.h"
#include "mge/core/GameObject.hpp"
#include <vector>
#include "mge/PlayerProgress.h"

//Rebuild statue en paintings

bool isInList;

Rebuild::Rebuild()
{
    //ctor
}

void Rebuild::AddPuzzle(std::string pPuzzleName, glm::vec3 pStartPosition, glm::vec3 pEndPosition, GameObject pGameObject)
{
    isInList = false;
    if( _puzzleNameList.size()==0)
    {
        PuzzleName * sPuzzleNameList = new PuzzleName();
        sPuzzleNameList->sPuzzleName = pPuzzleName;
        _puzzleNameList.push_back(*sPuzzleNameList);
    }
    for(int i = 0; i< _puzzleNameList.size();i++)
    {
        if (_puzzleNameList[i].sPuzzleName == pPuzzleName)
        {
            isInList = true;
            Puzzle * sPuzzle = new Puzzle();
            sPuzzle->sGameObjectID = pGameObject.getName();
            sPuzzle->sStartPosition = pStartPosition;
            sPuzzle->sEndPosition = pEndPosition;
            _puzzleNameList[i].sPuzzleList.push_back(*sPuzzle);
        }
    }
    if(isInList == false)
    {
        PuzzleName * sPuzzleNameList = new PuzzleName();
        sPuzzleNameList->sPuzzleName = pPuzzleName;
        _puzzleNameList.push_back(*sPuzzleNameList);

        Puzzle * sPuzzle = new Puzzle();
        sPuzzle->sGameObjectID = pGameObject.getName();
        sPuzzle->sStartPosition = pStartPosition;
        sPuzzle->sEndPosition = pEndPosition;
        _puzzleNameList.back().sPuzzleList.push_back(*sPuzzle);
    }

}

void Rebuild::UpdatePuzzle(std::string pPuzzleName, glm::vec3 pCurrenPosition, GameObject pGameObject)
{
    for(int i = 0; i < _puzzleNameList.size();i++)
    {
        if(_puzzleNameList[i].sPuzzleName == pPuzzleName)
        {
            for(int j =0; j < _puzzleNameList[i].sPuzzleList.size();j++)
            {
                if(_puzzleNameList[i].sPuzzleList[j].sGameObjectID == pGameObject.getName())
                {
                    _puzzleNameList[i].sPuzzleList[j].sStartPosition = pCurrenPosition;

                    if(_puzzleNameList[i].sPuzzleList[j].sStartPosition == _puzzleNameList[i].sPuzzleList[j].sEndPosition)
                    {
                        _puzzleNameList[i].sComplete = true;
                        Rebuild::SavePuzzle(pPuzzleName);
                    }
                }
            }
        }
    }
}

void Rebuild::SavePuzzle(std::string pPuzzleName)
{
    for(int i = 0; i < _puzzleNameList.size();i++)
    {
        if(_puzzleNameList[i].sPuzzleName == pPuzzleName)
        {
            if(_puzzleNameList[i].sComplete)
            {
                PlayerProgress::GetInstance()->SavePuzzle = _puzzleNameList;
            }
            else
            {
                PlayerProgress::GetInstance()->SavePuzzle = _puzzleNameList;
            }
        }
    }
}

Rebuild::~Rebuild()
{
    //dtor
}
