#include <Player.hpp>
#include <CommandQueue.hpp>
#include <Aircraft.hpp>
#include <map>
#include <string>
#include <algorithm>

using namespace std::placeholders;

struct AircraftMover
{
	AircraftMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
#pragma region step 11 - 1
		aircraft.accelerate(velocity * aircraft.getMaxSpeed());
#pragma endregion
	}

	sf::Vector2f velocity;
};

Player::Player()
{
	// Set initial key bindings
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;

#pragma region step 11 - 2
	mKeyBinding[sf::Keyboard::Space] = Fire;
	mKeyBinding[sf::Keyboard::M] = LaunchMissile;
#pragma endregion


	// Set initial action bindings
	initializeActions();	

	// Assign all categories to player's aircraft
	for(auto& pair: mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	for(auto pair: mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for(auto pair: mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
	const float playerSpeed = 200.f;

#pragma region step 11-3 
	mActionBinding[MoveLeft].action	 = derivedAction<Aircraft>(AircraftMover(-1, 0.f));  //use getmaxspeed instead of playerspeed
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+1, 0.f));
	mActionBinding[MoveUp].action    = derivedAction<Aircraft>(AircraftMover(0.f, -1));
	mActionBinding[MoveDown].action  = derivedAction<Aircraft>(AircraftMover(0.f, +1));


	//we don't want to fire a projectile for every frame. To accomplish this, we need to pass the delta time passed in the aircraft's update() function
	mActionBinding[Fire].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) { a.fire(); });
	mActionBinding[LaunchMissile].action = derivedAction<Aircraft>([](Aircraft& a, sf::Time) { a.launchMissile(); });

#pragma endregion

}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveDown:
		case MoveUp:
#pragma region step 11-4
		case Fire:
#pragma endregion

			return true;

		default:
			return false;
	}
}
