#include "Audio.hpp"
#include <iostream>
#include <SFML/Audio.hpp>

Audio::Audio(std::string pFilename)
{

    //ctor
}

void Audio::PlayAudio(std::string pFilename)
{
    if(!_audioBuffer.loadFromFile(pFilename))
    {
        std::cout << "Something goes wrong" << std::endl;
        //something is wrong
    }
    else
    {
        std::cout << "It should work" << std::endl;
        //file is loaded
    }
    _sound.setBuffer(_audioBuffer);
    _sound.play();
}

Audio::~Audio()
{
    //dtor
}
