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
#include "mge/core/PhysicsWorld.hpp"

#include <SFML/Audio.hpp>

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
    LuaLoader * LL = new LuaLoader("","");
    LL->LoadAllInteractiveModels();
    LL->LoadAllModels();
    /**/

    MainHall *mainHall = new MainHall("MainHall");
    _world->add(mainHall);

    GameObject * CameraPositionTarget = new GameObject("EmptyCamera",glm::vec3(0,0,10));
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
