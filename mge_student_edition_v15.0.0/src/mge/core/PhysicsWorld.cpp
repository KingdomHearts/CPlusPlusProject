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

void PhysicsWorld::AddColliderToObject(float pSizeX, float pSizeY, float pSizeZ, glm::vec4 pRotation, glm::vec3 pPosition, GameObject* pGO)
{
    btCollisionShape* boxCollisionShape = new btBoxShape(btVector3(pSizeX, pSizeY, pSizeZ));
        btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(
        btQuaternion(pRotation.x, pRotation.y, pRotation.z, pRotation.w),
        btVector3(pPosition.x, pPosition.y, pPosition.z)
    ));

    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
        0,                  // mass, in kg. 0 -> Static object, will never move.
        motionstate,
        boxCollisionShape,  // collision shape of body
        btVector3(0,0,0)    // local inertia
    );

    pGO->RigidBody =new btRigidBody(rigidBodyCI);
    pGO->RigidBody->setUserPointer(pGO);

    DynamicsWorld->addRigidBody(pGO->RigidBody);
}

bool PhysicsWorld::ScreenPosToWorldRay(Camera* pCamera)
{

    // The ray Start and End positions, in Normalized Device Coordinates (Have you read Tutorial 4 ?)
    glm::vec4 lRayStart_NDC(
        ((float)sf::Mouse::getPosition().x/(float)sf::VideoMode::getDesktopMode().width - 0.5f) * 2.0f, // [0,1024] -> [-1,1]
        ((float)sf::Mouse::getPosition().y/(float)sf::VideoMode::getDesktopMode().height - 0.5f) * 2.0f, // [0, 768] -> [-1,1]
        -1.0, // The near plane maps to Z=-1 in Normalized Device Coordinates
        1.0f
    );
    glm::vec4 lRayEnd_NDC(
        ((float)sf::Mouse::getPosition().x/(float)sf::VideoMode::getDesktopMode().width  - 0.5f) * 2.0f,
        ((float)sf::Mouse::getPosition().y/(float)sf::VideoMode::getDesktopMode().height - 0.5f) * 2.0f,
        0.0,
        1.0f
    );

    // Faster way (just one inverse)
    glm::mat4 M = glm::inverse(pCamera->getProjection() * pCamera->ViewMatrix);
    glm::vec4 lRayStart_world = M * lRayStart_NDC; lRayStart_world/=lRayStart_world.w;
    glm::vec4 lRayEnd_world   = M * lRayEnd_NDC  ; lRayEnd_world  /=lRayEnd_world.w;

    glm::vec3 lRayDir_world(lRayEnd_world - lRayStart_world);
    lRayDir_world = glm::normalize(lRayDir_world);

    glm::vec3 lRayStart_vec3 = glm::vec3(((float)sf::Mouse::getPosition().x/(float)sf::VideoMode::getDesktopMode().width - 0.5f) * 2.0f, ((float)sf::Mouse::getPosition().y/(float)sf::VideoMode::getDesktopMode().height - 0.5f) * 2.0f, -1.0);


    return Raycast(lRayStart_vec3, lRayDir_world);
}

bool PhysicsWorld::Raycast(glm::vec3 out_origin, glm::vec3 out_direction)
{
    /**/
    glm::vec3 out_end = out_origin + out_direction*1000.0f;

     btCollisionWorld::ClosestRayResultCallback RayCallback(
        btVector3(out_origin.x, out_origin.y, out_origin.z),
        btVector3(out_end.x, out_end.y, out_end.z)
     );
     DynamicsWorld->rayTest(
        btVector3(out_origin.x, out_origin.y, out_origin.z),
        btVector3(out_end.x, out_end.y, out_end.z),
        RayCallback
     );

     if(RayCallback.hasHit()) {
        return true;
     }else{
        return false;
     }
     /**/
}


