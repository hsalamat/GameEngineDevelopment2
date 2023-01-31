#pragma once
#include <SFML\Graphics.hpp>
#include "Category.hpp"
#include <iostream>
using namespace std;

class SceneNode: public sf::Transformable {
public:
	void					onCommand(const Command& command, sf::Time dt);
	unsigned int			getCategory() const;
};


