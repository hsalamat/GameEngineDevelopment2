/** @file Week3-Demo6-main.cpp
 *  @brief Scene Node - sprite Node
 * 
 *  Each scene node can store an object that is drawn on the screen, most often this is an entity.
 *  Each node may have an arbitrary amount of child nodes, which adapt to the
 *  transform of their parent node when rendering. Children only store the position,
 *  rotation, and scale relative to their parent.
 *  A scene graph contains a root scene node, which exists only once in a world. It
 *  resides above all other scene nodes in the hierarchy, thus it has no parent node.
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
