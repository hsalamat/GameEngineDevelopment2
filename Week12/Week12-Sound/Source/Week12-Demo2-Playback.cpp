#include "Windows.h"  //for sleep function
#include <SFML/Audio.hpp>

int main()
{

    //sf::Music music;
    //if (!music.openFromFile("Media/Music/MissionTheme.ogg"))
    //    return -1; // error
    //music.setVolume(10.f);
    //music.setLoop(true);
    //music.play();


    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Media/Music/MissionTheme.ogg"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50.f); //The value ranges from 0 (mute)to 100 (full volume).
    sound.setPitch(1); //greater than 1 plays the sound at a higher pitch 
    sound.setLoop(true); //whether the sound/music automatically loops or not
    sound.play();
    // advance to 2 seconds
    sound.setPlayingOffset(sf::seconds(2.f));

    Sleep(5000);

    // pause playback
    sound.pause();

    Sleep(5000);
    // resume playback
    sound.play();

    Sleep(5000);
    // stop playback and rewind
    sound.stop();
    Sleep(50000);
    return 0;
}