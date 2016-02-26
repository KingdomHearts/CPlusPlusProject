#include "AbstractGame.hpp"

#include <iostream>
using namespace std;

#include "mge/core/Timer.hpp"
#include "mge/core/FPS.hpp"
#include "mge/core/Renderer.hpp"
#include "mge/core/World.hpp"

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


bool doorIsClosed = true;

/**
int WaitForDoorToOpen(lua_State * lua) {

    int count = 0;
    while(doorIsClosed) {
        count ++;
        cout << count << " door closed ! \n";
        sf::sleep(sf::milliseconds(1000));
    }

    return 0;
}

**/
bool DialogIsFinish = false;
 void DialogThread(DebugHud * hud)
{
    int count = 0;
        while(true)
        {
            if(World::GetInstance()->DialogNumberList.size() > 0)
            {
                while(World::GetInstance()->DialogNumberList.size() > 0)
                {
                    int j = World::GetInstance()->DialogNumberList.at(0);
                    for(std::vector<DialogStruct>::iterator i =  World::GetInstance()->dialogList->begin(); i != World::GetInstance()->dialogList->end();i++)
                    {
                        if(i->sDialogNumber == j)
                        {
                            //std::cout << i->sDialogNumber << std::endl;
                            World::GetInstance()->displayText = i->sText;
                            std::cout << i->sText << std::endl;
                            World::GetInstance()->dialogList->erase(i);
                            World::GetInstance()->DialogNumberList.erase(World::GetInstance()->DialogNumberList.begin(),World::GetInstance()->DialogNumberList.begin()+1);
                            if(World::GetInstance()->waitTimesList.size() > 0)
                            {
                                int seconds = World::GetInstance()->waitTimesList.at(0);
                                sf::sleep(sf::milliseconds(seconds*1000));
                                World::GetInstance()->waitTimesList.erase(World::GetInstance()->waitTimesList.begin(),World::GetInstance()->waitTimesList.begin()+1);
                            }
                            //std::cout << World::GetInstance()->DialogNumberList.size() << std::endl;
                            //World::GetInstance()->waitTimesList.erase(World::GetInstance()->waitTimesList.begin());

                        }
                    }
                }
            }
            if(World::GetInstance()->state == "")
            {
                DialogIsFinish = true;
            }
        }

}
///LOOP

void AbstractGame::run()
{
    sf::Thread myThread(&DialogThread,_hud);
    myThread.launch();
	_running = true;

    _luaLoader = new LuaLoader("","");

    int Count = 0;

	while (_running) {

		Timer::update();
		FPS::update();
	    //clear frame, do it here so we can draw debug stuff in any other step etc
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        //    doorIsClosed = false;
		//}


        _update();
        if(World::GetInstance() != NULL && Count == 0)
        {
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



