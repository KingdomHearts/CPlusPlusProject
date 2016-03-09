#include "Triggers.hpp"

Triggers* Triggers::TriggersInstance = NULL;

Triggers * Triggers::GetInstance()
{
    if(Triggers::TriggersInstance == NULL){
        Triggers::TriggersInstance = new Triggers();
    }
    return Triggers::TriggersInstance;
}

Triggers::Triggers()
{
    //ctor
}

void Triggers::AddTriggers(GameObject pGameObject, glm::vec3 pPosition, float pRadius)
{
    TriggerObjects * triggerStruct = new TriggerObjects();
    triggerStruct->sGameObjectId = pGameObject.getName();
    triggerStruct->sPosition = pPosition;
    triggerStruct->sRadius = pRadius;
    _triggerObjectList.push_back(*triggerStruct);
}

TriggerObjects Triggers::CheckTriggers(Camera pCamera)
{
    for(int i =0; i<_triggerObjectList.size();i++)
    {
        glm::vec3 triggerPosition = _triggerObjectList[i].sPosition + _triggerObjectList[i].sRadius;
        if(triggerPosition.x < pCamera.getWorldPosition().x || triggerPosition.y < pCamera.getWorldPosition().y || triggerPosition.z < pCamera.getWorldPosition().z)
        {
            _triggerObjectList[i].sHit = true;
            return _triggerObjectList[i];
        }
        _triggerObjectList[i].sHit = false;
    }
    return TriggerObjects();
}

Triggers::~Triggers()
{
    //dtor
}
