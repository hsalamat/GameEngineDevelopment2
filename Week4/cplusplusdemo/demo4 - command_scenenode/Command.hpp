#pragma once
#include <functional>
#include <cassert>
#include <SFML\Graphics.hpp>
#include "SceneNode.hpp"

class Command
{
public:
	std::function<void(SceneNode&, sf::Time)> action;
};
