#include <Game.hpp>
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, vertices()
	, mTexture()
	, mVertexArray(sf::Quads)
	, mNeedsVertexUpdate(true)
	, mParticles()
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

	if (!mTexture.loadFromFile("Media/Textures/Particle.png"))
		return;


	mParticle.color = sf::Color(50, 50, 50);
	mParticle.lifetime = sf::seconds(10.f);
	mParticles.push_back(mParticle);

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}
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

void Game::update(sf::Time dt)
{
	mParticle.lifetime -= dt;
}

void Game::render()
{
	mWindow.clear();
	computeVertices();
	mWindow.draw(mVertexArray);
	mWindow.display();
}

void Game::computeVertices() const {
	//Determine the vertex positions more easily
	sf::Vector2f size(mTexture.getSize());
	sf::Vector2f half = size / 2.f;

	// Refill vertex array
	mVertexArray.clear();
	for (const Particle& particle : mParticles)
	{
		sf::Vector2f pos = sf::Vector2f(100.0f, 100.0f);
		sf::Color color = sf::Color(255, 255, 50);
		//Compute the ratio between the remaining and total lifetime - [0,1] --> [0, 255] sets the alpha value
		float ratio = mParticle.lifetime.asSeconds() / sf::seconds(10.f).asSeconds();		
		color.a = static_cast<sf::Uint8>(255 * std::max(ratio, 0.f));

		std::cout << mParticle.lifetime.asSeconds() << std::endl;
		if (mParticle.lifetime.asSeconds() < 0) exit(0);

		//We add four vertices for each particle, one in every corner of rectangle
		//the first two arguments denote the target coordinates, and the next two denote the texture coordinates
		addVertex(pos.x - half.x, pos.y - half.y, 0.f, 0.f, color);
		addVertex(pos.x + half.x, pos.y - half.y, size.x, 0.f, color);
		addVertex(pos.x + half.x, pos.y + half.y, size.x, size.y, color);
		addVertex(pos.x - half.x, pos.y + half.y, 0.f, size.y, color);
	}
}

void Game::addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const
{
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(worldX, worldY);
	vertex.texCoords = sf::Vector2f(texCoordX, texCoordY);
	vertex.color = color;

	mVertexArray.append(vertex);
}



