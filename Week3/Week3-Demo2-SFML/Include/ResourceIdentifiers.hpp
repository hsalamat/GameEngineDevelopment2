#pragma once
#pragma region step 5

namespace sf
{
	class Texture;
}

//namespace Textures
//{
//	enum ID
//	{
//		Landscape,
//		Airplane,
//	};
//}

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


typedef ResourceHolder<sf::Texture, TextureID> TextureHolder;
//typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
///using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;

typedef ResourceHolder<sf::Font, FontID> FontHolder;

#pragma endregion