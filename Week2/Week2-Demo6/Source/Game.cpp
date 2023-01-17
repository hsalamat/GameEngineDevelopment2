#include <Game.hpp>

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Bouncing Mushroom")
	, mushroomTexture()
	, mushroomSprite()
	, increment(0.4f, 0.4f)
{

	mushroomTexture.loadFromFile("Media/Textures/Mushroom.png");
	mushroomSprite.setTexture(mushroomTexture);
	mushroomSprite.setColor(sf::Color(0, 255, 0, 255)); // Green tint
	size = mushroomTexture.getSize();
	mushroomSprite.setOrigin(size.x / 2, size.y / 2);

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
	if ((mushroomSprite.getPosition().x + (size.x / 2) > mWindow.getSize().x && increment.x > 0) || (mushroomSprite.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
	{
		//Reverse the direction on X axis
		increment.x = -increment.x;
	}

	if ((mushroomSprite.getPosition().y + (size.y / 2) > mWindow.getSize().y && increment.y > 0) || (mushroomSprite.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
	{
		//Reverse the direction on X axis
		increment.y = -increment.y;
	}

	mushroomSprite.setPosition(mushroomSprite.getPosition() + increment);
}

void Game::render()
{
	mWindow.clear(sf::Color(16, 16, 16, 255)); //Dark gray
	mWindow.draw(mushroomSprite);
	mWindow.display();
}



