#include "Audio.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <vector>
#include "mge/core/World.hpp"

Audio::Audio(std::string pFilename, int pLayer)
{
    if(pFilename == "")
    {
        pLayer = 2;
    }
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
        _sound.play();
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
    else
    {

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

void Audio::SetVolume(float pVolume = 100.f)
{
    _sound.setVolume(pVolume);
}

void Audio::SetLoop(bool pSetLoop)
{
    _sound.setLoop(pSetLoop);
}

void Audio::PlaySound(std::string pFilename)
{
    if(World::GetInstance()->AudioList.size() != 0)
    {
        for (std::vector<AudioStruct>::iterator i = World::GetInstance()->AudioList.begin(); i != World::GetInstance()->AudioList.end(); ++i)
        {
            if(i->sFileName == pFilename)
            {
                Audio * audio = new Audio("mge/sounds/"+i->sFileName, i->sLayer);
                audio->SetLoop(i->sLoop);
                audio->SetVolume(i->sSetVolume);
                if(i->sIs3D)
                {
                    audio->SetAttenuation(i->sSetAttenuation);
                    audio->SetMinDistance(i->sMinDistance);

                    std::string nestedString = i->sObject;
                    std::string splitter = ",";
                    size_t pos = 0;
                    std::string token;
                    std::vector<std::string> stringNumbers;
                    while ((pos = nestedString.find(splitter)) != std::string::npos)
                    {
                    token = nestedString.substr(0, pos);
                    nestedString.erase(0, pos + splitter.length());
                    stringNumbers.push_back(token);
                    }
                    stringNumbers.push_back(nestedString);

                    if(stringNumbers.size() == 3)
                    {
                        float x = std::stof(stringNumbers[0]);
                        float y = std::stof(stringNumbers[1]);
                        float z = std::stof(stringNumbers[2]);
                        audio->SetPosition(sf::Vector3f(x,y,z));

                    std::cout << "X: " << x << std::endl;
                    std::cout << "Y: " << y << std::endl;
                    std::cout << "Z: " << z << std::endl;
                    }


                    // Object for 3d position
                }
                cFileName = pFilename;
                _playingAudio.push_back(audio);
                std::cout << i->sFileName << std::endl;

            }

        }
    }
}

void Audio::StopSound(std::string pFilename)
{
    std::cout << _playingAudio.size() << std::endl;
    if(_playingAudio.size() != 0)
    {
        for (std::vector<Audio*>::iterator i = _playingAudio.begin(); i != _playingAudio.end(); i++)
        {
            Audio *playingAudio = *i;
            playingAudio->_sound.stop();
        }
    }
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
