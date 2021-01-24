#pragma once

#pragma region step 10
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SceneNode.hpp>
#include <SpriteNode.hpp>
#include <Aircraft.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#pragma endregion

class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();

private:
	void					processEvents();
	void					update(sf::Time elapsedTime);
	void					render();

	void					updateStatistics(sf::Time elapsedTime);

private:
	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;

	sf::View				mView;
	sf::FloatRect			mWorldBounds;
	sf::Vector2f			mSpawnPosition;
	float					mScrollSpeed;
	std::size_t				mStatisticsNumFrames;


#pragma region step 11
	/*
	sf::Texture				mTexture;
	sf::Sprite				mPlayer;
	sf::Sprite				landscape;
	sf::Sprite				airplane;

	class Player player;
	class Player2 player2; */

	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

	TextureHolder						mTextures;
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	Aircraft*							mPlayerAircraft;

	void								loadTextures();
	void								buildScene();
#pragma endregion

};


