#include <glm.hpp>
#include <iostream>
#include <string>
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

#include <SFML/Audio.hpp>

//construct the game class into _window, _renderer and hud (other parts are initialized by build)
MGEDemo::MGEDemo():AbstractGame ()
{
}
void MGEDemo::initialize() {
    //setup the core part
    AbstractGame::initialize();

    //------Initialize Bullet
    // Build the broadphase
    btBroadphaseInterface* broadphase = new btDbvtBroadphase();

    // Set up the collision configuration and dispatcher
    btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
    btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // The actual physics solver
    btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

    // The world.
    btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0,-9.81f,0));
    //------

    //AssetList = new std::vector<Mesh>();

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
    LuaLoader * LL = new LuaLoader("","");
    LL->LoadAllModels();
    LL->LoadAllInteractiveModels();
    /**/

    MainHall *mainHall = new MainHall("MainHall");
    _world->add(mainHall);

    GameObject * CameraPositionTarget = new GameObject("EmptyCamera",glm::vec3(0,3,-40));
    CameraPositionTarget->setBehaviour(KeyboardBehaviour::GetInstance());
    _world->add(CameraPositionTarget);

    Camera* camera = new Camera ("camera", glm::vec3(0,3,0));
    camera->setBehaviour(new MouseBehaviour (CameraPositionTarget,camera, 10.0f));
    _world->add(camera);
    _world->setMainCamera(camera);
}

void MGEDemo::_render() {
    AbstractGame::_render();
    _updateHud();

    //_world->renderDebugInfo();
}

void MGEDemo::_updateHud() {
    string debugInfo = "";
    debugInfo += string ("FPS:") + std::to_string(FPS::getFPS())+"\n";

    _hud->setDebugInfo(debugInfo);
    _hud->draw();
}


MGEDemo::~MGEDemo()
{
	//dtor
}
