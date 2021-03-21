#include <Aircraft.hpp>
#include <ResourceHolder.hpp>
#include <Utility.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#pragma region step 8-1
#include <DataTables.hpp>


namespace
{
	const std::vector<AircraftData> Table = initializeAircraftData();
}

//Textures::ID toTextureID(Aircraft::Type type)
//{
//	switch (type)
//	{
//		case Aircraft::Eagle:
//			return Textures::Eagle;
//
//		case Aircraft::Raptor:
//			return Textures::Raptor;
//	}
//	return Textures::Eagle;
//}


Aircraft::Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts)
: Entity(Table[type].hitpoints)
, mType(type)
, mSprite(textures.get(Table[type].texture))
, mHealthDisplay(nullptr)
{
	centerOrigin(mSprite);

	std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, ""));
	mHealthDisplay = healthDisplay.get();
	attachChild(std::move(healthDisplay));

	// Update texts
	updateTexts();
}
#pragma endregion


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

#pragma region step 8-2
void Aircraft::updateTexts()
{
	mHealthDisplay->setString(toString(getHitpoints()) + " HP");
	mHealthDisplay->setPosition(0.f, 50.f);
	mHealthDisplay->setRotation(-getRotation());
}

#pragma endregion