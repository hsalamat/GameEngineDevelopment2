//To get your sprite object drawn that is in the player class from the 
//main game loop inside of your main.cpp file you can do it one of two ways 
//(There are more but these are the easiest).
//A.) Provide a get function that returns a reference to the sf::Sprite object in your player class.
//B) Look at Player2.hpp!

#include "Player.hpp"

Player::Player()
{

	if (!texture2.loadFromFile("Media/Textures/Eagle.png"))
	{
		// Handle loading error
	}

	mSprite.setTexture(texture2);
	mSprite.setPosition(200.f, 200.f);
}

sf::Sprite& Player::getSprite()
{
	return mSprite;
}