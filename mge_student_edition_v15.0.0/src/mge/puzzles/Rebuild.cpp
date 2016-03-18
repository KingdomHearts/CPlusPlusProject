#include "Rebuild.h"
#include "mge/core/GameObject.hpp"
#include <vector>
#include "mge/PlayerProgress.h"
#include "mge/util/LuaLoader.hpp"

//Rebuild statue en paintings

bool isInList;
Rebuild* Rebuild::RebuildInstance = NULL;

Rebuild* Rebuild::GetInstance()
{
    if(Rebuild::RebuildInstance == NULL){
        Rebuild::RebuildInstance = new Rebuild();
    }
    return Rebuild::RebuildInstance;
}
Rebuild::Rebuild()
{
    //ctor
}

void Rebuild::AddPuzzle(std::string pPuzzleName, glm::vec3 pStartPosition, glm::vec3 pEndPosition, GameObject* pGameObject)
{
    std::string nestedString = pPuzzleName;
    std::string splitter = "_";
    size_t pos = 0;
    std::string token;
    std::vector<std::string> PuzzleNameString;
    std::vector<int> dialogNumbers;
    while ((pos = nestedString.find(splitter)) != std::string::npos)
    {
    token = nestedString.substr(0, pos);
    nestedString.erase(0, pos + splitter.length());
    PuzzleNameString.push_back(token);
    }
    if(PuzzleNameString.size() == 0)
    {
        PuzzleNameString.push_back(pPuzzleName);
    }
    isInList = false;
    if( _puzzleNameList.size()==0)
    {
        PuzzleName * sPuzzleNameList = new PuzzleName();
        sPuzzleNameList->sPuzzleName = PuzzleNameString[0];
        _puzzleNameList.push_back(*sPuzzleNameList);
    }
    for(int i = 0; i< _puzzleNameList.size();i++)
    {
        if (_puzzleNameList[i].sPuzzleName == PuzzleNameString[0])
        {
            isInList = true;
            Puzzle * sPuzzle = new Puzzle();
            sPuzzle->sGameObjectID = pGameObject->getName();
            sPuzzle->sStartPosition = pStartPosition;
            sPuzzle->sEndPosition = pEndPosition;
            _puzzleNameList[i].sPuzzleList.push_back(*sPuzzle);
        }
    }
    if(isInList == false)
    {
        PuzzleName * sPuzzleNameList = new PuzzleName();
        sPuzzleNameList->sPuzzleName = PuzzleNameString[0];
        _puzzleNameList.push_back(*sPuzzleNameList);

        Puzzle * sPuzzle = new Puzzle();
        sPuzzle->sGameObjectID = pGameObject->getName();
        sPuzzle->sStartPosition = pStartPosition;
        sPuzzle->sEndPosition = pEndPosition;
        _puzzleNameList.back().sPuzzleList.push_back(*sPuzzle);
    }

}

void Rebuild::UpdatePuzzle(std::string pPuzzleName, glm::vec3 pCurrenPosition, GameObject* pGameObject)
{
    std::string nestedString = pPuzzleName;
    std::string splitter = "_";
    size_t pos = 0;
    std::string token;
    std::vector<std::string> PuzzleNameString;
    std::vector<int> dialogNumbers;
    while ((pos = nestedString.find(splitter)) != std::string::npos)
    {
    token = nestedString.substr(0, pos);
    nestedString.erase(0, pos + splitter.length());
    PuzzleNameString.push_back(token);
    }
    if(PuzzleNameString.size() == 0)
    {
        PuzzleNameString.push_back(pPuzzleName);
    }
    int trueCounter = 0;
    for(int i = 0; i < _puzzleNameList.size();i++)
    {
        if(_puzzleNameList[i].sPuzzleName == PuzzleNameString[0])
        {
            for(int j =0; j < _puzzleNameList[i].sPuzzleList.size();j++)
            {
                if(_puzzleNameList[i].sPuzzleList[j].sGameObjectID == pGameObject->getName())
                {
                    _puzzleNameList[i].sPuzzleList[j].sStartPosition = pCurrenPosition;

                    if(_puzzleNameList[i].sPuzzleList[j].sStartPosition == _puzzleNameList[i].sPuzzleList[j].sEndPosition)
                    {
                        _puzzleNameList[i].sPuzzleList[j].sInPlace = true;
                        for(int t = 0; t <_puzzleNameList[i].sPuzzleList.size();t++)
                        {
                            if(_puzzleNameList[i].sPuzzleList[j].sInPlace == true)
                            {
                                trueCounter++;
                                if(trueCounter == _puzzleNameList[i].sPuzzleList.size())
                                {
                                    LuaLoader::GetInstance()->SetCompletedPuzzle(PuzzleNameString[0]);
                                }
                                Rebuild::SavePuzzle(pGameObject->getName());
                            }
                        }
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
            PlayerProgress::GetInstance()->gameObjectName.push_back(pPuzzleName);
        }
    }
}

Rebuild::~Rebuild()
{
    //dtor
}
