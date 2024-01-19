#include "Entity.hpp"

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

#pragma region step 4
//change Entity::update to updateCurrent
void Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}

#pragma endregion