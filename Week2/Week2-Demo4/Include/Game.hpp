#pragma once

#include <SFML/Graphics.hpp>
#include <TextureHolder.hpp>
#include <iostream>

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
		bool					mIsMovingUp;
		bool					mIsMovingDown;
		bool					mIsMovingRight;
		bool					mIsMovingLeft;

		//step 1
		//sf::Texture				mTexture;
		//sf::Sprite				mPlayer;
		TextureHolder			textures;
		sf::Sprite				airplane;
		sf::Sprite				landscape;
		sf::Texture             mBackgroundTexture;
		sf::Texture             mAirplaneTexture;
};

