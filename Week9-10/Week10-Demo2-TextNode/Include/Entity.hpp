#pragma once
#include <SceneNode.hpp>

class Entity : public SceneNode
{
	public:
		void				setVelocity(sf::Vector2f velocity);
		void				setVelocity(float vx, float vy);
		void				accelerate(sf::Vector2f velocity);
		void				accelerate(float vx, float vy);
		sf::Vector2f		getVelocity() const;

#pragma region step 3-1
		//functions that allow modification of the hitpoint
		explicit			Entity(int hitpoints);
		int					getHitpoints() const;
#pragma endregion
private:
	virtual void		updateCurrent(sf::Time dt);

	private:
		sf::Vector2f		mVelocity;
#pragma region step 3-3
		//Hitpoints (HP) are a measure for the integrity of an entity
		//The entity is destroyed as soon as the hitpoint each or fall below zero
		int					mHitpoints;
#pragma endregion

};


