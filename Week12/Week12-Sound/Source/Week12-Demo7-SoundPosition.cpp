//Every audio source provided by SFML (sounds, music, streams) defines the same properties for spatialization.

#include "Windows.h"  //for sleep function
#include <SFML/Audio.hpp>

int main()
{

    //First, you can set the listener's position in the scene:
    //If you have a 2D world you can just use the same Y value everywhere, usually 0.
    sf::Listener::setPosition(0.f, 0.f, 0.f);    

    //Here, the listener is oriented along the -Z axis toward the front. 
    sf::Listener::setDirection(0.f, 0.f, -1.f);

    //The "up" vector of the listener is set to (0, 1, 0) by default, in other words, 
    //the top of the listener's head is pointing towards +Y. You can change the "up" vector if you want. It is rarely necessary though.
    sf::Listener::setUpVector(0.f, 1.f, 0.f);

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

    //the sound is coming from right
    sound.setPosition(2.f, 0.f, -5.f);

    //what happens if the listener turns right?
    //sf::Listener::setDirection(1.f, 0.f, 0.f);
    
    //This position is absolute by default, but it can be relative to the listener if needed.
    //This can be useful for sounds emitted by the listener itself (like a gun shot, or foot steps). 
    //It also has the interesting side-effect of disabling spatialization if you set the position of the audio source to (0, 0, 0). 
    //Non-spatialized sounds can be required in various situations: GUI sounds (clicks), ambient music, etc.
    //sound.setRelativeToListener(true);


    //You can also set the factor by which audio sources will be attenuated depending on their distance to the listener.

    //The minimum distance is the distance under which the sound will be heard at its maximum volume.
    sound.setMinDistance(5.f);

    //The attenuation is a multiplicative factor.The greater the attenuation, 
    //the less it will be heard when the sound moves away from the listener.
    //To get a non - attenuated sound, you can use 0. 
    //On the other hand, using a value like 100 will highly attenuate the sound, 
    //which means that it will be heard only if very close to the listener.
    sound.setAttenuation(10.f);

    sound.play();
    
    Sleep(50000);
    return 0;
}