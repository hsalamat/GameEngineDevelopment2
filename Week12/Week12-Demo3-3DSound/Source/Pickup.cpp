#include <Pickup.hpp>
#include <DataTables.hpp>
#include <Category.hpp>
#include <CommandQueue.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>


namespace
{
	const std::vector<PickupData> Table = initializePickupData();
}

Pickup::Pickup(Type type, const TextureHolder& textures)
: Entity(1)
, mType(type)
, mSprite(textures.get(Table[type].texture), Table[type].textureRect)
{
	centerOrigin(mSprite);
}

unsigned int Pickup::getCategory() const
{
	return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Pickup::apply(Aircraft& player) const
{
	Table[mType].action(player);
}

void Pickup::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

