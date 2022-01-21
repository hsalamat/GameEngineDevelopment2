/** @file Week2-Demo6-main.cpp
 *  @brief Generalizing the approach: ResourceHolder
 *  We have implemented everything we need for textures, but we would like to handle
 *  other resources such as fonts and sound buffers too. As the implementation looks
 *  extremely similar for them, it would be a bad idea to write new classes FontHolder
 *  and SoundBufferHolder with exactly the same functionality. Instead, we write a
 *  class template, which we instantiate for different resource classes.
 *  We call our template ResourceHolder and equip it with two template parameters:
 *  • Resource: The type of resource, for example, sf::Texture. We design the
 *  class template to work the SFML classes, but if you have your own resource
 *  class which conforms to the required interface (providing loadFromFile()
 *  methods), nothing keeps you from using it together with ResourceHolder.
 *  • Identifier: The ID type for resource access, for example, Textures::ID.
 *  This will usually be an enum, but the type is not restricted to enumerations.
 *  Any type that supports an operator< can be used as identifier, for example,
 *  std::string.
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