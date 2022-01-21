/** @file Week2-Demo2-main.cpp
 *  @brief Frame-Independent Movement
 *  We want to provide the speed in a way that changes depending on the time a frame takes. 
 *  There is a simple formula distance = speed * time.
 *  We can calculate a relevant speed for every frame, so that the plane always travels
 *  exactly the distance we want it to travel over one second, no matter what computer
 *  we are sitting on.
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