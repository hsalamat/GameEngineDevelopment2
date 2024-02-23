#pragma once
#include <ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <functional>

#pragma region step 1-1
// A direction consists of an angle and a distance
struct Direction
{
	Direction(float angle, float distance)
		: angle(angle)
		, distance(distance)
	{
	}

	float angle;
	float distance;
};
#pragma endregion


struct AircraftData
{
	int								hitpoints;
	float							speed;
	Textures::ID					texture;

#pragma region step 1-2
//sequence of directions that enemy airplane heads.
	std::vector<Direction>			directions;
#pragma endregion

};

std::vector<AircraftData>	initializeAircraftData();



