#ifndef BOOK_STATEIDENTIFIERS_HPP
#define BOOK_STATEIDENTIFIERS_HPP


namespace States
{
	enum ID
	{
#pragma region step 6
		None,
		Title,
		Menu,
		Game,
		Loading,
		Pause,
		NetworkPause,
		Settings,
		GameOver,
		MissionSuccess,
		HostGame,
		JoinGame,
#pragma endregion

	};
}

#endif // BOOK_STATEIDENTIFIERS_HPP
