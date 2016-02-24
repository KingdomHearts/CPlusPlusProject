#ifndef MOUSEBEHAVIOUR_H
#define MOUSEBEHAVIOUR_H

#include <glm.hpp>
#include "mge/behaviours/AbstractBehaviour.hpp"
#include "mge/behaviours/LookAt.hpp"
#include <iostream>
#include "mge/core/World.hpp"
#include "mge/core/Camera.hpp"

class MouseBehaviour : public AbstractBehaviour
{
    public:
        MouseBehaviour(GameObject* pCameraPosition,Camera* pCamera, float pDistance);
        virtual ~MouseBehaviour();

        virtual void update( float step );
    protected:
        AbstractBehaviour* _lookAt;
    private:
        GameObject* _cameraPosition;
        float _distance;
        GameObject* _emptyCameraParent;
        GameObject* _emptyChild;
        Camera* _camera;

        void Looking();
        void RaycastTest();
};

#endif // ORBITBEHAVIOUR_H
