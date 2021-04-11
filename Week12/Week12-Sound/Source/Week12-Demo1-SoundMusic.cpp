#include "Windows.h"  //for sleep function
#include <SFML/Audio.hpp>

int main()
{

    sf::Music music;
    if (!music.openFromFile("Media/Music/MissionTheme.ogg"))
        return -1; // error
    music.setVolume(10.f);
    music.setLoop(true);
    music.play();


    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Media/Sound/Explosion1.wav"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50.f);
    sound.setLoop(true);
    sound.play();
    Sleep(50000);
    return 0;
}