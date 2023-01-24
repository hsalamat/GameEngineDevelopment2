#pragma once

namespace sf
{
	class Texture;
}


namespace sf
{
	class Font;
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
enum class TextureID
{
	Eagle,
	Raptor,
	Desert,
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

