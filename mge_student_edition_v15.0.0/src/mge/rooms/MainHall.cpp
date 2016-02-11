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



MainHall::MainHall(std::string pName) : GameObject(pName)
{
CreateHall();
}

GameObject* MainHall::CreateHall()
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
    planeGround->scale(glm::vec3(5,5,5));
    planeGround->setMesh(planeMeshDefault);
    planeGround->setMaterial(textureMaterial);
    this->add(planeGround);

    GameObject* planeFront = new GameObject ("planeFront", glm::vec3(0,0,-5));
    planeFront->rotate(90,glm::vec3(90,0,0));
    planeFront->scale(glm::vec3(5,5,5));
    planeFront->setMesh(planeMeshDefault);
    planeFront->setMaterial(textureMaterial);
    this->add(planeFront);

    /**GameObject* planeRight = new GameObject ("planeRight", glm::vec3(0,0,0));
    planeRight->scale(glm::vec3(5,5,5));
    planeRight->setMesh(planeMeshDefault);
    planeRight->setMaterial(textureMaterial);
    this->add(planeRight);

    GameObject* planeLeft = new GameObject ("planeLeft", glm::vec3(0,0,0));
    planeLeft->scale(glm::vec3(5,5,5));
    planeLeft->setMesh(planeMeshDefault);
    planeLeft->setMaterial(textureMaterial);
    this->add(planeLeft);
    //_world->add(plane);
    //return plane;**/
}

MainHall    ::~MainHall()
{
    //dtor
}
