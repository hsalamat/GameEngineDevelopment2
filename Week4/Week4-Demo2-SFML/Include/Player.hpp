#pragma region step 17

#pragma once

#include <Command.hpp>
#include <SFML/Window/Event.hpp>
#include <map>

class CommandQueue;

class Player
{
	public:
								Player();
								static const float		PlayerSpeed;
		void					handleEvent(const sf::Event& event, CommandQueue& commands);
		void					handleRealtimeInput(CommandQueue& commands);
};
#pragma endregion

