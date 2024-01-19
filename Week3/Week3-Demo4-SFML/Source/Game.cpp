#include <Game.hpp>

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Entity", sf::Style::Close)
	, landscape()
	, airplane()
	, textures()
	, mTexture()
	, mPlayer()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
	, mView(mWindow.getDefaultView())
	, mWorldBounds(0.f, 0.f, mView.getSize().x, 4000.f)
	, mSpawnPosition(mView.getSize().x / 2.f, mWorldBounds.height - mView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
{
	mView.setCenter(mSpawnPosition);

	//Limit the framerate to a maximum fixed frequency.
	mWindow.setFramerateLimit(20);

	//Activating vertical synchronization will limit the number of frames displayed to the refresh rate of the monitor. This can avoid some visual artifacts, and limit the framerate to a good value (but not constant across different computers).
	mWindow.setVerticalSyncEnabled(true);
	try
	{
		textures.load(TextureID::Landscape, "Media/Textures/Desert.png");
		textures.load(TextureID::Airplane, "Media/Textures/Eagle.png");
		fonts.load(FontID::sansation, "Media/Sansation.ttf");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// Prepare the tiled background
	sf::Texture& texture = textures.get(TextureID::Landscape);
	texture.setRepeated(true);
	landscape.setTexture(texture);
	landscape.setTextureRect(sf::IntRect(mWorldBounds));

#pragma region step3
	landscape.setPosition(mWorldBounds.left, mWorldBounds.top);
	player2.setPosition(mSpawnPosition);
	player2.setVelocity(40.f, mScrollSpeed);

#pragma endregion

	//let's change the zoom to 0.2 or 2. sf::View::zoom(float factor) function to easily approach or moveaway from the center of the view
	//mView.zoom(0.2);

	//sf::View::rotate(float degree) to add a rotation angle to the current one sf::View::setRotation(float degrees) to set the rotation of the view to an absolute value
	//mView.rotate(45);

	airplane.setTexture(textures.get(TextureID::Airplane));
	airplane.setPosition(200.f, 200.f);

	mStatisticsText.setFont(fonts.get(FontID::sansation));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
	mStatisticsText.setFillColor(sf::Color::Black);

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
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

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

#pragma region step 4
	sf::Vector2f position = player2.getPosition();
	sf::Vector2f velocity = player2.getVelocity();

	// If player touches borders, flip its X velocity
	//if (position.x <= mWorldBounds.left + 150.f
	//	|| position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	//{
	//	velocity.x = -velocity.x;
	//	player2.setVelocity(velocity);
	//}


	velocity.x -= 1;
	velocity.y -= .1;
	player2.setVelocity(velocity);
	// Apply movements
	player2.update(elapsedTime);

#pragma endregion

	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

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

	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	sf::Vector2f position = player2.getPosition();
	sf::Vector2f velocity = player2.getVelocity();

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us" + "\n" +
			"Position = ( " + std::to_string(position.x) + " , " + std::to_string(position.y) + " )" + "\n" +
			"Velocity = ( " + std::to_string(velocity.x) + " , " + std::to_string(velocity.y) + " )" + "\n"
		);

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

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
}






