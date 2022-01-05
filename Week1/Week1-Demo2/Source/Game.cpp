#include "Game.hpp"


Game::Game()
#pragma region Step2
	: mWindow(sf::VideoMode(800, 600), "SFML Application", sf::Style::Close)
	, mTexture()
	, mBackground()
	, mPlayer()
	, mMusic()
	, mFont()
	, mIcon()
#pragma endregion

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);

#pragma region step3


	mIcon.loadFromFile("Media/Textures/icon.png");
	mWindow.setIcon(mIcon.getSize().x, mIcon.getSize().y, mIcon.getPixelsPtr());

	//Load a sprite to display
	if (!mTexture.loadFromFile("Media/Textures/cute_image.jpg"))
		return;
	mBackground.setTexture(mTexture);

	if (!mFont.loadFromFile("Media/Sansation.ttf"))
		return;


	mText.setString("Hello SFML");
	mText.setFont(mFont);
	mText.setPosition(5.f, 5.f);
	mText.setCharacterSize(50);
	mText.setFillColor(sf::Color::Black);

	//mText.setRotation(45);


	mMusic.openFromFile("Media/Sound/nice_music.ogg");
	//Play the music
	mMusic.play();

#pragma endregion

}

void Game::run()
{

	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	mWindow.clear();

#pragma region Step4

	mWindow.draw(mBackground);
	//Draw the string
	mWindow.draw(mText);
#pragma endregion

	//Update the window
	mWindow.display();
}

