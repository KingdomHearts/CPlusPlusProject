#ifndef PLAYERPROGRESS_H
#define PLAYERPROGRESS_H
#include <glm.hpp>
#include <vector>
#include "mge/core/GameObject.hpp"

class PlayerProgress
{
    public:
        PlayerProgress();
        void SaveGame(std::string pSaveName,glm::vec3 pPosition);
        glm::vec3 LoadGame();
        virtual ~PlayerProgress();
    protected:
    private:
};

#endif // PLAYERPROGRESS_H
