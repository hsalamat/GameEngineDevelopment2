#include <Projectile.hpp>
#include <DataTables.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <cmath>
#include <cassert>


namespace
{
	const std::vector<ProjectileData> Table = initializeProjectileData();
}

Projectile::Projectile(Type type, const TextureHolder& textures)
: Entity(1)
, mType(type)
, mSprite(textures.get(Table[type].texture))
#pragma region step 6
, mTargetDirection()

{
	centerOrigin(mSprite);
}


void Projectile::guideTowards(sf::Vector2f position)
{
	assert(isGuided());
	//target direction is a unit vector headed towards the target
	mTargetDirection = unitVector(position - getWorldPosition());
}

bool Projectile::isGuided() const
{
	return mType == Missile;
}

//we steer our missile by changing its velocity by adding small contributions of 
//the target direction vector to it. so the velocity vector continously approaches
//the target direction, having the effect that missile flies along a curve towards target

void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (isGuided())
	{
		//approachRate: to What extent the target direction contributes to its velocity
		const float approachRate = 200.f;

		//newVelocity: the weighted sum of the two vectors
		sf::Vector2f newVelocity = unitVector(approachRate * dt.asSeconds() * mTargetDirection + getVelocity());
		//If we don't add targetDirection to getVelocity(), we don't get tje effect that the missile flies along the curve towards the target
		//sf::Vector2f newVelocity = unitVector(approachRate * dt.asSeconds() * mTargetDirection );

		//scale to the maximum speed of the missile's velocity
		newVelocity *= getMaxSpeed();
		
		//While tangent will find the ratio of the two sides of a right triangle when given an angle, arctangent can find the angle given the ratio
		float angle = std::atan2(newVelocity.y, newVelocity.x);

		//the angle is assigned to the missile's direction. +90 => missile texture points upward (instead of right)
		//The rotation is the orientation of the entity in the 2D world. It is defined in degrees, in clockwise order (because the Y axis is pointing down in SFML).
		setRotation(toDegree(angle) + 90.f);
		setVelocity(newVelocity);
	}

	Entity::updateCurrent(dt, commands);
}

#pragma endregion
void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int Projectile::getCategory() const
{
	if (mType == EnemyBullet)
		return Category::EnemyProjectile;
	else
		return Category::AlliedProjectile;
}

sf::FloatRect Projectile::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

float Projectile::getMaxSpeed() const
{
	return Table[mType].speed;
}


