#pragma once
#include <ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <functional>
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

struct AircraftData
{
	int								hitpoints;
	float							speed;
	Textures::ID					texture;
	std::vector<Direction>			directions;

#pragma region step 2
	sf::Time						fireInterval;
};


struct ProjectileData
{
	int								damage;
	float							speed;
	Textures::ID					texture;
};

std::vector<AircraftData>	initializeAircraftData();
std::vector<ProjectileData>	initializeProjectileData();
#pragma endregion

