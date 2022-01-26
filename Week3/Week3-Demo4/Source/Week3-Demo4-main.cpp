/** @file Week3-Demo4-main.cpp
 *  @brief Entities
 *  We have a base class called Entity, which contains the data and
 *  functionality that all different kinds of entities have in common. We have multiple
 *  classes that derive from Entity, and that implement specific functionality. These
 *  derived classes could represent airplanes, projectiles (such as missiles), or pickups.
 *  We implement the velocity attribute in the base class Entity, so each concrete entity has it.
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
