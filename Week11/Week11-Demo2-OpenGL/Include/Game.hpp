#pragma once

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();


private:
	void					processEvents();
	void					update();
	void					render();


private:

	sf::RenderWindow		mWindow;
	sf::Vertex v1, v2, v3, v4;
	sf::VertexArray vertices;
};

