#pragma once

#include <ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <functional>

#pragma region step 2 - 1
#include <SFML/Graphics/Rect.hpp>
#pragma endregion


class Aircraft;

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

#pragma region step 2 - 2
	sf::IntRect						textureRect;
#pragma endregion

	sf::Time						fireInterval;
	std::vector<Direction>			directions;
};

struct ProjectileData
{
	int								damage;
	float							speed;
	Textures::ID					texture;

#pragma region step 2 - 3
	sf::IntRect						textureRect;
#pragma endregion
};

struct PickupData
{
	std::function<void(Aircraft&)>	action;
	Textures::ID					texture;

#pragma region step 2 - 4
	sf::IntRect						textureRect;
#pragma endregion
};


std::vector<AircraftData>	initializeAircraftData();
std::vector<ProjectileData>	initializeProjectileData();
std::vector<PickupData>		initializePickupData();

