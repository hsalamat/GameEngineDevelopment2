#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

class SceneNode: public sf::Transformable {
public:
	unsigned int			getCategory() const;
};