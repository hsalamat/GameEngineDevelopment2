#include <PauseState.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#pragma region step 11
#include <Button.hpp>

PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite()
, mPausedText()
, mGUIContainer()
{
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f windowSize(context.window->getSize());

	mPausedText.setFont(font);
	mPausedText.setString("Game Paused");	
	mPausedText.setCharacterSize(70);
	centerOrigin(mPausedText);
	mPausedText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);

	//mInstructionText.setFont(font);
	//mInstructionText.setString("(Press Backspace to return to the main menu)");
	//centerOrigin(mInstructionText);
	//mInstructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
	auto returnButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	returnButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 75);
	returnButton->setText("Return");
	returnButton->setCallback([this]()
	{
		requestStackPop();
	});

	auto backToMenuButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	backToMenuButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
	backToMenuButton->setText("Back to menu");
	backToMenuButton->setCallback([this]()
	{
		requestStateClear();
		requestStackPush(States::Menu);
	});

	mGUIContainer.pack(returnButton);
	mGUIContainer.pack(backToMenuButton);
}

#pragma endregion

void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(mPausedText);
#pragma region step 12
	//window.draw(mInstructionText);
	window.draw(mGUIContainer);
#pragma endregion
}

bool PauseState::update(sf::Time)
{
	return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
#pragma region step 13
	mGUIContainer.handleEvent(event);

	//if (event.type != sf::Event::KeyPressed)
	//	return false;

	//if (event.key.code == sf::Keyboard::Escape)
	//{
	//	// Escape pressed, remove itself to return to the game
	//	requestStackPop();
	//}

	//if (event.key.code == sf::Keyboard::BackSpace)
	//{
	//	// Escape pressed, remove itself to return to the game
	//	requestStateClear();
	//	requestStackPush(States::Menu);
	//}
#pragma endregion
	return false;
}