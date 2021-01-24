#pragma once

namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
