#ifndef ORBITBEHAVIOUR_H
#define ORBITBEHAVIOUR_H

#include <glm.hpp>
#include "mge/behaviours/AbstractBehaviour.hpp"
#include "mge/behaviours/LookAt.hpp"
#include <iostream>

class OrbitBehaviour : public AbstractBehaviour
{
    public:
        OrbitBehaviour(GameObject* pCameraPosition, float pDistance);
        virtual ~OrbitBehaviour();

        virtual void update( float step );
    protected:
        AbstractBehaviour* _lookAt;
    private:
        GameObject* _cameraPosition;
        float _distance;
        GameObject* _emptyCameraParent;
        GameObject* _emptyChild;
};

#endif // ORBITBEHAVIOUR_H
