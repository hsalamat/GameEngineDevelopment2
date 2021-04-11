//In addition to its position, you can define the listener's orientation:

#include "Windows.h"  //for sleep function
#include <SFML/Audio.hpp>

int main()
{

    //First, you can set the listener's position in the scene:
    //If you have a 2D world you can just use the same Y value everywhere, usually 0.
    sf::Listener::setPosition(0.f, 0.f, 0.f);    

    //Here, the listener is oriented along the +X axis. 
    //This means that, for example, a sound emitted at (15, 0, 5) will be heard from the right speaker.
    sf::Listener::setDirection(1.f, 0.f, 0.f);

    //The "up" vector of the listener is set to (0, 1, 0) by default, in other words, 
    //the top of the listener's head is pointing towards +Y. You can change the "up" vector if you want. It is rarely necessary though.
    //This corresponds to the listener tilting their head towards the right(+X).
    sf::Listener::setUpVector(1.f, 1.f, 0.f);

    //the listener can adjust the global volume of the scene :
    sf::Listener::setGlobalVolume(50.f);

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