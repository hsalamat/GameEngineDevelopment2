#pragma once
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <Command.hpp>
#include <TextNode.hpp>

#pragma region step 8 -1
#include <Projectile.hpp>
#pragma endregion


class Aircraft : public Entity
{
	public:
		enum Type
		{
			Eagle,
			Raptor,
			Avenger,
			TypeCount
		};

	public:
		Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);
		virtual unsigned int	getCategory() const;
		float					getMaxSpeed() const;

#pragma region step 8 - 2
		void 					fire();
		void					launchMissile();
		bool					isAllied() const;
	private:
		void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);

		void					createBullets(SceneNode& node, const TextureHolder& textures) const;
		void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
#pragma endregion


		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
		Type					mType;
		sf::Sprite				mSprite;
		TextNode*				mHealthDisplay;
		void					updateTexts();
		float					mTravelledDistance;
		std::size_t				mDirectionIndex;
		void					updateMovementPattern(sf::Time dt);

#pragma region step 8 - 3
		Command 				mFireCommand;
		Command					mMissileCommand;
		sf::Time				mFireCountdown;
		bool 					mIsFiring; //to avoid firing a projectile for every frame
		bool					mIsLaunchingMissile;
		bool 					mIsMarkedForRemoval;

		int						mFireRateLevel;
		int						mSpreadLevel;
		int						mMissileAmmo;

		TextNode*				mMissileDisplay;
#pragma endregion

};

