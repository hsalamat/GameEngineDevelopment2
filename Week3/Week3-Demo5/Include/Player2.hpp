//B) The other way to do this would be to have your player class inheirit 
//from sf::Drawable and then override the virtual draw() function to do 
//the drawing in the player class. This is the best way to do this but 
//takes more knowledge on inheiritence, though it will allows you to make 
//a draw call like this Window.draw(player); in your main game loop.

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML\Graphics.hpp>
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "Entity.hpp"

class Player2: public Entity
#pragma endregion

{

public:
	enum class Type
	{
		Eagle,
		Raptor,
	};


public:
	Player2();

	sf::Sprite& getSprite();

	virtual	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Time);

private:
	sf::Sprite mSprite;
	sf::Texture texture2;
	TextureHolder textures;
};
