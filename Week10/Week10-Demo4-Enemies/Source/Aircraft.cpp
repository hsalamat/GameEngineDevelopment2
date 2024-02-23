#include <Aircraft.hpp>
#include <ResourceHolder.hpp>
#include <Utility.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <DataTables.hpp>
#include <CommandQueue.hpp>

namespace
{
	const std::vector<AircraftData> Table = initializeAircraftData();
}


Aircraft::Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts)
: Entity(Table[type].hitpoints)
, mType(type)
, mSprite(textures.get(Table[type].texture))
, mHealthDisplay(nullptr)
#pragma region step 4-1
, mTravelledDistance(0.f)
, mDirectionIndex(0)
#pragma endregion


{
	centerOrigin(mSprite);

	std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, ""));
	mHealthDisplay = healthDisplay.get();
	attachChild(std::move(healthDisplay));
}



void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
		case Eagle:
			return Category::PlayerAircraft;

		default:
			return Category::EnemyAircraft;
	}
}

void Aircraft::updateTexts()
{
	mHealthDisplay->setString(toString(getHitpoints()) + " HP");
	mHealthDisplay->setPosition(0.f, 50.f);
	mHealthDisplay->setRotation(-getRotation());
}

void Aircraft::updateCurrent(sf::Time dt, CommandQueue& commands)
{
#pragma region step 4-2
	// Update enemy movement pattern; apply velocity
	updateMovementPattern(dt);
#pragma endregion


	Entity::updateCurrent(dt, commands);
	// Update texts
	updateTexts();
}

#pragma region step 4-3

float Aircraft::getMaxSpeed() const
{
	return Table[mType].speed;
}


void Aircraft::updateMovementPattern(sf::Time dt)
{
	// Enemy airplane: Retrieve the movement pattern
	const std::vector<Direction>& directions = Table[mType].directions;
	//Only proceed if there are movement pattern
	if (!directions.empty())
	{
		//Check if the current direction has already been passed by the plane
		// If so, moved long enough in current direction: Change direction
		if (mTravelledDistance > directions[mDirectionIndex].distance)
		{
			//After finishing the lst direction, the plane begins again with the first one
			mDirectionIndex = (mDirectionIndex + 1) % directions.size();
			mTravelledDistance = 0.f;
		}

		// Compute velocity vector from direction's angle (toRadian method to be added to utility class!)
		// Add 90 degrees to fly downwards
		float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
		float vx = getMaxSpeed() * std::cos(radians);
		float vy = getMaxSpeed() * std::sin(radians);

		setVelocity(vx, vy);

		mTravelledDistance += getMaxSpeed() * dt.asSeconds();
	}
}
#pragma endregion

