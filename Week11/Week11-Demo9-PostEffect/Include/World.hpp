#pragma once

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SceneNode.hpp>
#include <SpriteNode.hpp>
#include <Aircraft.hpp>
#include <CommandQueue.hpp>
#include <Command.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>

#pragma region step 3 - 1
#include <PostEffect.hpp>
#include <SFML/Graphics/Shader.hpp>
// Forward declaration
namespace sf
{
	class RenderTarget;
}



//// Forward declaration
//namespace sf
//{
//	class RenderWindow;
//}
#pragma endregion
class World : private sf::NonCopyable
{
	public:
#pragma region step 3 - 2
		//explicit							World(sf::RenderWindow& window, FontHolder& fonts);
		explicit							World(sf::RenderTarget& outputTarget, FontHolder& fonts);
#pragma endregion
		void								update(sf::Time dt);
		void								draw();
		
		CommandQueue&						getCommandQueue();

		bool 								hasAlivePlayer() const;
		bool 								hasPlayerReachedEnd() const;


	private:
		void								loadTextures();
		void								adaptPlayerPosition();
		void								adaptPlayerVelocity();
		void								handleCollisions();
		
		void								buildScene();
		void								addEnemies();
		void								addEnemy(Aircraft::Type type, float relX, float relY);
		void								spawnEnemies();
		void								destroyEntitiesOutsideView();
		void								guideMissiles();
		sf::FloatRect						getViewBounds() const;
		sf::FloatRect						getBattlefieldBounds() const;


	private:
		enum Layer
		{
			Background,
			LowerAir,
			UpperAir,
			LayerCount
		};

		struct SpawnPoint 
		{
			SpawnPoint(Aircraft::Type type, float x, float y)
			: type(type)
			, x(x)
			, y(y)
			{
			}

			Aircraft::Type type;
			float x;
			float y;
		};


	private:
#pragma region step 3 - 2
		sf::RenderTarget&					mTarget;
		sf::RenderTexture					mSceneTexture;
		PostEffect							mPostEffect;
		ShaderHolder		mShaders;
		//sf::RenderWindow&					mWindow;

#pragma endregion


		sf::View							mWorldView;
		TextureHolder						mTextures;
		FontHolder&							mFonts;

		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;
		CommandQueue						mCommandQueue;

		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;
		Aircraft*							mPlayerAircraft;

		std::vector<SpawnPoint>				mEnemySpawnPoints;
		std::vector<Aircraft*>				mActiveEnemies;
};


