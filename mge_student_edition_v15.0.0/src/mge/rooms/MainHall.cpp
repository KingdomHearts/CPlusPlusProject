//using namespace std;
#include "MainHall.h"
//#include "mge/core/GameObject.hpp"
#include "mge/core/Mesh.hpp"
//#include "mge/core/Renderer.hpp"
//#include "mge/core/Texture.hpp"
//#include "mge/core/World.hpp"
#include "mge/config.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/ColorMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/util/LuaLoader.hpp"
#include "mge/util/Audio.hpp"
#include "mge/core/World.hpp"
#include <vector>

MainHall::MainHall(std::string pName) : GameObject(pName)
{
    //audio1 = new Audio("mge/sounds/Spider_7.wav");
    //audio2 = new Audio("mge/sounds/Spider_7.wav");
    //audio1 = new Audio("mge/sounds/test2Mono.wav",0);
    //audio1 = new Audio("mge/sounds/Mono_Sample.wav",0);
    //audio1->SetLoop(true);
    //audio1->SetPosition(sf::Vector3f(-3.f, 0.f, 0.f));
    //audio2 = new Audio("mge/sounds/test2Mono.wav",0);
    //audio2->SetLoop(true);
    //audio2->SetMinDistance(1.f);

    //audio2->SetPosition(sf::Vector3f(3.f,0.f,0.f));
    //audio2 = new Audio(std::vector<std::string> {"mge/sounds/Spider_7.wav","mge/sounds/Sell.wav","mge/sounds/Arrow_1.wav","mge/sounds/Arrow_2.wav","mge/sounds/Arrow_3.wav","mge/sounds/Arrow_Impact.wav","mge/sounds/Cannon_Impact_1.wav","mge/sounds/Cannon_Impact_2.wav","mge/sounds/Cannon_Impact_3.wav"});

    /**
    LuaLoader * luaLoader = new LuaLoader("Lua","TestLua");
    this->add(luaLoader);
    luaLoader->LoadSounds();
    luaLoader->RuntimeLoader();

    for (std::vector<AudioStruct>::iterator i = World::GetInstance()->AudioList.begin(); i != World::GetInstance()->AudioList.end(); ++i)
    {
        Audio * audio = new Audio("mge/sounds/"+i->sFileName, i->sLayer);
        audio->SetLoop(i->sLoop);
        audio->SetVolume(i->sSetVolume);
        if(i->sIs3D)
        {
            audio->SetAttenuation(i->sSetAttenuation);
            audio->SetMinDistance(i->sMinDistance);
            // Object for 3d position
        }

    }
    **/
    //audio1->SetLoop(listAudio[1].sLoop);
    //sf::Listener::setPosition(10.f, 0.f, 5.f);
}

void MainHall::update(float pStep)
{
    std::cout << "ipdate" << std::endl;
}

MainHall    ::~MainHall()
{
    //dtor
}
