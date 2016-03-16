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
#include "mge/core/PhysicsWorld.hpp"
#include "hud.h"
#include "mge/core/Triggers.hpp"

#include "mge/core/AbstractGame.hpp"

#include "mge/util/Audio.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"

#include "mge/util/DebugHud.hpp"

#include <vector>

#include <time.h>

#include <SFML/System/Thread.hpp>
#include "mge/puzzles/Inventory.h"


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

bool DialogIsRunning = true;
timer t;
Audio * _audio = new Audio("",0);
int waitSeconds = 0;
//std::vector<DialogStruct> * dialogList = new std::vector<DialogStruct>();
//std::vector<int> waitTimesList;
//std::vector<int> DialogNumberList;
LuaLoader* LuaLoader::LuaLoaderInstance = NULL;

LuaLoader* LuaLoader::GetInstance()
{
    if(LuaLoader::LuaLoaderInstance == NULL){
        LuaLoader::LuaLoaderInstance = new LuaLoader();
    }
    return LuaLoader::LuaLoaderInstance;
}

LuaLoader::LuaLoader() : GameObject("LUA")
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
    std::cout << "AddInteractiveModel start" << std::endl;
    std::string IDname;
    std::string Model;
    std::string Texture;
    float sizeX;
    float sizeY;
    float sizeZ;
    float rotationX;
    float rotationY;
    float rotationZ;
    float rotationW;

    if (lua_isstring(lua, -42)) {
		IDname = lua_tostring(lua, -42);
	}
    if (lua_isstring(lua, -41)) {
		Model = lua_tostring(lua, -41);
	}
	if (lua_isstring(lua, -40)) {
		Texture= lua_tostring(lua, -40);
	}
    sizeX = lua_tonumber(lua, -39);
    sizeY = lua_tonumber(lua, -38);
    sizeZ = lua_tonumber(lua, -37);
    rotationX = lua_tonumber(lua, -36);
    rotationY = lua_tonumber(lua, -35);
    rotationZ = lua_tonumber(lua, -34);
    rotationW = lua_tonumber(lua, -33);
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
    GameObject* GO = new GameObject (IDname, glm::vec3(0,0,0), true);
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);

    World::GetInstance()->MeshList.push_back(*mesh);

    glm::mat4 currentMatrix(cm[0],  cm[1],  cm[2],  cm[3],
                            cm[4],  cm[5],  cm[6],  cm[7],
                            cm[8],  cm[9],  cm[10], cm[11],
                            cm[12], cm[13], cm[14], cm[15]);

    currentMatrix[2][0] *= -1;
    currentMatrix[0][2] *= -1;
    currentMatrix[3][0] *= -1;

    glm::mat4 finalMatrix  (fm[0],  fm[1],  fm[2],  fm[3],
                            fm[4],  fm[5],  fm[6],  fm[7],
                            fm[8],  fm[9],  fm[10], fm[11],
                            fm[12], fm[13], fm[14], fm[15]);

    finalMatrix[2][0] *= -1;
    finalMatrix[0][2] *= -1;
    finalMatrix[3][0] *= -1;

    /**
    glm::mat4 currentMatrix(cm[0],  cm[4],  cm[8],  cm[12],
                            cm[1],  cm[5],  cm[9],  cm[13],
                            cm[2],  cm[6],  cm[10], cm[14],
                            cm[3],  cm[7],  cm[11], cm[15]);

    glm::mat4 finalMatrix  (fm[0],  fm[4],  fm[8],  fm[12],
                            fm[1],  fm[5],  fm[9],  fm[13],
                            fm[2],  fm[6],  fm[10], fm[14],
                            fm[3],  fm[7],  fm[11], fm[15]);


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
    GameObject * GOfinalPosition = new GameObject("TempGO", glm::vec3(0,0,0), false);
    GOfinalPosition->setTransform(finalMatrix);
    GO->GOPositionToPlace = GOfinalPosition->getLocalPosition();
    GO->TransformToPlace = finalMatrix;
    GO->setTransform(currentMatrix);

    KeyboardBehaviour::GetInstance()->BindMeshToButton(mesh,textureMaterial,finalMatrix,GO);
    GO->GOSizeX = sizeX;
    GO->GOSizeY = sizeY;
    GO->GOSizeZ = sizeZ;
    GO->GORotation = glm::vec4(rotationX, rotationY, rotationZ, rotationW);
    PhysicsWorld::GetInstance()->AddColliderToObject(GO->GOSizeX, GO->GOSizeY, GO->GOSizeZ , GO->GORotation ,GO->getLocalPosition(),0, GO);


    std::cout << "AddInteractiveModel end -> " << IDname << std::endl;

    return 0;

}

int AddModel(lua_State * lua)
{
    std::cout << "AddModel start"  << std::endl;

    std::string IDname;
    std::string Model;
    std::string Texture;
    float sizeX;
    float sizeY;
    float sizeZ;
    float rotationX;
    float rotationY;
    float rotationZ;
    float rotationW;

    if (lua_isstring(lua, -26)) {
		IDname = lua_tostring(lua, -26);
	}
    if (lua_isstring(lua, -25)) {
		Model = lua_tostring(lua, -25);
	}
	if (lua_isstring(lua, -24)) {
		Texture= lua_tostring(lua, -24);
	}
    sizeX = lua_tonumber(lua, -23);
    sizeY = lua_tonumber(lua, -22);
    sizeZ = lua_tonumber(lua, -21);
    rotationX = lua_tonumber(lua, -20);
    rotationY = lua_tonumber(lua, -19);
    rotationZ = lua_tonumber(lua, -18);
    rotationW = lua_tonumber(lua, -17);
	float m[16];
	for (int i=0; i<16; i++) {
        m[i] = lua_tonumber(lua, -((15-i)+1));
	}

    Mesh* mesh = Mesh::load("mge/models/"+Model);
    AbstractMaterial* textureMaterial = new TextureMaterial (Texture::load ("mge/textures/bricks.jpg"));
    if(Texture != ""){
        textureMaterial = new TextureMaterial (Texture::load ("mge/textures/"+Texture));
    }
    GameObject* GO = new GameObject (IDname, glm::vec3(0,0,0), false);
    GO->setMesh (mesh);
    GO->setMaterial(textureMaterial);
    World::GetInstance()->add(GO);
    World::GetInstance()->MeshList.push_back(*mesh);

    glm::mat4 matrix(m[0],  m[1],  m[2],  m[3],
                     m[4],  m[5],  m[6],  m[7],
                     m[8],  m[9],  m[10], m[11],
                     m[12], m[13], m[14], m[15]);

    matrix[2][0] *= -1;
    matrix[0][2] *= -1;
    matrix[3][0] *= -1;

    GO->setTransform(matrix);
    std::cout << "AddModel end -> " << IDname << std::endl;
    PhysicsWorld::GetInstance()->AddColliderToObject(sizeX, sizeY, sizeZ , glm::vec4(rotationX, rotationY, rotationZ, rotationW) ,GO->getLocalPosition(), 500.0f, GO);

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

int TriggerObject(lua_State * lua)
{
    float m[16];
	for (int i=0; i<16; i++) {
        m[i] = lua_tonumber(lua, -((15-i)+1));
	}

	glm::mat4 matrix(m[0],  m[4],  m[8],  m[12],
                     m[1],  m[5],  m[9],  m[13],
                     m[2],  m[6],  m[10], m[14],
                     m[3],  m[7],  m[11], m[15]);

    matrix = glm::transpose(matrix);
    matrix[0][0] *= -1;
    matrix[1][0] *= -1;
    matrix[2][0] *= -1;
    matrix[3][0] *= -1;

    float radius = lua_tonumber(lua,-17);
    std::string gameObjectName = lua_tostring(lua,-18);
    GameObject * GO =  new GameObject(gameObjectName,glm::vec3(0,0,0));
    GO->setTransform(matrix);
    std::cout << "GameObjectTrigger " << GO->getLocalPosition() << std::endl;
    Triggers::GetInstance()->AddTriggers(gameObjectName,GO->getLocalPosition(), radius);
}

void LuaLoader::LoadAllTiggers()
{
    lua_State *lua = luaL_newstate();
	luaL_openlibs(lua);
	luaL_loadfile(lua,"mge/lua/Triggers.lua");

    lua_register(lua, "TriggerObject",TriggerObject);

	lua_call(lua,0,0);
	lua_close(lua);
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



int Load(lua_State * lua)
{
    //bool FredHud = lua_toboolean(lua,-1);
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

int Text(lua_State * lua)
{
    DialogStruct * dialog = new DialogStruct();
    dialog->sScreenTime = lua_tonumber(lua, -1);
    dialog->sText = lua_tostring(lua, -2);
    dialog->sDialogNumber = lua_tonumber(lua, -3);
    World::GetInstance()->dialogList->push_back(*dialog);
    return 0;
}

void LuaLoader::LoadAllDialogs()
{
    lua_State * dialogLua = luaL_newstate();
    luaL_openlibs(dialogLua);
	luaL_loadfile(dialogLua,"mge/lua/DialogueScript.lua");
	lua_register(dialogLua,"ID",ID);
    lua_register(dialogLua,"Text",Text);
    lua_register(dialogLua,"Delay",Delay);
    lua_register(dialogLua,"Freedom",Freedom);
    lua_register(dialogLua,"Music",Music);
    lua_register(dialogLua,"Load",Load);
    lua_call(dialogLua,0,0);
}

int PlaySound(lua_State * lua)
{
    _audio->PlaySound(lua_tostring(lua,-1));
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
    bool isFrozen = lua_toboolean(lua,-1);
    if(isFrozen)
    {
        //sf::sleep(sf::milliseconds(10000));

    }
    return 0;
}

int wait(lua_State * lua)
{
    World::GetInstance()->waitTimesList.push_back(lua_tonumber(lua,-1));
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}
int playDialogueTrack(lua_State * lua)
{
    int dialogSoundNumber = lua_tonumber(lua,-1);
    ostringstream os;
    os << dialogSoundNumber << ".wav";
    std::string filename = os.str();
    World::GetInstance()->DialogSoundList.push_back(filename);
    //_audio->PlaySound(filename);
    std::cout << filename << std::endl;
    return 0;
}

int RandomDialogAndRepeat(lua_State * lua)
{
    std::string nestedString = lua_tostring(lua,-1);
    std::string splitter = ",";
    size_t pos = 0;
    std::string token;
    std::vector<std::string> stringNumbers;
    std::vector<int> dialogNumbers;
    while ((pos = nestedString.find(splitter)) != std::string::npos)
    {
    token = nestedString.substr(0, pos);
    nestedString.erase(0, pos + splitter.length());
    stringNumbers.push_back(token);
    }
    stringNumbers.push_back(nestedString);
    //stringNumbers.erase(stringNumbers.end(),stringNumbers.end()+1);
    for(int i = 0; i < stringNumbers.size();i++)
    {
        dialogNumbers.push_back(atoi(stringNumbers[i].c_str()));
    }
    int sameCounter=0;
    bool isTheSame = false;
    for(int i =0;i<dialogNumbers.size();i++)
    {
        if(std::find(World::GetInstance()->DialogNumberList.begin(),World::GetInstance()->DialogNumberList.end(), dialogNumbers[i])!= World::GetInstance()->DialogNumberList.end())
        {
            sameCounter++;
        }
        if(sameCounter == dialogNumbers.size())
        {
            isTheSame = true;
        }
        else
        {
            isTheSame = false;
        }
    }
    std::cout << "True or False: " << isTheSame << std::endl;
    std::cout << "numberCount: " << dialogNumbers.size() << std::endl;
    std::vector<int> randomOrder;
    int random =0;
    int dialogSize = dialogNumbers.size();
    srand(time(NULL));
    if(isTheSame)
    {
        for(int i = 0; i<dialogSize;i++)
        {
            random = rand() % dialogNumbers.size() ;
            std::cout << "random is: " << random << std::endl;
            randomOrder.push_back(dialogNumbers[random]);
            dialogNumbers.erase(std::remove(dialogNumbers.begin(), dialogNumbers.end(), dialogNumbers[random]), dialogNumbers.end());
        }
    }
    World::GetInstance()->DialogNumberList.erase(World::GetInstance()->DialogNumberList.begin(),World::GetInstance()->DialogNumberList.end());

    std::vector<std::string> stringNumbersT;
    for(int i =0; i<randomOrder.size();i++)
    {
        std::cout << "place " << i << " number: " << randomOrder[i] << std::endl;
        World::GetInstance()->DialogNumberList.push_back(randomOrder[i]);


    std::string nestedStringT = World::GetInstance()->DialogSoundList[i];
    std::string splitterT = ".";
    size_t posT = 0;
    std::string tokenT;
        while ((posT = nestedStringT.find(splitterT)) != std::string::npos)
        {
        tokenT = nestedStringT.substr(0, posT);
        std::cout << "dialog: " << tokenT << std::endl;
        nestedStringT.erase(0, posT + splitterT.length());
        stringNumbersT.push_back(tokenT);
        }

    }

    World::GetInstance()->DialogSoundList.clear();
    for(int i = 0; i < World::GetInstance()->DialogNumberList.size();i++)
    {
        for(int j =0 ; j < stringNumbersT.size();j++)
        {
            if(World::GetInstance()->DialogNumberList[i] == std::stof(stringNumbersT[j]))
            {
                ostringstream os;
                os << stringNumbersT[j] << ".wav";
                std::string filename = os.str();
                World::GetInstance()->DialogSoundList.push_back(filename);
            }
        }
    }
   // std::cout << World::GetInstance()->DialogSoundList << std::endl;

    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int playSubtitleScript(lua_State * lua)
{
    World::GetInstance()->DialogNumberList.push_back(lua_tonumber(lua,-1));
    //bool FredHud = lua_toboolean(lua,-1);
    return 0;
}

int StartTimer(lua_State * lua)
{
    World::GetInstance()->maxTime = lua_tonumber(lua,-1);
    World::GetInstance()->startTimer = true;
    //World::GetInstance()->maxTime = lua_tonumber(lua,-1);
    return 0;
}

void LuaLoader::SetTime(int pTime)
{
    lua_pushnumber(lua,pTime);
    lua_setglobal(lua,"timer");
}

void LuaLoader::PushFredToLua()
{
    lua_pushstring(lua, "Y");
    lua_setglobal(lua, "keyPressed");
}

void LuaLoader::SetNewState(std::string pNewState)
{
    lua_pushstring(lua,pNewState.c_str());
    lua_setglobal(lua,"state");
}

void LuaLoader::SetTrigger(std::string pTriggerName)
{
    lua_pushstring(lua,pTriggerName.c_str());
    lua_setglobal(lua,"trigger");
}

void LuaLoader::KeyPressed(std::string pPressedKey)
{
    World::GetInstance()->maxTime = 0;
    lua_pushstring(lua,pPressedKey.c_str());
    lua_setglobal(lua,"keyPressed");
}

int SetState(lua_State * lua)
{
    World::GetInstance()->state = "";
    World::GetInstance()->nextState = lua_tostring(lua,-1);
    lua_pushstring(lua,"");
    lua_setglobal(lua,"state");
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
	luaL_loadfile(lua,"mge/lua/GameScriptNew.lua");
	std::cout << "chrash" << std::endl;

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
	lua_register(lua,"AddSound",AddSound);
	lua_register(lua,"PlaySound",PlaySound);
    lua_register(lua,"StopSound",StopSound);
	lua_register(lua,"StartTimer",StartTimer);
	lua_register(lua,"RandomDialogAndRepeat",RandomDialogAndRepeat);

	//luaL_loadfile(lua,"mge/lua/Runtime.lua");

    //lua_register(lua,"Print",Print);
    //lua_register(lua,"AddSound",AddSound);
    //lua_register(lua,"PlaySound",PlaySound);
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
