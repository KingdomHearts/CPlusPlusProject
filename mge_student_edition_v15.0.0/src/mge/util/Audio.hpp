#ifndef AUDIO_H
#define AUDIO_H
#include <SFML/Audio.hpp>

class Audio
{
    public:
        Audio(std::string pFilename);
        virtual ~Audio();
        void PlayAudio(std::string pFilename);
    protected:
    private:
    sf::SoundBuffer _audioBuffer;
    sf::Sound _sound;
};

#endif // AUDIO_H
