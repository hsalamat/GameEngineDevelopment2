#pragma region step 5
#pragma once
#include <ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <functional>

struct AircraftData
{
	int								hitpoints;
	float							speed;
	Textures::ID					texture;
};

std::vector<AircraftData>	initializeAircraftData();
#pragma endregion


