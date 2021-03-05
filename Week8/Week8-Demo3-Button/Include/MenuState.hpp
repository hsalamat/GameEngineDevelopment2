#pragma once
#include <Container.hpp>
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

#pragma region step 7
		//void					updateOptionText();
#pragma endregion

	private:
		enum OptionNames
		{
			Play,
			Exit,
		};


	private:
		sf::Sprite				mBackgroundSprite;
		GUI::Container			mGUIContainer;

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;
};

