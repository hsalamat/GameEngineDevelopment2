#include "Game.hpp"


Game::Game()
	: mWindow(sf::VideoMode({ 640, 480 }), "SFML Application")
	, mPlayer()

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition({ 100.f, 100.f });
	mPlayer.setFillColor(sf::Color::Cyan);
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
	while (const std::optional event = mWindow.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			mWindow.close();				
	}
}

void Game::update()
{
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}



