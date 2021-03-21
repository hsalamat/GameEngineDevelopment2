#pragma region step 2
#pragma once

#include <State.hpp>
#include <Player.hpp>
#include <Container.hpp>
#include <Button.hpp>
#include <Label.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingsState : public State
{
	public:
										SettingsState(StateStack& stack, Context context);

		virtual void					draw();
		virtual bool					update(sf::Time dt);
		virtual bool					handleEvent(const sf::Event& event);


	private:
		void							updateLabels();
		void							addButtonLabel(Player::Action action, float y, const std::string& text, Context context);


	private:
		sf::Sprite											mBackgroundSprite;
		GUI::Container										mGUIContainer;
		std::array<GUI::Button::Ptr, Player::ActionCount>	mBindingButtons;
		std::array<GUI::Label::Ptr, Player::ActionCount> 	mBindingLabels;
};

#pragma endregion

