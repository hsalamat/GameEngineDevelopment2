#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include <iostream>

namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
	};
}

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

#pragma region step 3
	    //TextureHolder			 textures;
		ResourceHolder<sf::Texture, Textures::ID> textures;
#pragma endregion

		sf::Sprite				airplane;
		sf::Sprite				landscape;
		sf::Texture             mBackgroundTexture;


};

#endif // BOOK_GAME_HPP
