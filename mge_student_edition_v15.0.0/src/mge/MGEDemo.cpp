#include <glm.hpp>
#include <iostream>
#include <string>
#include <SFML/Window.hpp>
using namespace std;

#include "mge/core/Renderer.hpp"

#include "mge/core/Mesh.hpp"
#include "mge/core/World.hpp"
#include "mge/core/FPS.hpp"

#include "mge/rooms/MainHall.h"
#include "LuaLoader.hpp"

#include "mge/core/Camera.hpp"

#include "mge/core/GameObject.hpp"
#include "mge/materials/AbstractMaterial.hpp"

#include "mge/materials/ColorMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"

#include "mge/behaviours/RotatingBehaviour.hpp"
#include "mge/behaviours/KeysBehaviour.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"
#include "mge/behaviours/LookAt.hpp"
#include "mge/behaviours/MouseBehaviour.hpp"

#include "mge/util/DebugHud.hpp"

#include "mge/config.hpp"
#include "mge/MGEDemo.hpp"
#include "mge/core/PhysicsWorld.hpp"

#include <BulletCollision/BroadphaseCollision/btCollisionAlgorithm.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>
#include <BulletCollision/BroadphaseCollision/btOverlappingPairCache.h>
#include <BulletCollision/CollisionDispatch/btCollisionObject.h>

#include <SFML/Audio.hpp>
#include "mge/core/Triggers.hpp"

//construct the game class into _window, _renderer and hud (other parts are initialized by build)
MGEDemo::MGEDemo():AbstractGame ()
{
}
void MGEDemo::initialize() {
    //setup the core part
    AbstractGame::initialize();

    //AssetList = new std::vector<Mesh>();
    //PhysicsWorld::GetInstance();
    //setup the custom part
	cout << "Initializing HUD" << endl;
	_hud = new DebugHud(_window);
	cout << "HUD initialized." << endl << endl;
}

//build the game _world
void MGEDemo::_initializeScene()
{
    //SCENE SETUP
    /**/
    LuaLoader * LL = LuaLoader::GetInstance();
    LL->LoadAllInteractiveModels();
    LL->LoadAllModels();
    LL->LoadAllTiggers();
    /**/
    PhysicsWorld::GetInstance();
    MainHall *mainHall = new MainHall("MainHall");
    _world->add(mainHall);

    /**/
    GameObject * emptyGameObject = new GameObject("Empty");
    GameObject * CameraPositionTarget = new GameObject("EmptyCamera",glm::vec3(0,0,0));
    CameraPositionTarget->setBehaviour(KeyboardBehaviour::GetInstance());
    _world->add(CameraPositionTarget);
    /**/

    _camera = new Camera ("camera", glm::vec3(0,0,0));
    _camera->setBehaviour(new MouseBehaviour (CameraPositionTarget,_camera, 10.0f));
    _camera->setParent(emptyGameObject);
    _world->add(_camera);
    _world->setMainCamera(_camera);
}

void MGEDemo::_render() {
    AbstractGame::_render();
    _updateHud();
    TriggerObjects trigger = Triggers::GetInstance()->CheckTriggers(*_camera);
    if(trigger.sHit)
    {
        std::cout << "test" << std::endl;
    }

       //std::cout << "G: " << _camera->getChildCount() << std::endl;
       //std::cout << "L: " << _camera->getParent()->getLocalPosition() << std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        PlayerProgress::GetInstance()->Position = _camera->getWorldPosition();

        PlayerProgress::GetInstance()->SaveGame();
        //_playerProgress->SaveGame();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        _camera->getParent()->setLocalPosition(PlayerProgress::GetInstance()->LoadGame());
       //_camera->getParent()->setLocalPosition(_playerProgress->LoadGame());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        /**
            btPairCachingGhostObject  * ghostObject = new btPairCachingGhostObject();
            ghostObject->setCollisionShape()
            btManifoldArray manifoldArray;
            btBroadphasePairArray& pairArray = ghostObject->getOverlappingPairCache()->getOverlappingPairArray();
            int numPairs = pairArray.size();

            for (int i = 0; i < numPairs; ++i)
            {
                manifoldArray.clear();

                const btBroadphasePair& pair = pairArray[i];

                btBroadphasePair* collisionPair =
                    PhysicsWorld::GetInstance()->DynamicsWorld->getPairCache()->findPair(
                        pair.m_pProxy0,pair.m_pProxy1);

                if (!collisionPair) continue;

                if (collisionPair->m_algorithm)
                    collisionPair->m_algorithm->getAllContactManifolds(manifoldArray);

                for (int j=0;j<manifoldArray.size();j++)
                {
                    btPersistentManifold* manifold = manifoldArray[j];

                    bool isFirstBody = manifold->getBody0() == ghostObject;

                    btScalar direction = isFirstBody ? btScalar(-1.0) : btScalar(1.0);

                    for (int p = 0; p < manifold->getNumContacts(); ++p)
                    {
                        const btManifoldPoint&pt = manifold->getContactPoint(p);

                        if (pt.getDistance() < 0.f)
                        {
                            const btVector3& ptA = pt.getPositionWorldOnA();
                            const btVector3& ptB = pt.getPositionWorldOnB();
                            const btVector3& normalOnB = pt.m_normalWorldOnB;

                            // handle collisions here
                        }
                    }
                }
            }

            PhysicsWorld::GetInstance()->DynamicsWorld->getPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());
    **/
    }
    //_world->renderDebugInfo();
}

void MGEDemo::_updateHud() {
    string debugInfo = "";
    debugInfo += string ("FPS:") + std::to_string(FPS::getFPS())+"\n";
    std::string displayText = World::GetInstance()->displayText;
    if(displayText.size() > 150)
    {
        size_type pos = displayText.find(" ",125);
        displayText.insert(pos,"\n");
    }
    int screenWidth = sf::VideoMode::getDesktopMode().width / 4;
    int screenHeight = sf::VideoMode::getDesktopMode().height - 150;
    _hud->setDebugInfo(debugInfo,10,10);
    _hud->setDebugInfo(displayText,screenWidth,screenHeight+10);
    //_hud->draw();
}


MGEDemo::~MGEDemo()
{
	//dtor
}
