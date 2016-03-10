#include "hud.h"
#include "mge/core/Mesh.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/core/World.hpp"

HUD* HUD::HUDInstance = NULL;

HUD::HUD() : GameObject("HUD")
{
    //ctor
}

HUD::~HUD()
{
    //dtor
}

HUD* HUD::GetInstance()
{
    if(HUD::HUDInstance == NULL){
        HUD::HUDInstance = new HUD();
    }
    return HUD::HUDInstance;
}

void HUD::ActivateFred()
{
    if(FredActive) return;
    FredActive = true;

    std::cout << "Fred Activated" << std::endl;
    Mesh* mesh;
    AbstractMaterial* textureMaterial;
    GameObject* GO;

    /**Borders*/
    mesh = Mesh::load("mge/HUD/Borders.obj");
    textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Borders.png"));
    GO = new GameObject ("Borders", glm::vec3(0,5,0));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    GO->scale(glm::vec3(0.25, 0.25, 0.25));
    //_borders = GO;
    World::GetInstance()->add(GO);

    /**Button*/
    mesh = Mesh::load("mge/HUD/Button.obj");
    textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Button.png"));
    GO = new GameObject ("Button", glm::vec3(0,5,0.1));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    GO->scale(glm::vec3(0.25, 0.25, 0.25));
    //_borders = GO;
    World::GetInstance()->add(GO);

    /**Inventory Box*/
    mesh = Mesh::load("mge/HUD/Inventory Box.obj");
    textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Inventory Box.png"));
    GO = new GameObject ("Inventory Box", glm::vec3(0,5,0.1));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    GO->scale(glm::vec3(0.25, 0.25, 0.25));
    //_borders = GO;
    World::GetInstance()->add(GO);

    /**Progress Bar Empty*/
    mesh = Mesh::load("mge/HUD/Progress Bar Empty.obj");
    textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Progress Bar Empty.png"));
    GO = new GameObject ("Progress Bar Empty", glm::vec3(0,5,1));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    GO->scale(glm::vec3(0.25, 0.25, 0.25));
    //_borders = GO;
    World::GetInstance()->add(GO);

    /**Scroller*/
    mesh = Mesh::load("mge/HUD/Scroller.obj");
    textureMaterial = new TextureMaterial (Texture::load ("mge/HUD/Scroller.png"));
    GO = new GameObject ("Scroller", glm::vec3(0,5,1.5));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    GO->scale(glm::vec3(0.25, 0.25, 0.25));
    //_borders = GO;
    World::GetInstance()->add(GO);
}

void HUD::DeactivateFred()
{
    //if(!FredPickedUp) return;
    if(!FredActive) return;
    FredActive = false;

    std::cout << "Fred Deactivated" << std::endl;
    World::GetInstance()->remove(_borders);
}
