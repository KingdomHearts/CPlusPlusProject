#ifndef MOUSEBEHAVIOUR_H
#define MOUSEBEHAVIOUR_H

#include <glm.hpp>
#include "mge/behaviours/AbstractBehaviour.hpp"
#include "mge/behaviours/LookAt.hpp"
#include <iostream>
#include "mge/core/Raycast.hpp"
#include "mge/core/World.hpp"

class MouseBehaviour : public AbstractBehaviour
{
    public:
        MouseBehaviour(GameObject* pCameraPosition, float pDistance);
        virtual ~MouseBehaviour();

        virtual void update( float step );
    protected:
        AbstractBehaviour* _lookAt;
    private:
        GameObject* _cameraPosition;
        float _distance;
        GameObject* _emptyCameraParent;
        GameObject* _emptyChild;

        void Looking();
        void RaycastTest();
};

#endif // ORBITBEHAVIOUR_H
