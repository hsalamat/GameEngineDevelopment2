/** @file Week3-Demo2-main.cpp
 *  @brief Adding ResourceIdentifiers and Player inheriting from sf::Transformable & sf::Drawable
 *  SFML provides an API to work with position, rotation, and scale in the class
 *  sf::Transformable. The class stores the three transforms separately and provides
 *  useful accessor functions such as setPosition(), move(), rotate(), getScale(),and many more.
 *  SFML provides another useful base class for graphical entities: the class
 *	sf::Drawable is a stateless interface and provides only a pure virtual function with
 *	the following signature:
 *	virtual void Drawable::draw(sf::RenderTarget& target,sf::RenderStates states) const = 0
 *  The first parameter specifies, where the drawable object is drawn to. Mostly, this
 *	will be a sf::RenderWindow. The second parameter contains additional information
 *  for the rendering process, such as blend mode, transform, the used texture, or
 *  shader. SFML's high-level classes Sprite, Text, and Shape are all derived from
 *  Transformable and Drawable.
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