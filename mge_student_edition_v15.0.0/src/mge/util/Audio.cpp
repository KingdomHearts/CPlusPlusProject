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
    sf::Listener::setGlobalVolume(100.f);
    _sound.setPosition(pPosition);
    _sound.play();
}

/**
The minimum distance is the distance under which the sound will be heard at its maximum volume.
As an example, louder sounds such as explosions should have a higher minimum distance to ensure
that they will be heard from far away. Please note that a minimum distance of 0
(the sound is inside the head of the listener!) would lead to an incorrect spatialization and
result in a non-attenuated sound. 0 is an invalid value, never use it.
**/
void Audio::SetMinDistance(float pMinDistance = 1.0f)
{
    _sound.setMinDistance(pMinDistance);
}
/**
The attenuation is a multiplicative factor.
The greater the attenuation, the less it will be heard when the sound moves away from the listener.
To get a non-attenuated sound, you can use 0.
On the other hand, using a value like 100 will highly attenuate the sound,
which means that it will be heard only if very close to the listener.
**/
void Audio::SetAttenuation(float pAttenuation = 10.0f)
{
    _sound.setAttenuation(pAttenuation);
}


Audio::~Audio()
{
    //dtor
}
