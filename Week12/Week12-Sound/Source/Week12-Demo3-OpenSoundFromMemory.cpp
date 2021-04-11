#include "Windows.h"  //for sleep function
#include <SFML/Audio.hpp>

int main()
{

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Media/Sound/Explosion1.wav"))
        return -1;

    // You can also load a sound buffer directly from an array of samples, in the case they originate from another source:

    sf::SoundBuffer buffer2;
    const sf::Int16* samples = buffer.getSamples();
    int fileSize = buffer.getSampleCount();

    buffer2.loadFromSamples(&samples[0], fileSize, 1, 44100);

    sf::Sound sound;
    sound.setBuffer(buffer2);
    sound.setVolume(50.f);
    sound.setLoop(true);
    sound.play();

    Sleep(50000);
    return 0;
}




