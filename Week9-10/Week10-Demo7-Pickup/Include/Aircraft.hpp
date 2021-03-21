#pragma once

#include <Entity.hpp>
#include <Command.hpp>
#include <ResourceIdentifiers.hpp>
#include <Projectile.hpp>
#include <TextNode.hpp>

#include <SFML/Graphics/Sprite.hpp>


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

		bool					isAllied() const;
		float					getMaxSpeed() const;

		void 					fire();
		void					launchMissile();

#pragma region step 6
		void					increaseFireRate();
		void					increaseSpread();
		void					collectMissiles(unsigned int count);
#pragma endregion


	private:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
		void					updateMovementPattern(sf::Time dt);
		void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);
		void					createBullets(SceneNode& node, const TextureHolder& textures) const;
		void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;

#pragma region step 7
		void					createPickup(SceneNode& node, const TextureHolder& textures) const;
		void					checkPickupDrop(CommandQueue& commands);
#pragma endregion

		void					updateTexts();


	private:
		Type					mType;
		sf::Sprite				mSprite;
		Command 				mFireCommand;
		Command					mMissileCommand;
		sf::Time				mFireCountdown;
		bool 					mIsFiring;
		bool					mIsLaunchingMissile;


		int						mFireRateLevel;
		int						mSpreadLevel;
		int						mMissileAmmo;

		Command 				mDropPickupCommand;
		float					mTravelledDistance;
		std::size_t				mDirectionIndex;
		TextNode*				mHealthDisplay;
		TextNode*				mMissileDisplay;
};

