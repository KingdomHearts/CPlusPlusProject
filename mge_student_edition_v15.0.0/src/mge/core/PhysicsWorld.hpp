#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include <BulletCollision\BroadphaseCollision\btBroadphaseInterface.h>
#include <BulletCollision\CollisionDispatch\btDefaultCollisionConfiguration.h>
#include <BulletCollision\CollisionDispatch\btCollisionDispatcher.h>
#include <BulletDynamics\ConstraintSolver\btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics\Dynamics\btDiscreteDynamicsWorld.h>
#include <BulletCollision\BroadphaseCollision\btDbvtBroadphase.h>

class PhysicsWorld
{
    public:
        static PhysicsWorld* GetInstance();
        btDiscreteDynamicsWorld* DynamicsWorld;
    protected:
    private:
        PhysicsWorld();
        static PhysicsWorld* physicsWorldInstance;
};

#endif // PHYSICSWORLD_H
