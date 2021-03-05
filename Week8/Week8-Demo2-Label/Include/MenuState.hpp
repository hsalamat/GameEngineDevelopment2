#pragma once
#pragma region step 7
#include <Container.hpp>
#pragma endregion
#include <State.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
	public:
								MenuState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					updateOptionText();


	private:
		enum OptionNames
		{
			Play,
			Exit,
		};


	private:
		sf::Sprite				mBackgroundSprite;

#pragma region step 8
		GUI::Container			mGUIContainer;
#pragma endregion

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;
};

