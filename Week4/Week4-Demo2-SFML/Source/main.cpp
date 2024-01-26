//Commands denote messages that are sent to various game objects.
//A command is able to alter the object and to issue orders such as moving an entity,
//firing a weapon, and triggering an explosion.
//We design a structure Command that contains a function object, which can be called
//on any game object represented by a scene node :
//struct Command
//{
//	std::function<void(SceneNode&, sf::Time)> action;
//};
//std::function is a C++11 class template to implements
//callback mechanisms.It treats functions as objects and makes
//it possible to copy functions or to store them in containers.The
//std::function class is compatible with function pointers,
//member function pointers, functors, and lambda expressions.
//The template parameter represents the signature of the function
//being stored

#include <Game.hpp>

#include <stdexcept>
#include <iostream>


int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
