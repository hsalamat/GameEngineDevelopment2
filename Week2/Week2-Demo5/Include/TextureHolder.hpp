#pragma once
#include <string> //std::string
#include <SFML\Graphics.hpp>   //sf::Texture


//namespace provides a method for preventing name conflicts
namespace Textures {
	enum ID
	{
		Landscape,
		Airplane
	};
}

class TextureHolder {
private:
	//sf::Texture mTexture;
	std::map<Textures::ID, sf::Texture> mTextureMap;
public:
	void load(Textures::ID, std::string filename);
	sf::Texture get(Textures::ID);
};
