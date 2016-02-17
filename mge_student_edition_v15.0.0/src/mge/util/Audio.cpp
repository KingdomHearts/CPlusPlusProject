#include "Audio.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <vector>

Audio::Audio(std::string pFilename, int pLayer)
{
    if(pLayer == 0)
    {
        if(!_audioBuffer.loadFromFile(pFilename))
        {
            std::cout << "Something goes wrong" << std::endl;
            //something is wrong
        }
        else
        {
            std::cout << "It should work" << std::endl;

            std::cout << _audioBuffer.getChannelCount() << std::endl;
            //file is loaded
        }
        _sound.setBuffer(_audioBuffer);
        //_sound.play();
    }
    else if (pLayer == 1)
    {
        if(!_music.openFromFile(pFilename))
        {
            std::cout << "Something goes wrong" << std::endl;
            //something is wrong
        }
        else
        {
            std::cout << "It should work" << std::endl;
            //file is loaded
        }
        //_sound.setBuffer(_audioBuffer);
        _music.play();
    }
    //ctor
}

Audio::Audio(std::vector<std::string> pListFilenames)
{
    std::string pFilename;
    for(int i=0; i < pListFilenames.size();i++)
    {
        pFilename = pListFilenames[i];
        if(!_audioBuffer.loadFromFile(pFilename))
        {
            std::cout << "Something goes wrong" << std::endl;
            //something is wrong
        }
        else
        {
            std::cout << "It should work" << std::endl;
            //file is loaded
            Audio * audio = new Audio(pFilename);

        }
       // _sound.setBuffer(_audioBuffer);
       // _sound.play();
    }

}
void Audio::SetLoop(bool pSetLoop)
{
    _sound.setLoop(pSetLoop);
}

void Audio::SetPosition(sf::Vector3f pPosition)
{
    //sf::Listener::setPosition(50,0,0);
    sf::Listener::setGlobalVolume(100.f);
    //sf::Listener::setGlobalVolume(50.f);
    _sound.setPosition(pPosition);
    //_sound.setRelativeToListener(true);
    //_sound.setMinDistance(0.f);
    //_sound.setAttenuation(10.f);
    _sound.setMinDistance(1.0f);

    _sound.setAttenuation(10.f);
    _sound.play();
}

void Audio::SetListener(sf::Vector3f pPosition)
{
    sf::Listener::setPosition(pPosition);
}

Audio::~Audio()
{
    //dtor
}
