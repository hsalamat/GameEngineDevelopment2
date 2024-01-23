#include "Game2.hpp"


Game2::Game2()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mPlayer()
	, mPlayer2(sf::Vector2f(100.0f, 100.0f))

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);

	mPlayer2.setPosition(200.f, 200.f);
	mPlayer2.setFillColor(sf::Color::Yellow);
}


void Game2::run()
{

	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game2::processEvents()
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

void Game2::update()
{
}

void Game2::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.draw(mPlayer2);
	mWindow.display();
}


