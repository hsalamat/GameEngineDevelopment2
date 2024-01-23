#pragma once
#include <SFML/Graphics.hpp>


class Game2 : private sf::NonCopyable
{
public:
	Game2();
	void					run();


private:
	void					processEvents();
	void					update();
	void					render();


private:

	sf::RenderWindow		mWindow;
	sf::CircleShape				mPlayer;
	sf::RectangleShape				mPlayer2;
};
