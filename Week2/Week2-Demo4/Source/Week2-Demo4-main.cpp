/** @file Week2-Demo4-main.cpp
 *  @brief Fixed Time Steps
 *  Consider that a frame may sometimes take three times the average delta time. This
 *	can lead to severe mistakes in the game logic, for example, when a player moves
 *	three times the distance and passes through a wall he would normally collide with.
 *	This is why physics engines expect the delta time to be fixed.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include "Game.hpp"

int main()
{
	Game game;
	game.run();

}