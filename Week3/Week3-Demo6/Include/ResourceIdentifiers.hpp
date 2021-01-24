#pragma once

namespace sf
{
	class Texture;
}

#pragma region step 1
namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Desert,
	};
}
#pragma endregion

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

