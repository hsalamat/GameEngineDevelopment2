#pragma region step 5
#pragma once
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};

	Aircraft(Type type, const TextureHolder& textures);

private:
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	Type				mType;
	sf::Sprite			mSprite;
};

#pragma endregion
