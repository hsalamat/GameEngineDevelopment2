#include <Game.hpp>
#include <Utility.hpp>
#include <State.hpp>
#include <StateIdentifiers.hpp>
#include <TitleState.hpp>


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "TilteState", sf::Style::Close)
#pragma region 14
	//	, mWorld(mWindow)
	//, mFont()
#pragma endregion	
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mFonts()
	, mPlayer()
	, mTextures()
	, mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
{

#pragma region 15
	//If key repeat is enabled, you will receive repeated KeyPressed events while keeping a key pressed. If it is disabled, you will only get a single event when the key is pressed. Key repeat is enabled by default
	mWindow.setKeyRepeatEnabled(false);

	mFonts.load(Fonts::Main, "Media/Sansation.ttf");
	mTextures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");

	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10u);

	registerStates();
	mStateStack.pushState(States::Title);

#pragma endregion
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

#pragma region 16
			// Check inside this loop, because stack might be empty before update() call
		//	if (mStateStack.isEmpty())
		//		mWindow.close();
#pragma endregion

		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
#pragma region 17
	//CommandQueue& commands = mWorld.getCommandQueue();
#pragma endregion


	sf::Event event;
	while (mWindow.pollEvent(event))
	{
#pragma region 18
		mStateStack.handleEvent(event);
#pragma endregion
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}

#pragma region 19
		//	mPlayer.handleRealtimeInput(commands);
#pragma endregion

	}
}


void Game::update(sf::Time elapsedTime)
{
#pragma region 20
	mStateStack.update(elapsedTime);
#pragma endregion
}

void Game::render()
{
	mWindow.clear();

#pragma region 21
	mStateStack.draw();
#pragma endregion

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
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

#pragma region 22
void Game::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
}
#pragma endregion


