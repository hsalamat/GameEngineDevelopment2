#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

class Player
{

public:
	enum class Type
	{
		Eagle,
		Raptor,
	};


public:
	Player();


	sf::Sprite& getSprite(); 

private:
	sf::Sprite mSprite;
	sf::Texture texture2;
	TextureHolder textures;
};
