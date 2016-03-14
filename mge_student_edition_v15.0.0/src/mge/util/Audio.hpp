#ifndef AUDIO_H
#define AUDIO_H
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>


//namespace AudioNamespace
//{
    struct AudioStruct
    {
        std::string sID;
        std::string sFileName;
        int sLayer;
        bool sLoop;
        std::string sTrigger = "NULL";
        float sSetVolume = 10.f;
        bool sIs3D = false;
        float sMinDistance = 1.f;
        float sSetAttenuation = 10.f;
        std::string sObject = "NULL";
    };

    class Audio
    {

        public:
            std::string cFileName;
            Audio(std::string pFilename, int pLayer = 0);
            Audio(std::vector<std::string> pListFilenames);
            void SetVolume(float pVolume);
            void SetLoop(bool pSetLoop);
            void PlaySound(std::string pFilename);
            void StopSound(std::string pFilename);
            void SetPosition(sf::Vector3f pPosition);
            void SetMinDistance(float pMinDistance);
            void SetAttenuation(float pAttenuation);
        protected:
        private:
        sf::SoundBuffer _audioBuffer;
        sf::Sound _sound;
        sf::Music _music;
        std::vector<Audio*> _playingAudio;
    };
//};
#endif // AUDIO_H
