#ifndef REBUILD_H
#define REBUILD_H
#include <glm.hpp>
#include <string>
#include <vector>
#include "mge/core/GameObject.hpp"


struct Puzzle
{
    std::string sGameObjectID;
    glm::vec3 sStartPosition;
    glm::vec3 sEndPosition;
    bool sInPlace = false;
};

struct PuzzleName
{
    std::string sPuzzleName;
    std::vector<Puzzle> sPuzzleList;
    bool sComplete = false;
};

class Rebuild
{
    public:
        static Rebuild* GetInstance();
        void AddPuzzle(std::string pPuzzleName, glm::vec3 pStartPosition, glm::vec3 pEndPosition, GameObject * pGameObject);
        void UpdatePuzzle(std::string pPuzzleName, glm::vec3 pCurrenPosition, GameObject * pGameObject);
        void SavePuzzle(std::string pPuzzleName);
        virtual ~Rebuild();
    protected:
    private:
        static Rebuild* RebuildInstance;
        Rebuild();
        std::vector<PuzzleName> _puzzleNameList;
};

#endif // REBUILD_H
