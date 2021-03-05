#pragma once

#include <State.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#pragma region step 9
#include <Container.hpp>
#pragma endregion


class PauseState : public State
{
	public:
							PauseState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mPausedText;
#pragma region step 10
		//sf::Text			mInstructionText;
		GUI::Container 		mGUIContainer;
#pragma endregion

	
};
