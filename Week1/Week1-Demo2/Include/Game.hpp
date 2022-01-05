#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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
	sf::CircleShape			mPlayer;
	sf::Sprite				mBackground;
	sf::Texture				mTexture;

#pragma region Step 1
	//Set the Icon
	sf::Image mIcon;

	//Create a graphical text to display
	sf::Font mFont;
	sf::Text mText;

	sf::Music mMusic;
#pragma endregion

};