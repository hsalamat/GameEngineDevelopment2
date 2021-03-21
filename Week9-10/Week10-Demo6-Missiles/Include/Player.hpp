#pragma once

#include <Command.hpp>

#include <SFML/Window/Event.hpp>

#include <map>


class CommandQueue;

class Player
{
	public:
		enum Action
		{
			MoveLeft,
			MoveRight,
			MoveUp,
			MoveDown,
			Fire,
			LaunchMissile,
			ActionCount
		};

#pragma region step 9

		enum MissionStatus
		{
			MissionRunning,
			MissionSuccess,
			MissionFailure
		};

#pragma endregion
	public:
								Player();

		void					handleEvent(const sf::Event& event, CommandQueue& commands);
		void					handleRealtimeInput(CommandQueue& commands);

		void					assignKey(Action action, sf::Keyboard::Key key);
		sf::Keyboard::Key		getAssignedKey(Action action) const;

#pragma region step 10
		void 					setMissionStatus(MissionStatus status);
		MissionStatus 			getMissionStatus() const;
#pragma endregion

	private:
		void					initializeActions();
		static bool				isRealtimeAction(Action action);


	private:
		std::map<sf::Keyboard::Key, Action>		mKeyBinding;
		std::map<Action, Command>				mActionBinding;

#pragma region step 11
		MissionStatus 							mCurrentMissionStatus;
#pragma endregion
};

