#include "PhysicsWorld.hpp"

PhysicsWorld* PhysicsWorld::physicsWorldInstance = NULL;

PhysicsWorld::PhysicsWorld()
{
   // Initialize Bullet. This strictly follows http://bulletphysics.org/mediawiki-1.5.8/index.php/Hello_World,
   // even though we won't use most of this stuff.

  // Build the broadphase
  btBroadphaseInterface* broadphase = new btDbvtBroadphase();

  // Set up the collision configuration and dispatcher
  btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
  btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);

  // The actual physics solver
  btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

  // The world.
  DynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
  DynamicsWorld->setGravity(btVector3(0,-9.81f,0));
}

PhysicsWorld* PhysicsWorld::GetInstance()
{
    if(PhysicsWorld::physicsWorldInstance == NULL){
        PhysicsWorld::physicsWorldInstance = new PhysicsWorld();
    }
    return PhysicsWorld::physicsWorldInstance;
}


