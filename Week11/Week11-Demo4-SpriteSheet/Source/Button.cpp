#include <Button.hpp>
#include <Utility.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


namespace GUI
{

Button::Button(const FontHolder& fonts, const TextureHolder& textures)
: mCallback()
#pragma region step 9 - 1
//, mNormalTexture(textures.get(Textures::ButtonNormal))
//, mSelectedTexture(textures.get(Textures::ButtonSelected))
//, mPressedTexture(textures.get(Textures::ButtonPressed))
//, mSprite()
, mSprite(textures.get(Textures::Buttons)) 
#pragma endregion

, mText("", fonts.get(Fonts::Main), 16)
, mIsToggle(false)
{

#pragma region step 9 - 2
	//mSprite.setTexture(mNormalTexture);
	changeTexture(Normal);
#pragma endregion

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void Button::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}

void Button::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
	Component::select();
#pragma region step 9 - 3
	//mSprite.setTexture(mSelectedTexture);
	changeTexture(Selected);
#pragma endregion

}

void Button::deselect()
{
	Component::deselect();

#pragma region step 9 - 4
	//mSprite.setTexture(mNormalTexture);
	changeTexture(Normal);
#pragma endregion
}

void Button::activate()
{
	Component::activate();

    // If we are toggle then we should show that the button is pressed and thus "toggled".
	if (mIsToggle)
#pragma region step 9 - 5
		//mSprite.setTexture(mPressedTexture);
	changeTexture(Pressed);
#pragma endregion

	if (mCallback)
		mCallback();

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
	if (!mIsToggle)
		deactivate();
}

void Button::deactivate()
{
	Component::deactivate();

	if (mIsToggle)
	{
        // Reset texture to right one depending on if we are selected or not.
		if (isSelected())
#pragma region step 9 - 6
			changeTexture(Selected);
		else
			changeTexture(Normal);
#pragma endregion
	}
}

void Button::handleEvent(const sf::Event&)
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
	target.draw(mText, states);
}


#pragma region step 9 - 7
void Button::changeTexture(Type buttonType)
{
	sf::IntRect textureRect(0, 50 * buttonType, 200, 50);
	mSprite.setTextureRect(textureRect);
}
#pragma endregion

}
