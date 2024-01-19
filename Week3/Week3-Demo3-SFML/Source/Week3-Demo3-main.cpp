/** @file Week3-Demo3-main.cpp
 *  @brief View & Viewport
 *  sf::View  class acts as a viewing lens, which ensures that anything you attempt to draw to the screen
 *  that is outside the view's rectangle will remain unseen.
 *  Besides the viewing rectangle, another parameter that defines the sf::View class is
 *  the viewport, which gives us control over how to map the viewing rectangle to the
 *  actual application window.
 *  So, a viewport rectangle starting at (0, 0) and ending in (1, 1) means
 *  essentially that the entire window area will be used to render the world.
 *  having their viewport rectangles defined as, respectively, (left=0, top=0, width=1, height=0.5) and (left=0,
 *  top=0.5, width=1, height=0.5). This would immediately mean that we would have two distinct "eyes" looking at the
 *  world, and that they would only render in their own viewports
 *  The sf::View utility gives us another two  features: zooming and rotating our view. 
 *  In every step of the game loop, when updating the state of the world, we also scroll
 *  the view a little. We do this at a constant speed towards the negative y axis (up), so
 *  we see a little further at each time step. Of course, we also move the player's aircraft
 *  by the exact same distance, so it won't get left behind, but remains in action.
 *  This incremental and automatic scrolling operation of the view is simply done in the
 *  update code, by doing: mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
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
