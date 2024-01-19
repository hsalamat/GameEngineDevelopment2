/** @file Week3-Demo5-main.cpp
 *  @brief Getting the input state in real time
 *  Now, we have gone through many varieties of events.A problem with events is that
 *  they report once when the state changes, but you cannot continuously ask them how
 *  the state of the input devices look right now.
 *  But SFML, in an effort to make input management easier, has
 *  implemented classes that let you access these states in real time whenever you want
 *  from wherever you want. We will use the notion of real-time input to denote this
 *  alternative method of handling user input.
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
