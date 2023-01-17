/** @file Week2-Demo4-1-main.cpp
 *  @brief TextureHolder using type inference
 *  We write a method get() that returns a reference to a texture. The method has one
 *  parameter, namely the identifier for the resource. The method signature looks as
 *  follows: sf::Texture& get(Textures::ID id);
 * 
 *  mAirplaneTexture = textures.get(Textures::Airplane);
 *	airplane.setTexture(mAirplaneTexture);
 *	//!@ note now you can use the following 
 *	airplane.setTexture(textures.get(Textures::Airplane));
 * 
 *  Type inference is a language feature that has been introduced with
 *  C++11, which allows the compiler to find out the type of expressions.
 *  auto found = mTextureMap.find(id);
 * 
 *  The macro assert evaluates its expression; if it is false in debug mode, a breakpoint
 *	is triggered, halting the program execution and directly pointing to the source
 *  of the error. In release mode, assertions are optimized away, so we do not waste
 *  any performance to check for errors that cannot occur.
 *  assert(found != mTextureMap.end());
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