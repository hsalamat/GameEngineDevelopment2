#include "Player2.hpp"


Player2::Player2()
{


	//if (!texture2.loadFromFile("Media/Textures/Eagle.png"))
	//{
	//	// Handle loading error
	//}

	//mSprite.setTexture(texture2);
	textures.load(TextureID::Airplane, "Media/Textures/Eagle.png");

	mSprite.setTexture(textures.get(TextureID::Airplane));
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

void Player2::update(sf::Time dt)
{
	mSprite.move(mVelocity * dt.asSeconds());
}
