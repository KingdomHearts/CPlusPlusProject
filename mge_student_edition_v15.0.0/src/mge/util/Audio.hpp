#ifndef AUDIO_H
#define AUDIO_H
#include <SFML/Audio.hpp>
#include <vector>

class Audio
{
    public:
        Audio(std::string pFilename, int pLayer = 0);
        Audio(std::vector<std::string> pListFilenames);
        void SetLoop(bool pSetLoop);
        void SetPosition(sf::Vector3f pPosition);
        void SetMinDistance(float pMinDistance);
        void SetAttenuation(float pAttenuation);
        virtual ~Audio();
    protected:
    private:
    sf::SoundBuffer _audioBuffer;
    sf::Sound _sound;
    sf::Music _music;
};

#endif // AUDIO_H
