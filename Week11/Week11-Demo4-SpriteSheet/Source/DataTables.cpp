#include <DataTables.hpp>
#include <Aircraft.hpp>
#include <Projectile.hpp>
#include <Pickup.hpp>


// For std::bind() placeholders _1, _2, ...
using namespace std::placeholders;

std::vector<AircraftData> initializeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);

	data[Aircraft::Eagle].hitpoints = 100;
	data[Aircraft::Eagle].speed = 200.f;
	data[Aircraft::Eagle].fireInterval = sf::seconds(1);

#pragma region step 3 - 1
	//data[Aircraft::Eagle].texture = Textures::Eagle;
	data[Aircraft::Eagle].texture = Textures::Entities;
	data[Aircraft::Eagle].textureRect = sf::IntRect(0, 0, 48, 64);
#pragma endregion


	data[Aircraft::Raptor].hitpoints = 20;
	data[Aircraft::Raptor].speed = 80.f;

#pragma region step 3 - 2
	//data[Aircraft::Raptor].texture = Textures::Raptor;
	data[Aircraft::Raptor].texture = Textures::Entities;
	data[Aircraft::Raptor].textureRect = sf::IntRect(144, 0, 84, 64);
#pragma endregion

	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Raptor].directions.push_back(Direction(-45.f, 160.f));
	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Raptor].fireInterval = sf::Time::Zero;

	data[Aircraft::Avenger].hitpoints = 40;
	data[Aircraft::Avenger].speed = 50.f;

#pragma region step 3 - 3
	//data[Aircraft::Avenger].texture = Textures::Avenger;
	data[Aircraft::Avenger].texture = Textures::Entities;
	data[Aircraft::Avenger].textureRect = sf::IntRect(228, 0, 60, 59);
#pragma endregion

	data[Aircraft::Avenger].directions.push_back(Direction(+45.f,  50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(  0.f,  50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(-45.f, 100.f));
	data[Aircraft::Avenger].directions.push_back(Direction(  0.f,  50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(+45.f,  50.f));
	data[Aircraft::Avenger].fireInterval = sf::seconds(2);

	return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::AlliedBullet].damage = 10;
	data[Projectile::AlliedBullet].speed = 300.f;

#pragma region step 3 - 4
	//	data[Projectile::AlliedBullet].texture = Textures::Bullet;
	data[Projectile::AlliedBullet].texture = Textures::Entities;
	data[Projectile::AlliedBullet].textureRect = sf::IntRect(175, 64, 3, 14);
#pragma endregion

	data[Projectile::EnemyBullet].damage = 10;
	data[Projectile::EnemyBullet].speed = 300.f;

#pragma region step 3 - 5
	//	data[Projectile::EnemyBullet].texture = Textures::Bullet;
	data[Projectile::EnemyBullet].texture = Textures::Entities;
	data[Projectile::EnemyBullet].textureRect = sf::IntRect(178, 64, 3, 14);
#pragma endregion

	data[Projectile::Missile].damage = 200;
	data[Projectile::Missile].speed = 150.f;

#pragma region step 3 - 6
	//	data[Projectile::Missile].texture = Textures::Missile;
	data[Projectile::Missile].texture = Textures::Entities;
	data[Projectile::Missile].textureRect = sf::IntRect(160, 64, 15, 32);
#pragma endregion

	return data;
}

std::vector<PickupData> initializePickupData()
{
	std::vector<PickupData> data(Pickup::TypeCount);

#pragma region step 3 - 7
	//data[Pickup::HealthRefill].texture = Textures::HealthRefill;
	data[Pickup::HealthRefill].texture = Textures::Entities;
	data[Pickup::HealthRefill].textureRect = sf::IntRect(0, 64, 40, 40);
#pragma endregion

	data[Pickup::HealthRefill].action = [] (Aircraft& a) { a.repair(25); };

#pragma region step 3 - 8
	//data[Pickup::MissileRefill].texture = Textures::MissileRefill;
	data[Pickup::MissileRefill].texture = Textures::Entities;
	data[Pickup::MissileRefill].textureRect = sf::IntRect(40, 64, 40, 40);
#pragma endregion

	data[Pickup::MissileRefill].action = std::bind(&Aircraft::collectMissiles, _1, 3);
	
#pragma region step 3 - 9
	//data[Pickup::FireSpread].texture = Textures::FireSpread;
	data[Pickup::FireSpread].texture = Textures::Entities;
	data[Pickup::FireSpread].textureRect = sf::IntRect(80, 64, 40, 40);

	data[Pickup::FireSpread].action = std::bind(&Aircraft::increaseSpread, _1);

#pragma region step 3 - 10
	//data[Pickup::FireRate].texture = Textures::FireRate;
	data[Pickup::FireRate].texture = Textures::Entities;
	data[Pickup::FireRate].textureRect = sf::IntRect(120, 64, 40, 40);
#pragma endregion
	data[Pickup::FireRate].action = std::bind(&Aircraft::increaseFireRate, _1);

#pragma endregion

	return data;
}
