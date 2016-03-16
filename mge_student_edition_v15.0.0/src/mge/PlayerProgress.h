#ifndef PLAYERPROGRESS_H
#define PLAYERPROGRESS_H
#include <glm.hpp>
#include <vector>
#include "mge/core/GameObject.hpp"
#include "mge/puzzles/Rebuild.h"
#include "mge/puzzles/Inventory.h"

class PlayerProgress
{
    public:
        static PlayerProgress* GetInstance();
        PlayerProgress();
        std::string SaveName;
        glm::vec3 Position;
        std::vector<PuzzleName> SavePuzzle;
        void SaveGame();
        glm::vec3 LoadGame();
        virtual ~PlayerProgress();
    protected:
    private:
        static PlayerProgress* PlayerProgressInstance;
};

#endif // PLAYERPROGRESS_H
