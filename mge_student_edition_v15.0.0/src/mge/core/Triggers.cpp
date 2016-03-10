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

void Triggers::AddTriggers(std::string pGameObjectName, glm::vec3 pPosition, float pRadius)
{
    TriggerObjects * triggerStruct = new TriggerObjects();
    triggerStruct->sGameObjectId = pGameObjectName;
    triggerStruct->sPosition = pPosition;
    triggerStruct->sRadius = pRadius;
        //std::cout << "sPosition: " <<pPosition << std::endl;
        //std::cout << "CameraPosition: " <<pCamera.getWorldPosition() << std::endl;
    _triggerObjectList.push_back(*triggerStruct);
}

TriggerObjects Triggers::CheckTriggers(Camera pCamera)
{
    for(int i =0; i<_triggerObjectList.size();i++)
    {
        glm::vec3 triggerPositionMax = _triggerObjectList[i].sPosition + _triggerObjectList[i].sRadius;
        glm::vec3 triggerPositionMin = _triggerObjectList[i].sPosition - _triggerObjectList[i].sRadius;
        if(triggerPositionMax.x > pCamera.getWorldPosition().x && triggerPositionMin.z < pCamera.getWorldPosition().z &&
           triggerPositionMin.x < pCamera.getWorldPosition().x && triggerPositionMax.z > pCamera.getWorldPosition().z && _triggerObjectList[i].sHit != true)
        {
            _triggerObjectList[i].sHit = true;
            return _triggerObjectList[i];
        }
        else if(triggerPositionMax.x < pCamera.getWorldPosition().x && triggerPositionMin.z > pCamera.getWorldPosition().z &&
                triggerPositionMin.x > pCamera.getWorldPosition().x && triggerPositionMax.z < pCamera.getWorldPosition().z && _triggerObjectList[i].sHit == true)
        {
        _triggerObjectList[i].sHit = false;
    }
    }
    return TriggerObjects();
}

Triggers::~Triggers()
{
    //dtor
}
