#include "AbstractGame.hpp"

#include <iostream>
using namespace std;

#include "mge/core/Timer.hpp"
#include "mge/core/FPS.hpp"
#include "mge/core/Renderer.hpp"
#include "mge/core/World.hpp"
#include "mge/behaviours/KeyboardBehaviour.hpp"
#include "mge/core/Timer.hpp"

AbstractGame::AbstractGame():_window(NULL),_renderer(NULL),_world(NULL),_running(false)
{
    //ctor
}

AbstractGame::~AbstractGame()
{
    //dtor
    delete _window;
    delete _renderer;
    delete _world;
}

void AbstractGame::initialize() {
    cout << "Initializing engine..." << endl << endl;
    _initializeWindow();
    _printVersionInfo();
    _initializeGlew();
    _initializeRenderer();
    _initializeWorld();
    _initializeScene();
    cout << endl << "Engine initialized." << endl << endl;
}

///SETUP

void AbstractGame::_initializeWindow() {
	cout << "Initializing window..." << endl;
	_window = new sf::RenderWindow( sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height), "My Game!", sf::Style::Default, sf::ContextSettings(24,8,0,3,3));
	_window->setMouseCursorVisible(false);
	_window->setVerticalSyncEnabled(true);
    cout << "Window initialized." << endl << endl;
}

void AbstractGame::_printVersionInfo() {
	cout << "Context info:" << endl;
    cout << "----------------------------------" << endl;
    //print some debug stats for whoever cares
    const GLubyte *renderer = glGetString( GL_RENDERER );
    const GLubyte *vendor = glGetString( GL_VENDOR );
    const GLubyte *version = glGetString( GL_VERSION );
    const GLubyte *glslVersion = glGetString( GL_SHADING_LANGUAGE_VERSION );
    //nice consistency here in the way OpenGl retrieves values
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    printf("GL Vendor : %s\n", vendor);
    printf("GL Renderer : %s\n", renderer);
    printf("GL Version (string) : %s\n", version);
    printf("GL Version (integer) : %d.%d\n", major, minor);
    printf("GLSL Version : %s\n", glslVersion);

    cout << "----------------------------------" << endl << endl;
}

void AbstractGame::_initializeGlew() {
	cout << "Initializing GLEW..." << endl;
    //initialize the opengl extension wrangler
    GLint glewStatus = glewInit();
	cout << "Initialized GLEW, status (1 == OK, 0 == FAILED):" << (glewStatus == GLEW_OK) << endl << endl;
}

void AbstractGame::_initializeRenderer() {
    //setup our own renderer
	cout << "Initializing renderer..." << endl;
	_renderer = new Renderer();
    cout << "Renderer done." << endl << endl;
}

void AbstractGame::_initializeWorld() {
    //setup our own renderer
	cout << "Initializing world..." << endl;
	_world = World::GetInstance();
    cout << "World initialized." << endl << endl;
}

void KeyPressings(LuaLoader * luaLoader)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        luaLoader->KeyPressed("Q");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        luaLoader->KeyPressed("E");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        luaLoader->KeyPressed("R");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        luaLoader->KeyPressed("T");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        luaLoader->KeyPressed("Y");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
        luaLoader->KeyPressed("U");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        luaLoader->KeyPressed("I");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
        luaLoader->KeyPressed("O");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        luaLoader->KeyPressed("P");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        luaLoader->KeyPressed("F");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        luaLoader->KeyPressed("G");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        luaLoader->KeyPressed("H");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
        luaLoader->KeyPressed("J");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        luaLoader->KeyPressed("K");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        luaLoader->KeyPressed("L");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        luaLoader->KeyPressed("Z");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        luaLoader->KeyPressed("X");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        luaLoader->KeyPressed("C");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        luaLoader->KeyPressed("V");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        luaLoader->KeyPressed("B");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
        luaLoader->KeyPressed("N");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        luaLoader->KeyPressed("M");
    }

}

bool skip = false;
bool PickedUpFred = true;
bool DialogIsFinish = false;
int luaTimer = 0;
float screenTime;
float waitlistTime;
bool isShowing = false;
bool isStartTime = true;
bool isShowingDialog = false;
bool isAudioStarted = false;
bool startedWaitTime = true;
bool isLuaStarted = true;
bool canPressSpace = true;
int threadTimer = 0;
int luaTimerPassed = 0;
int militimer = 0;
int waitTime =0;
Audio * audio = new Audio("",0);
//Time waitlistTime;

void TimerThread()
{
    while(true)
    {
        sf::sleep(sf::milliseconds(10));
        militimer++;
        if(militimer == 100)
        {
    threadTimer++;
            militimer =0;
        }
        if(KeyboardBehaviour::GetKeyDown(sf::Keyboard::Space))
    {
            if(canPressSpace)
            {
            isShowing = true;
            skip = true;
    }
        }
    //
    }
//std::cout << "IsShowing: " << isShowing << std::endl;


}
void DialogThread(DebugHud * hud)
{
        while(true)
        {
            if(World::GetInstance()->DialogNumberList.size() > 0)
            {
                luaTimer =0;
                screenTime =0;
                while(World::GetInstance()->DialogNumberList.size() > 0)
                {
                    int j = World::GetInstance()->DialogNumberList.at(0);
                                //std::cout << "listCount: " << World::GetInstance()->DialogNumberList.size()  << std::endl;
                    for(std::vector<DialogStruct>::iterator i =  World::GetInstance()->dialogList->begin(); i != World::GetInstance()->dialogList->end();i++)
                    {
                        //std::cout << "isSkipped: " << skip <<std::endl;
                        if(i->sDialogNumber == j)
                        {
                                int display = i->sScreenTime;
                            if(isStartTime)
                            {
                                    screenTime = threadTimer + display;
                                isStartTime = false;
                            }
                            if(screenTime > threadTimer && isShowingDialog == false)
                            {
                                    World::GetInstance()->displayText = i->sText;
                                std::cout << i->sText << std::endl;
                                isShowingDialog = true;
                            }
                            else if (screenTime < threadTimer || skip)
                            {
                                //std::cout << "It's coming here!!!!" << std::endl;
                                isStartTime = true;
                                isShowingDialog = false;
                                        World::GetInstance()->DialogNumberList.erase(World::GetInstance()->DialogNumberList.begin(),World::GetInstance()->DialogNumberList.begin()+1);
                                //skip = false;
                            }

                            if(World::GetInstance()->DialogSoundList.size() != 0)
                            {
                               std::string audiofile = World::GetInstance()->DialogSoundList.at(0);
                                if(isAudioStarted == false)
                                {
                               audio->PlaySound(audiofile);
                                   isAudioStarted = true;
                                }
                               if(skip && isShowingDialog == false)
                               {
                                    World::GetInstance()->DialogSoundList.erase(World::GetInstance()->DialogSoundList.begin(),World::GetInstance()->DialogSoundList.begin()+1);
                                    audio->StopSound(audiofile);
                                    skip = false;
                                    isAudioStarted = false;
                               }
                               else if(isShowingDialog == false && skip == false)
                               {
                                    //std::cout << "It's coming here in audio part!!!!" << std::endl;
                                    audio->StopSound(audiofile);
                               World::GetInstance()->DialogSoundList.erase(World::GetInstance()->DialogSoundList.begin(),World::GetInstance()->DialogSoundList.begin()+1);
                                    isAudioStarted = false;
                               }
                            }
                            /**
                            if(World::GetInstance()->waitTimesList.size() > 0)
                            {
                                    int seconds = World::GetInstance()->waitTimesList.at(0);
                                if(startedWaitTime)
                                {
                                    waitTime = seconds + threadTimer;
                                    startedWaitTime = false;
                                }
                                if(waitTime > threadTimer)
                                {
                                World::GetInstance()->waitTimesList.erase(World::GetInstance()->waitTimesList.begin(),World::GetInstance()->waitTimesList.begin()+1);
                                    waitTime = 0;
                                    startedWaitTime = true;
                                }
                            }
                            /**/
                        }
                    }
                }
            }
            if(World::GetInstance()->state == "")
            {
                DialogIsFinish = true;
            }

            if(World::GetInstance()->startTimer)
            {
                if(World::GetInstance()->DialogSoundList.size() == 0)
                {
                    if(isLuaStarted == true)
                    {
                        luaTimerPassed = threadTimer + 1;
                        isLuaStarted = false;
                        canPressSpace = false;
                    }
                    if(threadTimer > luaTimerPassed)
                    {
                luaTimer = luaTimer + 1;
                        isLuaStarted = true;
                        canPressSpace = false;
                    }
                    if(threadTimer == World::GetInstance()->maxTime)
                    {
                        World::GetInstance()->maxTime =0;
                        canPressSpace = true;
                    }

                }

                //std::cout << luaTimer << std::endl;
            }

        }

}
///LOOP

void AbstractGame::run()
{
    sf::Thread timerThread(&TimerThread);
    timerThread.launch();
    sf::Thread myThread(&DialogThread,_hud);
    myThread.launch();
	_running = true;

    _luaLoader = LuaLoader::GetInstance();

    int Count = 0;
    bool startGame = false;

	while (_running) {

		Timer::update();
		FPS::update();
	    //clear frame, do it here so we can draw debug stuff in any other step etc
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


        _update();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            startGame = true;
        }
        if(startGame)
        {
            if(World::GetInstance() != NULL && Count == 0)
            {
                _luaLoader->LoadSounds();
                _luaLoader->RuntimeLoader();
                _luaLoader->LoadAllDialogs();
                Count++;
            }
            if(World::GetInstance() != NULL && Count == 1)
            {
                _luaLoader->RuntimeUpdater();

            }
        }
        //collision loop over here?
        _render();

        //swap colorbuffer to screen
        _window->display();
        //_hud = new DebugHud(_window);

        if(DialogIsFinish)
        {
            if(startGame)
            {
                std::string nextState = World::GetInstance()->nextState;
                _luaLoader->SetNewState(nextState);
                DialogIsFinish = false;
            }
        }
        else
        {
            canPressSpace = true;
        }
        if(World::GetInstance()->startTimer)
        {
            _luaLoader->SetTime(luaTimer);
        }

        KeyPressings(_luaLoader);

		_processEvents();
	}
}

void AbstractGame::_update() {
    _world->update(Timer::deltaTime(), glm::mat4());
}

void AbstractGame::_render () {
    _renderer->render(_world);
}

void AbstractGame::_processEvents()
{
	sf::Event event;
	bool exit = false;



	//we must empty the event queue
	while( _window->pollEvent( event ) ) {
        //give all system event listeners a chance to handle events
        //optionally to be implemented by you...
        //SystemEventDispatcher::dispatchEvent(event);

        switch (event.type) {
            case sf::Event::Closed:
                exit = true;
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    exit = true;
                }
                break;
            case sf::Event::Resized:
                //would be better to move this to the renderer
                //this version implements nonconstrained match viewport scaling
                glViewport(0, 0, event.size.width, event.size.height);
                break;
            default:
                break;
        }
	}

	if (exit) {
        _window->close();
        _running = false;
	}
}



