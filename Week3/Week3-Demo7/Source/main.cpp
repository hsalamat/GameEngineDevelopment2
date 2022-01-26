/** @file Week3-Demo7-main.cpp
 *  @brief World
 *
 *  We create a new class called World. On one side, our World
 *  class must contain all the data related to rendering:
 *	• A reference to the render window
 *	• The world's current view
 *	• A texture holder with all the textures needed inside the world
 *	• The scene graph
 *	• Some pointers to access the scene graph's layer nodes
 *	On the other hand, we store some logical data:
 *	• The bounding rectangle of the world, storing its dimensions
 *	• The position where the player's plane appears in the beginning
 *	• The speed with which the world is scrolled
 *	• A pointer to the player's aircraft
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include "Game.hpp"
#include <stdexcept>
#include <iostream>


int main()
{
	try {
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
