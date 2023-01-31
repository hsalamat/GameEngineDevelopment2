#include "Command.hpp"
#include "SceneNode.hpp"
#include <algorithm>
#include <cassert>

unsigned int SceneNode::getCategory() const
{
	return Category::Scene;
}

void SceneNode::onCommand(const Command& command, sf::Time dt)
{
	if (command.category & getCategory())
		command.action(*this, dt);
}