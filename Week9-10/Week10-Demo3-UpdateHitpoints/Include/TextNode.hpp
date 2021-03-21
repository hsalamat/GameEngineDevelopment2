#pragma region step 8-1
//Add some text on the display to show the hitpoints or ammunition of different entities
#pragma once
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <SceneNode.hpp>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class TextNode : public SceneNode
{
public:
	explicit			TextNode(const FontHolder& fonts, const std::string& text);

	void				setString(const std::string& text);


private:
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	sf::Text			mText;
};
#pragma endregion


