#include <Game.hpp>
#include <StringHelpers.hpp>

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Input Handling", sf::Style::Close)
	, landscape()
	, airplane()
	, textures()
	, mTexture()
	, mPlayer()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)

#pragma region step 2 
	//, mIsMovingUp(false)
	//, mIsMovingDown(false)
	//, mIsMovingRight(false)
	//, mIsMovingLeft(false)
#pragma endregion

	, mView(mWindow.getDefaultView())
	, mWorldBounds(0.f, 0.f, mView.getSize().x, 4000.f)
	, mSpawnPosition(mView.getSize().x / 2.f, mWorldBounds.height - mView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
{
	mView.setCenter(mSpawnPosition);
	mWindow.setFramerateLimit(20);
	try
	{
		textures.load(Textures::Landscape, "Media/Textures/Desert.png");
		textures.load(Textures::Airplane, "Media/Textures/Eagle.png");
		mFont.loadFromFile("Media/Sansation.ttf");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// Prepare the tiled background
	sf::Texture& texture = textures.get(Textures::Landscape);
	texture.setRepeated(true);
	landscape.setTexture(texture);
	landscape.setTextureRect(sf::IntRect(mWorldBounds));

	landscape.setPosition(mWorldBounds.left, mWorldBounds.top);
	player2.setPosition(mSpawnPosition);
	player2.setVelocity(0.f, mScrollSpeed);

	airplane.setTexture(textures.get(Textures::Airplane));
	airplane.setPosition(200.f, 200.f);

	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
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
#pragma region step3

		/*case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;*/

#pragma endregion

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	// Scroll the world
	mView.move(0.f, mScrollSpeed * elapsedTime.asSeconds());
	sf::Vector2f position = player2.getPosition();
	sf::Vector2f velocity = player2.getVelocity();

	player2.setVelocity(0.f, -30.f);
	// Apply movements
	player2.update(elapsedTime);

	sf::Vector2f movement(0.f, 0.f);

#pragma region step 4

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		movement.y -= PlayerSpeed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		movement.y += PlayerSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= PlayerSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += PlayerSpeed;

#pragma endregion

	airplane.move(movement * elapsedTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();

	mWindow.setView(mView);
	mWindow.draw(landscape);

	mWindow.setView(mWindow.getDefaultView());

	mWindow.draw(airplane);
	mWindow.draw(player.getSprite());
	mWindow.draw(player2);
	mWindow.draw(mStatisticsText);

#pragma endregion

	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

#pragma region step 5

/*
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;

	if (key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		mIsMovingRight = isPressed;
}*/

#pragma endregion




