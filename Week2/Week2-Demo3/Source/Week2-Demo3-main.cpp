/** @file Week2-Demo3-main.cpp
 *  @brief change Music parameters, create your own image and move the player with the mouse Demo
 *	mMusic.setPosition(0, 0, 0); //! @param setPosition: change its 3D position - the default position is (0,0,0)
 *	mMusic.setPitch(2); //! @param setPitch: increase the pitch - pitch represents the perceived fundamental frequency of a sound such as modifying the playing speed of the sound
 *	mMusic.setVolume(50); //! @param setVolume: reduce the volume
 *	mMusic.setAttenuation(100); //! @param setAttenuation: an attenuation value of 100 will make the sound fade out very quicky as it gets further from the listener - default value is 1
 *	mMusic.setLoop(true); //! @param setLoop: make it loop
 *
 *  Move the player with the mouse:
 *  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
 *		sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);
 *		mPlayer.setPosition((float)mousePosition.x, (float)mousePosition.y);
 *	}
 * 
 *  You could also create your own image
 *	mIcon.create(20, 20, sf::Color::Red);
 *	sf::Color color = mIcon.getPixel(0, 0);
 *  color.a = 0; //make the top-left pixel transparent
 *	color.r = 0;   //set the r = 0 (rgb) from the color
 *	mIcon.setPixel(0, 0, color);
 * 
 *  @attention: the sf::Texture::loadFromX() functions are just a shortcut for combined sf::Image::loadFromX() and
 *  sf::Texture::loadFromImage() calls.
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */ 
#include "Game.hpp"

int main()
{
	Game game;
	game.run();

}