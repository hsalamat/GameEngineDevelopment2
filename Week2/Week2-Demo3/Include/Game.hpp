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
#pragma region step 1-1
	void					update(sf::Time elapsedTime);
#pragma endregion
	void					render();

#pragma region step1

	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
#pragma endregion

private:
#pragma region Step 1-2
	static const float		PlayerSpeed;
#pragma endregion
	sf::RenderWindow		mWindow;
	sf::Sprite				mPlayer;
	sf::Sprite				mBackground;
	sf::Texture				mTexture;
	sf::Texture				mAirplaneTexture;
	sf::Image				mIcon;

	//Create a graphical text to display
	sf::Font mFont;
	sf::Text mText;

	sf::Music mMusic;

#pragma region step2

	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;
#pragma endregion
};