/** @file Week2-Demo1-main.cpp
 *  @brief Frame Dependent Movement
 *  Right now your computer will be running
 *  the update() function as fast as it can, which means it will probably call it a couple
 *  of hundreds of times each second, if not more. If we move the shape by one pixel
 *  for every frame, this can count up to several 100 pixels every second, making our
 *  little player fly all over the screen.
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