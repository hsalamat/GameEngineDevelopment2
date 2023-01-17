#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>

//This class makes its instances non-copyable, by explicitly disabling its copy constructor and its assignment operator.
class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();


private:
	void					processEvents();
	void					update();
	void					render();


private:

	sf::RenderWindow		mWindow;
	sf::Texture				mushroomTexture;
	sf::Sprite				mushroomSprite;
	sf::Vector2u			size;
	sf::Vector2f			increment;
};

#endif // BOOK_GAME_HPP
