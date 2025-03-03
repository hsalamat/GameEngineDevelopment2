#pragma once
#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

namespace sf
{
	class Sprite;
	class Text;
}
void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);



#include <Utility.inl>

