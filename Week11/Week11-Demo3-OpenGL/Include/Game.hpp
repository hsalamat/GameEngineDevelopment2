#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream>

class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();


	struct Particle
	{
		enum Type
		{
			Propellant,
			Smoke,
			ParticleCount
		};

		sf::Vector2f	position;
		sf::Color		color;
		sf::Time		lifetime;
	};
	

private:
	static const sf::Time	TimePerFrame;
	void					processEvents();
	void				    update(sf::Time dt);
	void					render();

	void					computeVertices() const;
	void					addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;

private:

	sf::RenderWindow		mWindow;
	sf::Vertex v1, v2, v3, v4;
	sf::VertexArray vertices;

	std::deque<Particle>	mParticles;
	Particle::Type			mType;
	Particle mParticle;

	sf::Texture mTexture;
	mutable					sf::VertexArray mVertexArray;
	mutable bool			mNeedsVertexUpdate;
};

