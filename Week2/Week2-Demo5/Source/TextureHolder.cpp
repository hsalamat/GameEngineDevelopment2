#include <TextureHolder.hpp>

void TextureHolder::load(Textures::ID id, std::string filename)
{
	sf::Texture mTexture;
	mTexture.loadFromFile(filename);

	std::pair<Textures::ID, sf::Texture> mPair(id,mTexture);

	mTextureMap.insert(mPair);
}

sf::Texture TextureHolder::get(Textures::ID id)
{

	//in ideal situation
	//return mTextureMap.find(id)->second;
	std::map<Textures::ID, sf::Texture>::iterator it;
	it= mTextureMap.find(id);
	if (it != mTextureMap.end())
		return it->second;
	return sf::Texture();
}
