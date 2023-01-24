#pragma once

#include <ResourceHolder.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceIdentifiers.hpp"
#include "Player.hpp"
#include "Player2.hpp"

class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();

private:
	void					processEvents();
	void					update(sf::Time elapsedTime);
	void					render();

	void					updateStatistics(sf::Time elapsedTime);
	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	sf::Texture				mTexture;
	sf::Sprite				mPlayer;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	sf::Sprite				landscape;
	sf::Sprite				airplane;

#pragma region step 3
	sf::View							mView;
	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
#pragma endregion

	TextureHolder textures;
	FontHolder fonts;

	class Player player;
	class Player2 player2;

	std::size_t				mStatisticsNumFrames;
	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;


};


