#include <iostream>
using namespace std;

#include <bitset>


enum class Category : int
{
	None = 0,
	Scene = 1 << 0,
	PlayerAircraft = 1 << 1,
	AllliedAircraft = 1 << 2,
	EnemyAircraft = 1 << 3,
	Pixkup = 1 << 5,
} category;

int main()
{
	cout << static_cast<int>(Category::None) << endl;
	cout << static_cast<int>(Category::Scene) << endl;
	cout << static_cast<int>(Category::PlayerAircraft) << endl;
	cout << static_cast<int>(Category::AllliedAircraft) << endl;
	cout << static_cast<int>(Category::EnemyAircraft) << endl;


	int a = static_cast<int>(Category::Scene);
	std::cout << "a = " << std::bitset<8>(a) << std::endl;

	int b = static_cast<int>(Category::Pixkup);
	std::cout << std::hex << b << endl;

}