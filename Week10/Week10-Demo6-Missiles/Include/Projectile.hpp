#pragma once

#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>

#include <SFML/Graphics/Sprite.hpp>


class Projectile : public Entity
{
	public:
		enum Type
		{
			AlliedBullet,
			EnemyBullet,
			Missile,
			TypeCount
		};


	public:
								Projectile(Type type, const TextureHolder& textures);

		virtual unsigned int	getCategory() const;
		virtual sf::FloatRect	getBoundingRect() const;
		float					getMaxSpeed() const;

#pragma region step 1
		void					guideTowards(sf::Vector2f position);
		bool					isGuided() const;
#pragma endregion

	
	private:
		virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		Type					mType;
		sf::Sprite				mSprite;

#pragma region step 2
		sf::Vector2f			mTargetDirection;
#pragma endregion

};


