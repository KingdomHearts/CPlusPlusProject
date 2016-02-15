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



MainHall::MainHall(std::string pName) : GameObject(pName)
{
    _CreateHall();
    LuaLoader * luaLoader = new LuaLoader("Lua","TestLua");
    this->add(luaLoader);
}

GameObject* MainHall::_CreateHall()
{
    //MESHES

    //load a bunch of meshes we will be using throughout this demo
    //each mesh only has to be loaded once, but can be used multiple times:
    //F is flat shaded, S is smooth shaded (normals aligned or not), check the models folder!
    Mesh* planeMeshDefault = Mesh::load (config::MGE_MODEL_PATH+"plane.obj");

    //MATERIALS

    AbstractMaterial* colorMaterial = new ColorMaterial (glm::vec3(0.2f,0,0.2f));
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load (config::MGE_TEXTURE_PATH+"land.jpg"));
    AbstractMaterial* textureMaterial2 = new TextureMaterial (Texture::load (config::MGE_TEXTURE_PATH+"bricks.jpg"));
    //ctor
    GameObject* planeGround = new GameObject ("planeGround", glm::vec3(0,0,0));
    planeGround->scale(glm::vec3(10,10,10));
    planeGround->setMesh(planeMeshDefault);
    planeGround->setMaterial(textureMaterial);
    this->add(planeGround);

    GameObject* planeFront = new GameObject ("planeFront", glm::vec3(0,10,-10));
    planeFront->rotate(glm::radians(90.0f),glm::vec3(1,0,0));
    planeFront->scale(glm::vec3(10,10,10));
    planeFront->setMesh(planeMeshDefault);
    planeFront->setMaterial(textureMaterial);
    this->add(planeFront);

    GameObject* planeRight = new GameObject ("planeRight", glm::vec3(10,10,0));
    planeRight->rotate(glm::radians(90.0f),glm::vec3(0,0,1));
    planeRight->scale(glm::vec3(10,10,10));
    planeRight->setMesh(planeMeshDefault);
    planeRight->setMaterial(textureMaterial);
    this->add(planeRight);

    GameObject* planeLeft = new GameObject ("planeLeft", glm::vec3(-10,10,0));
    planeLeft->rotate(glm::radians(90.0f),glm::vec3(0,0,-1));
    planeLeft->scale(glm::vec3(10,10,10));
    planeLeft->setMesh(planeMeshDefault);
    planeLeft->setMaterial(textureMaterial);
    this->add(planeLeft);
    //_world->add(plane);
    //return plane;
}

MainHall    ::~MainHall()
{
    //dtor
}
