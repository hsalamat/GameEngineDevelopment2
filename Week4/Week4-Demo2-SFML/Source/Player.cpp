#pragma region step 18
#include <Player.hpp>
#include <CommandQueue.hpp>
#include <Aircraft.hpp>

#include <map>
#include <string>
#include <algorithm>
#include <iostream>
const float Player::PlayerSpeed = 100.f;
struct AircraftMover
{
	AircraftMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	//void operator() (SceneNode& node, sf::Time) const
	//{
	//	assert(dynamic_cast<Aircraft*>(&node) != nullptr);
	//	Aircraft& aircraft = static_cast<Aircraft&>(node);
	//	aircraft.accelerate(velocity);
	//}


	void operator() (Aircraft& aircraft, sf::Time) const
	{
		aircraft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

Player::Player()
{

}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
	{
		Command output;
		output.category = Category::PlayerAircraft;
		output.action = [](SceneNode& s, sf::Time) {
			std::cout << s.getPosition().x << ","
				<< s.getPosition().y << "\n";
		};
		commands.push(output);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(
			AircraftMover(-PlayerSpeed, 0.f)
			);
		commands.push(moveLeft);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Command moveRight;
		moveRight.category = Category::PlayerAircraft;
		moveRight.action = derivedAction<Aircraft>(
			AircraftMover(PlayerSpeed, 0.f)
			);
		commands.push(moveRight);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Command moveUp;
		moveUp.category = Category::PlayerAircraft;
		moveUp.action = derivedAction<Aircraft>(
			AircraftMover(0.f, -PlayerSpeed)
			);
		commands.push(moveUp);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Command moveDown;
		moveDown.category = Category::PlayerAircraft;
		moveDown.action = derivedAction<Aircraft>(
			AircraftMover(0.f, PlayerSpeed)
			);
		commands.push(moveDown);
	}


}
#pragma endregion
