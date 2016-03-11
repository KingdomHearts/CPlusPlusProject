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

bool skip = true;
bool PickedUpFred = true;
bool DialogIsFinish = false;
int luaTimer = 0;
int threadcount =0;
float screenTime;
float waitlistTime;
bool isShowing = false;
float now;
//Time waitlistTime;
 void DialogThread(DebugHud * hud)
{
        while(true)
        {
            threadcount++;
            //std::cout << Timer::now() << std::endl;
            if(World::GetInstance()->DialogNumberList.size() > 0)
            {
                luaTimer =0;
                now = Timer::now();
                while(World::GetInstance()->DialogNumberList.size() > 0)
                {
                    int j = World::GetInstance()->DialogNumberList.at(0);
                    for(std::vector<DialogStruct>::iterator i =  World::GetInstance()->dialogList->begin(); i != World::GetInstance()->dialogList->end();i++)
                    {
                        //std::cout << "isSkipped: " << skip <<std::endl;
                        if(i->sDialogNumber == j)
                        {

                            screenTime = 0;
                                int display = i->sScreenTime;
                                if(screenTime == 0 && isShowing == false)
                                {
                                    screenTime = round(Timer::now()) + display;
                                    std::cout << screenTime << std::endl;
                                    isShowing = true;
                                }
                                if(screenTime > 0 && isShowing)
                                {
                                    if(now - Timer::now() < 2)
                                    {
                                        screenTime--;
                                    }
                                    World::GetInstance()->displayText = i->sText;
                                    std::cout << i->sText << std::endl;
                                    std::cout << screenTime << std::endl;
                                }
                                else
                                {
                                    isShowing =false;
                                }
                                //sf::sleep(sf::milliseconds(display*1000));
                                //World::GetInstance()->dialogList->erase(i);

                            World::GetInstance()->DialogNumberList.erase(World::GetInstance()->DialogNumberList.begin(),World::GetInstance()->DialogNumberList.begin()+1);
                            if(World::GetInstance()->waitTimesList.size() > 0)
                            {
                                    int seconds = World::GetInstance()->waitTimesList.at(0);
                                    //sf::sleep(sf::milliseconds(seconds*1000));

                                World::GetInstance()->waitTimesList.erase(World::GetInstance()->waitTimesList.begin(),World::GetInstance()->waitTimesList.begin()+1);
                            }
                        }
                    }
                }
            }
            if(World::GetInstance()->state == "")
            {
                DialogIsFinish = true;
            }
            /**
            if(World::GetInstance()->startTimer)
            {
                sf::sleep(sf::milliseconds(1000));
                luaTimer = luaTimer + 1;

                std::cout << luaTimer << std::endl;
            }
            **/
        }

}
///LOOP

void AbstractGame::run()
{
    sf::Thread myThread(&DialogThread,_hud);
    myThread.launch();
	_running = true;

    _luaLoader = LuaLoader::GetInstance();

    int Count = 0;

	while (_running) {

		Timer::update();
		FPS::update();
	    //clear frame, do it here so we can draw debug stuff in any other step etc
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


        _update();
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
        //collision loop over here?
        _render();

        //swap colorbuffer to screen
        _window->display();
        //_hud = new DebugHud(_window);
        if(DialogIsFinish)
        {
            std::string nextState = World::GetInstance()->nextState;
            _luaLoader->SetNewState(nextState);
            DialogIsFinish = false;
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
            //case sf::Event::MouseWheelMoved:
                //if (event.type == sf::Event::MouseWheelMoved)
                //{
                    //mouse_wheel = event.mouseWheel.delta;
                    //_scrollers->setLocalPosition(glm::vec3(_scrollers->getLocalPosition().x, _scrollers->getLocalPosition().y + event.mouseWheel.delta, _scrollers->getLocalPosition().z));
                    //std::cout << "Mouse wheel moved by: " << event.mouseWheel.delta << std::endl;
                //}
                //break;

            default:
                break;
        }
	}

	if (exit) {
        _window->close();
        _running = false;
	}
}



