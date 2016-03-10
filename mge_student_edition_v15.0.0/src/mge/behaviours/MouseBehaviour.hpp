#ifndef MOUSEBEHAVIOUR_H
#define MOUSEBEHAVIOUR_H

#include <glm.hpp>
#include "mge/behaviours/AbstractBehaviour.hpp"
#include "mge/behaviours/LookAt.hpp"
#include <iostream>
#include "mge/core/World.hpp"
#include "mge/core/Camera.hpp"
#include "mge/core/PhysicsWorld.hpp"

class MouseBehaviour : public AbstractBehaviour
{
    public:
        MouseBehaviour(GameObject* pCameraPosition,Camera* pCamera, float pDistance);
        virtual void update( float step );
        virtual ~MouseBehaviour();

    protected:
        AbstractBehaviour* _lookAt;
    private:
        GameObject* _cameraPosition;
        float _distance;
        //GameObject* _emptyCameraParent;
        //GameObject* _emptyChild;
        bool _fredActive = false;
        Camera* _camera;
        void Looking();
        void PickUpObject();
        void RaycastTest();
        void Hud();

        GameObject* _borders;
        GameObject* _button;
        GameObject* _inventoryBox;
        GameObject* _progressBar;
        GameObject* _scrollers;

        // position
        glm::vec3 _position = glm::vec3( 0, 3, 10 );
        // horizontal angle : toward -Z
        float _horizontalAngle = 3.14f;
        // vertical angle : 0, look at the horizon
        float _verticalAngle = 0.0f;

        float _speed = 0.0f; // 3 units / second
        float const _walkingSpeed = 4.0f;
        float const _debugSpeed = 20.0f;
        float const _mouseSpeed = 0.2f;
        bool _startup = true;
        sf::Vector2i _mousePos;
        glm::vec3 _direction;
};

#endif // ORBITBEHAVIOUR_H
