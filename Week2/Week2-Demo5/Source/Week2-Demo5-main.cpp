/** @file Week2-Demo5-main.cpp
 *  @brief TextureHolder
 *  We must find the right data structure to store the textures. We need to choose
 *  an STL container that does not perform unnecessary copies. std::vector is the
 *  wrong choice, since inserting new textures can trigger a reallocation of the dynamic
 *  array and the copying of all textures. Not only is this slow, but also all references
 *  and pointers to the textures are invalidated. We can access
 *  the textures by an enum, so the associative container std::map looks like the perfect
 *  choice.
 *
 *  @note: mBackgroundTexture.setRepeated(true);
 *  Repeating is involved when using texture coordinates outside 
 *  the texture rectangle [0, 0, width, height]. In this case, if repeat mode is enabled, 
 *  the whole texture will be repeated as many times as needed to reach the coordinate 
 *  (for example, if the X texture coordinate is 3 * width, the texture will be repeated 3 times). 
 *  If repeat mode is disabled, the "extra space" will instead be filled with border pixels. 
 * 
 *  @note: landscape.setTextureRect(sf::IntRect(0, 0, 1200, 800));
 *  Set the sub-rectangle of the texture that the sprite will display.
 *
 *  The texture rect is useful when you don't want to display the whole texture, but rather a part of it. By default, the texture rect covers the entire texture.
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