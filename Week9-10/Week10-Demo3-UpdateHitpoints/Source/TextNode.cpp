#include <TextNode.hpp>
#include <Utility.hpp>

#include <SFML/Graphics/RenderTarget.hpp>


TextNode::TextNode(const FontHolder& fonts, const std::string& text)
{
	mText.setFont(fonts.get(Fonts::Main));
	mText.setCharacterSize(20);
	setString(text);
}

//drawCurrent just forwards the call to the SFML render target
void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mText, states);
}

//setString assigns a new string  to the text node and automatically adapts to its size
void TextNode::setString(const std::string& text)
{
	mText.setString(text);

	//sets the text origin to its center
	centerOrigin(mText);
}

