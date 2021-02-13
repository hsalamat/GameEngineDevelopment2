#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#pragma region step 10

void centerOrigin(sf::Sprite& sprite)
{

	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

#pragma endregion
