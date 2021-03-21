#include <Entity.hpp>

#pragma region step 4
#include <cassert>

Entity::Entity(int hitpoints)
	: mVelocity()
	, mHitpoints(hitpoints)
{
}

int Entity::getHitpoints() const
{
	return mHitpoints;
}
#pragma endregion

void Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}



void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
	mVelocity.x += vx;
	mVelocity.y += vy;
}




