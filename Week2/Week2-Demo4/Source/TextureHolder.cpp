#include <TextureHolder.hpp>

void TextureHolder::load(Textures::ID id, const std::string& filename)
{
	sf::Texture mTexture;
	mTexture.loadFromFile(filename);

	std::pair<Textures::ID, sf::Texture> mPair(id,mTexture);

	mTextureMap.insert(mPair);
}

sf::Texture& TextureHolder::get(Textures::ID id)
{

	//in ideal situation
	//return mTextureMap.find(id)->second;
	//std::map<Textures::ID, sf::Texture>::iterator it;
	//it= mTextureMap.find(id);
	//if (it != mTextureMap.end())
	//	return it->second;
	//return sf::Texture();
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	return found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id)const
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	return found->second;
}
