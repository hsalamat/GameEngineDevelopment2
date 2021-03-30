#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <StringHelpers.hpp>

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
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;

	std::size_t				mStatisticsNumFrames;

	sf::Shader shader;
	sf::Texture tex;
	sf::Sprite spr;
	
	const float winW = 800;
	const float winH = 600;
};

