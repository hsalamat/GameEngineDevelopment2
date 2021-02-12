#include "Entity.hpp"

Entity::Entity(Game* game) : SceneNode(game), mVelocity(0, 0)
{
}

void Entity::setVelocity(XMFLOAT2 velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

XMFLOAT2 Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::updateCurrent(const GameTimer& gt) 
{
	XMFLOAT2 mV;
	mV.x = mVelocity.x * gt.DeltaTime();
	mV.y = mVelocity.y * gt.DeltaTime();

	move(mV.x, mV.y, 0);

	renderer->World = getWorldTransform();
	renderer->NumFramesDirty++;
}
