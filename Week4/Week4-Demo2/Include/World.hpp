#pragma once

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SceneNode.hpp>
#include <SpriteNode.hpp>
#include <Aircraft.hpp>
#pragma region step 12
#include <CommandQueue.hpp>
#include <Command.hpp>
#pragma endregion



#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
	public:
		explicit							World(sf::RenderWindow& window);
		void								update(sf::Time dt);
		void								draw();

#pragma region step 13

		CommandQueue&						getCommandQueue();
	private:
		CommandQueue						mCommandQueue;

#pragma endregion

		void								loadTextures();
		void								buildScene();


	private:
		enum Layer
		{
			Background,
			Air,
			LayerCount
		};


	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;
		TextureHolder						mTextures;

		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;

		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;
		Aircraft*							mPlayerAircraft;
};


