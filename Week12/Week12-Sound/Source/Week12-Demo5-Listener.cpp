//All the soundsand music in your audio environment will be heard by a single actor : the listener.
//What is output from your speakers is determined by what the listener hears.
//The class which defines the listener's properties is sf::Listener. 
//Since the listener is unique in the environment, this class only contains static functions and is not meant to be instantiated.


#include "Windows.h"  //for sleep function
#include <SFML/Audio.hpp>

int main()
{

    //First, you can set the listener's position in the scene:
    //If you have a 2D world you can just use the same Y value everywhere, usually 0.
    sf::Listener::setPosition(0.f, 0.f, 0.f);    
    //sf::Listener::setPosition(10.f, 0.f, 0.f);  //you should hear from your left  ear
    //sf::Listener::setPosition(-10.f, 0.f, 0.f);  //you should hear from your right  ear
    //sf::Listener::setPosition(0.f, 0.f, 100.f);  //you should hear the sound from far
    //sf::Listener::setPosition(0.f, 0.f, -100.f);  //you should hear the sound from far
    //sf::Listener::setPosition(0.f, -100.f, 0.f);  //you should hear the sound from far

    //sf::Music music;
    //if (!music.openFromFile("Media/Music/MissionTheme.ogg"))
    //    return -1; // error
    //music.setVolume(10.f);
    //music.setLoop(true);
    //music.play();




    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Media/Sound/Explosion1.wav"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100.f);
    sound.setLoop(true);
    sound.play();
    
    Sleep(50000);
    return 0;
}