#include <glm.hpp>
#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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
#include "hud.h"

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

    _camera = new Camera ("camera", glm::vec3(-30,-100,-40));
    _camera->setBehaviour(new MouseBehaviour (CameraPositionTarget,_camera, 10.0f));
    _camera->setParent(emptyGameObject);
    PhysicsWorld::GetInstance()->AddColliderToObject(1, 1, 1, glm::vec4(0,0,0,0),_camera->getLocalPosition(), 60.0f, _camera);
    _world->add(_camera);
    _world->setMainCamera(_camera);

    Mesh* mesh;
    GameObject* GO;
    AbstractMaterial* mainMenu;

    mesh = Mesh::load("mge/HUD/Plane.obj");
    mainMenu = new TextureMaterial(Texture::load("mge/HUD/main_menu.png"));
    GO = new GameObject("menu",glm::vec3(0, -0, -1));
    GO->rotate(1.6,glm::vec3(1,0,0));
    GO->setMesh(mesh);
    GO->setMaterial(mainMenu);
    GO->scale(glm::vec3(0.1, 2, 0.14));
    _menu = GO;
    _camera->add(_menu);
}

void MGEDemo::_render() {
    AbstractGame::_render();
    _updateHud();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        std::cout << "left In MGEDemo" << std::endl;
        World::GetInstance()->remove(_menu);
    }

    TriggerObjects trigger = Triggers::GetInstance()->CheckTriggers(_camera->getWorldPosition());

    if(trigger.sHit)
    {
        LuaLoader::GetInstance()->SetTrigger(trigger.sGameObjectId);
        std::cout << trigger.sGameObjectId << std::endl;
    }

       //std::cout << "G: " << _camera->getChildCount() << std::endl;
       //std::cout << "L: " << _camera->getParent()->getLocalPosition() << std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
    {
        PlayerProgress::GetInstance()->SaveGame();
        //_playerProgress->SaveGame();
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
