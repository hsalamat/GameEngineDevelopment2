#pragma region step 4

#include "Player2.hpp"

Player2::Player2()
{

	if (!texture2.loadFromFile("Media/Textures/Eagle.png"))
	{
		// Handle loading error
	}

	mSprite.setTexture(texture2);
	mSprite.setPosition(400.f, 400.f);
}

sf::Sprite& Player2::getSprite()
{
	return mSprite;
}

void Player2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

#pragma endregion