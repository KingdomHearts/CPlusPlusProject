#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include "mge/core/GameObject.hpp"
#include "mge/core/AbstractGame.hpp"
#include <BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <BulletCollision/CollisionDispatch/btCollisionDispatcher.h>
#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <BulletCollision/BroadphaseCollision/btDbvtBroadphase.h>
#include <BulletCollision/CollisionShapes/btCollisionShape.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btDefaultMotionState.h>
#include "mge/core/Camera.hpp"

class PhysicsWorld
{
    public:
        static PhysicsWorld* GetInstance();
        btDiscreteDynamicsWorld* DynamicsWorld;
        void ScreenPosToWorldRay(Camera* pCamera);
        void Raycast();
        void AddColliderToObject(float pSizeX, float pSizeY, float pSizeZ, glm::vec4 pRotation, glm::vec3 pPosition, GameObject* pGO);
    protected:
    private:
        PhysicsWorld();
        static PhysicsWorld* physicsWorldInstance;
};

#endif // PHYSICSWORLD_H
