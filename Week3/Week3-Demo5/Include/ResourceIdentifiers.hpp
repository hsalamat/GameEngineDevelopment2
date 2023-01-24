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
enum class TextureID
{
	Landscape,
	Airplane,
};

enum class FontID
{
	sansation,
	font2,
};

template <typename Resource, typename Identifier>
class ResourceHolder;

//typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
using TextureHolder = ResourceHolder<sf::Texture, TextureID>;
using FontHolder = ResourceHolder<sf::Font, FontID>;
