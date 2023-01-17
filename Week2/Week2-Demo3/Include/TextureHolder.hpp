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

enum class TexturesID {
	Landscape,
	Airplane
};


class TextureHolder {
private:
	//sf::Texture mTexture;
	std::map<Textures::ID, sf::Texture> mTextureMap;
	std::map<TexturesID, sf::Texture> mTextureMap2;
public:
	void load(Textures::ID, std::string filename);
	void load(TexturesID, std::string filename);

	sf::Texture get(Textures::ID);
	sf::Texture get(TexturesID);
};
