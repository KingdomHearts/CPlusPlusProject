#include "LuaLoader.hpp"
#include "mge/config.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "mge/core/Mesh.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/core/World.hpp"

#include "mge/core/AbstractGame.hpp"

#include "mge/util/Audio.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"

#include <vector>

#include <time.h>

class timer {
	private:
		unsigned long begTime;
	public:
		void start() {
			begTime = clock();
		}

		unsigned long elapsedTime() {
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool isTimeout(unsigned long seconds) {
			return seconds >= elapsedTime();
		}
};
timer t;
Audio * _audio = new Audio("",0);
std::vector<DialogStruct> * dialogList = new std::vector<DialogStruct>();
int waitSeconds = 0;
std::vector<int> waitTimesList;
std::vector<int> DialogNumberList;

LuaLoader::LuaLoader(std::string pName,std::string pLuaFileName) : GameObject(pName)
{
	std::cout << "Lua is loading ..."  << std::endl;
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/TestLua.lua");
	lua_call(lua,0,0);
	lua_close(lua);
	std::cout << "Lua Loaded."  << std::endl;
}

int Print(lua_State * lua)
{
    std::cout << "pink fluffy unicorns" << std::endl;
    return 0;
}

int AddInteractiveModel(lua_State * lua)
{
    std::cout << "AddInteractiveModel start"  << std::endl;
    std::string IDname;
    std::string Model;
    std::string Texture;
    std::string sPosition;
    glm::vec3 vPosition;
    std::string sRotation;
    float fRotation;



    if (lua_isstring(lua, -35)) {
		IDname = lua_tostring(lua, -35);
	}
    if (lua_isstring(lua, -34)) {
		Model = lua_tostring(lua, -34);
	}
	if (lua_isstring(lua, -33)) {
		Texture= lua_tostring(lua, -33);
	}
	float cm[16];
	for (int i=0; i<16; i++) {
        cm[i] = lua_tonumber(lua, -((31-i)+1));
	}
	float fm[16];
	for (int i=0; i<16; i++) {
        fm[i] = lua_tonumber(lua, -((15-i)+1));
	}

    Mesh* mesh = Mesh::load("mge/models/"+Model);
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/bricks.jpg"));
    if(Texture != ""){
        textureMaterial = new TextureMaterial (Texture::load ("mge/textures/"+Texture));
    }
    GameObject* GO = new GameObject (IDname, glm::vec3(0,0,0));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);

    World::GetInstance()->MeshList.push_back(*mesh);

    glm::mat4 currentMatrix(cm[0],  cm[4],  cm[8],  cm[12],
                            cm[1],  cm[5],  cm[9],  cm[13],
                            cm[2],  cm[6],  cm[10], cm[14],
                            cm[3],  cm[7],  cm[11], cm[15]);

    glm::mat4 finalMatrix  (fm[0],  fm[4],  fm[8],  fm[12],
                            fm[1],  fm[5],  fm[9],  fm[13],
                            fm[2],  fm[6],  fm[10], fm[14],
                            fm[3],  fm[7],  fm[11], fm[15]);

    /**/
    currentMatrix = glm::transpose(currentMatrix);
    currentMatrix[0][0] *= -1;
    currentMatrix[1][0] *= -1;
    currentMatrix[2][0] *= -1;
    currentMatrix[3][0] *= -1;

    finalMatrix = glm::transpose(finalMatrix);
    finalMatrix[0][0] *= -1;
    finalMatrix[1][0] *= -1;
    finalMatrix[2][0] *= -1;
    finalMatrix[3][0] *= -1;
    /**/


    GO->setTransform(currentMatrix);

    KeyboardBehaviour::GetInstance()->BindMeshToButton(mesh,finalMatrix,GO);

    std::cout << currentMatrix << std::endl;
    std::cout << finalMatrix << std::endl;


    std::cout << World::GetInstance()->MeshList.size() << std::endl;

    std::cout << "AddInteractiveModel end"  << std::endl;

    return 0;

}

int AddModel(lua_State * lua)
{
    std::cout << "AddModel start"  << std::endl;

    std::string IDname;
    std::string Model;
    std::string Texture;
    std::string sPosition;
    glm::vec3 vPosition;
    std::string sRotation;
    float fRotation;

    if (lua_isstring(lua, -19)) {
		IDname = lua_tostring(lua, -19);
	}
    if (lua_isstring(lua, -18)) {
		Model = lua_tostring(lua, -18);
	}
	if (lua_isstring(lua, -17)) {
		Texture= lua_tostring(lua, -17);
	}
	float m[16];
	for (int i=0; i<16; i++) {
        m[i] = lua_tonumber(lua, -((15-i)+1));
	}

    Mesh* mesh = Mesh::load("mge/models/"+Model);
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/bricks.jpg"));
    if(Texture != ""){
        textureMaterial = new TextureMaterial (Texture::load ("mge/textures/"+Texture));
    }
    GameObject* GO = new GameObject (IDname, glm::vec3(0,0,0));
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);
    World::GetInstance()->MeshList.push_back(*mesh);

    glm::mat4 matrix(m[0],  m[4],  m[8],  m[12],
                     m[1],  m[5],  m[9],  m[13],
                     m[2],  m[6],  m[10], m[14],
                     m[3],  m[7],  m[11], m[15]);

    matrix = glm::transpose(matrix);
    matrix[0][0] *= -1;
    matrix[1][0] *= -1;
    matrix[2][0] *= -1;
    matrix[3][0] *= -1;
    GO->setTransform(matrix);
    std::cout << "AddModel end"  << std::endl;

    return 0;

}

void LuaLoader::LoadAllModels(){


    std::cout << "Loading Models ..."  << std::endl;

    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/AssetLoader.lua");

    lua_pushcfunction(lua, AddModel);
    lua_setglobal(lua, "AddModel");

	lua_call(lua,0,0);
	lua_close(lua);

	std::cout << "Models Loaded"  << std::endl;
}

void LuaLoader::LoadAllInteractiveModels(){

    std::cout << "Loading Interactive Models ..."  << std::endl;

    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/AssetLoaderInteractable.lua");

    lua_pushcfunction(lua, AddInteractiveModel);
    lua_setglobal(lua, "AddInteractiveModel");

	lua_call(lua,0,0);
	lua_close(lua);

    std::cout << "Interactive Models Loaded"  << std::endl;
}

int AddSound(lua_State * lua)
{

    AudioStruct * sAudio = new AudioStruct();
    sAudio->sObject = lua_tostring(lua,-1);
    sAudio->sSetAttenuation = lua_tonumber(lua,-2);
    sAudio->sMinDistance = lua_tonumber(lua,-3);
    sAudio->sIs3D = lua_toboolean(lua,-4);
    sAudio->sSetVolume = lua_tonumber(lua,-5);
    sAudio->sTrigger = lua_tostring(lua,-6);
    sAudio->sLayer = lua_tonumber(lua,-7);
    sAudio->sLoop = lua_toboolean(lua,-8);
    sAudio->sFileName = lua_tostring(lua,-9);
    sAudio->sID = lua_tostring(lua,-10);
    World::GetInstance()->AudioList.push_back(*sAudio);
    return 0;
}

void LuaLoader::LoadSounds()
{
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/SoundLoader.lua");

    lua_pushcfunction(lua, AddSound);
    lua_setglobal(lua, "AddSound");

	lua_call(lua,0,0);
	lua_close(lua);
}

int ID(lua_State * lua)
{
    std::string IDString = lua_tostring(lua,-1);
    return 0;
}

int Text(lua_State * lua)
{
    DialogStruct * dialog = new DialogStruct();
    dialog->sScreenTime = lua_tonumber(lua, -1);
    dialog->sText = lua_tostring(lua, -2);
    dialog->sDialogNumber = lua_tonumber(lua, -3);
    dialogList->push_back(*dialog);
    return 0;
}

int Delay(lua_State * lua)
{
    return 0;
}

int Freedom(lua_State * lua)
{
    return 0;
}

int Music(lua_State * lua)
{
    return 0;
}

void LuaLoader::LoadAllDialogs()
{
    lua_State * dialogLua = luaL_newstate();
    luaL_openlibs(dialogLua);
	luaL_loadfile(dialogLua,"mge/lua/Introduction.lua");
	lua_register(dialogLua,"ID",ID);
    lua_register(dialogLua,"Text",Text);
    lua_register(dialogLua,"Delay",Delay);
    lua_register(dialogLua,"Freedom",Freedom);
    lua_register(dialogLua,"Music",Music);
    lua_call(dialogLua,0,0);
}

int PlaySound(lua_State * lua)
{
    _audio->PlaySound(lua_tostring(lua,-1));
    std::cout << "pizza salami" << std::endl;
    return 0;
}
int StopSound(lua_State * lua)
{
    _audio->StopSound(lua_tostring(lua,-1));
    return 0;
}

int AddModelToScene(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
    return 0;
}

int RemoveModelFromScene(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
    return 0;
}

int Trigger(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
    return 0;
}

int Timer(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
    return 0;
}

int DisplayMessage(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
    return 0;
}

int Dialog(lua_State * lua)
{
    std::cout << "pizza olandaise" << std::endl;
    return 0;
}

int FredHud(lua_State * lua)
{
    bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int OpenDoor(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int Destroy(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int PickUpModel(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int PlaceModel(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int Freeze(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}
int wait(lua_State * lua)
{
    waitTimesList.push_back(lua_tonumber(lua,-1));
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}
int playDialogueTrack(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int playSubtitleScript(lua_State * lua)
{
    DialogNumberList.push_back(lua_tonumber(lua,-1));
    /**
    bool isDialogIsDone = false;
    int dialogNumber = lua_tonumber(lua,-1);
    for(std::vector<DialogStruct>::iterator i =  dialogList->begin(); i != dialogList->end(); i++)
    {
        if(i->sDialogNumber == dialogNumber)
        {
            while(isDialogIsDone == false)
            {
                if(t.elapsedTime() >= waitSeconds)
                {
                    std::cout << i->sText << std::endl;
    std::cout << "test2313" << std::endl;
                    waitTimes.erase(waitTimes.begin());
                }
                if (waitTimes.size() == 0)
                {
                    isDialogIsDone = true;
                }

            }
        }
    }
    **/
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int Load(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}
int SetState(lua_State * lua)
{
    return 0;
}

void LuaLoader::RuntimeUpdater()
{
	//luaL_loadfile(lua,"mge/lua/Runtime.lua");
    lua_getglobal(lua, "update");
	lua_call(lua,0,0);
	//lua_close(lua);
	//lua_call(lua,0,0);
}

void LuaLoader::RuntimeLoader()
{
    lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/GameScript.lua");

	lua_register(lua,"FredHud",FredHud);
	lua_register(lua,"OpenDoor",OpenDoor);
	lua_register(lua,"Destroy",Destroy);
	lua_register(lua,"PickUpModel",PickUpModel);
	lua_register(lua,"PlaceModel",PlaceModel);
	lua_register(lua,"freeze",Freeze);
	lua_register(lua,"wait",wait);
	lua_register(lua,"playDialogueTrack",playDialogueTrack);
	lua_register(lua,"playSubtitleScript",playSubtitleScript);
	lua_register(lua,"Load",Load);
	lua_register(lua,"SetState",SetState);

	//luaL_loadfile(lua,"mge/lua/Runtime.lua");

    //lua_register(lua,"Print",Print);
    //lua_register(lua,"AddSound",AddSound);
    //lua_register(lua,"PlaySound",PlaySound);
    //lua_register(lua,"StopSound",StopSound);
	lua_call(lua,0,0);

    lua_getglobal(lua,"state");
    std::string state = lua_tostring(lua,lua_gettop( lua ));

    lua_getglobal(lua,"pickedUpFred");
    bool pickedUpFred = lua_toboolean(lua,lua_gettop( lua ));

    lua_getglobal(lua,"pickedUpFredSeconds");
    int pickedUpFredSeconds = lua_tonumber(lua,lua_gettop( lua ));

    lua_getglobal(lua,"player_Opendoor");
    bool player_Opendoor = lua_toboolean(lua,lua_gettop( lua ));

    lua_getglobal(lua,"player_PicksUp");
    bool player_PicksUp = lua_toboolean(lua,lua_gettop( lua ));

    lua_getglobal(lua,"player_PlaceDown");
    bool player_PlaceDown = lua_toboolean(lua,lua_gettop( lua ));

    lua_getglobal(lua,"goingToExhibit");
    bool GoingToExhibit = lua_toboolean(lua,lua_gettop( lua ));

    lua_getglobal(lua,"goingToExhibitSeconds");
    int GoingToExhibitSeconds = lua_tonumber(lua,lua_gettop( lua ));

    lua_getglobal(lua,"eventFred");
    std::string eventFred = lua_tostring(lua,lua_gettop( lua ));

	//lua_close(lua);
}


LuaLoader::~LuaLoader()
{
    //dtor
}
