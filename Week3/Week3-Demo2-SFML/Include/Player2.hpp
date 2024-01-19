#pragma once
#pragma region step 3

//B) The other way to do this would be to have your player class inheirit 
//from sf::Drawable and then override the virtual draw() function to do 
//the drawing in the player class. This is the best way to do this but 
//takes more knowledge on inheiritence, though it will allows you to make 
//a draw call like this Window.draw(player); in your main game loop.


#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML\Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Player2 : public sf::Drawable, public sf::Transformable
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

	//The first parameter specifies, where the drawable object is drawn to. Mostly, this will be a sf::RenderWindow. The second parameter contains additional information for the rendering process, such as blend mode (how pixel of the object are blened, transform (how the object is positioned/rotated/scaled), the used texture (what image is mapped to the object), or shader (what custom effects applied to the object). 
	//SFML's high-level classes Sprite, Text, and Shape are all derived fromTransformable and Drawable.

	virtual	void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	sf::Sprite mSprite;
	sf::Texture texture2;

};

#pragma endregion