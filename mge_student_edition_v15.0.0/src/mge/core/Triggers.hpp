#ifndef TRIGGERS_H
#define TRIGGERS_H

#include "mge/core/GameObject.hpp"
#include "mge/core/Camera.hpp"

#include <vector>
#include <string>
#include <glm.hpp>

struct TriggerObjects
{
    std::string sGameObjectId;
    glm::vec3 sPosition;
    float sRadius;
    bool sHit;
    int isEntered = 0;
};

class Triggers
{
    public:
        Triggers();
        static Triggers* GetInstance();
        void AddTriggers(std::string pGameObjectName, glm::vec3 pPosition, float pRadius);
        TriggerObjects CheckTriggers(Camera camera);
        virtual ~Triggers();
    protected:
    private:
        std::vector<TriggerObjects> _triggerObjectList;
        static Triggers* TriggersInstance;
};

#endif // TRIGGERS_H
