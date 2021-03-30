#include <Game.hpp>


Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, vertices()
{
	v1.position = sf::Vector2f(100.0f, 100.0f);
	v1.texCoords = sf::Vector2f(100.0f, 100.0f);
	v1.color = sf::Color::Blue;

	v2.position = sf::Vector2f(200.0f, 100.0f);
	v2.texCoords = sf::Vector2f(200.0f, 100.0f);
	v2.color = sf::Color::Red;

	v3.position = sf::Vector2f(200.0f, 200.0f);
	v3.texCoords = sf::Vector2f(200.0f, 200.0f);
	v3.color = sf::Color::Green;

	v4.position = sf::Vector2f(100.0f, 200.0f);
	v4.texCoords = sf::Vector2f(100.0f, 200.0f);
	v4.color = sf::Color::Yellow;

	vertices.setPrimitiveType(sf::Quads);
	vertices.append(v1);
	vertices.append(v2);
	vertices.append(v3);
	vertices.append(v4);

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
	mWindow.draw(vertices);
	mWindow.display();
}



