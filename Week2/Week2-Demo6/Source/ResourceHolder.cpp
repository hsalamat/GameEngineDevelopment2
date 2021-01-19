#pragma region step 2

#include "Book\ResourceHolder.hpp"
#include <SFML\Graphics.hpp>

//void TextureHolder::load(Textures::ID id, const std::string &filename) {
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	//std::unique_ptr<sf::Texture> texture(new sf::Texture());
	// Create and load resource
	std::unique_ptr<Resource> resource(new Resource());

	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	// If loading successful, insert resource to map
	mResourceMap.insert(std::make_pair(id, std::move(resource)));
}



//sf::Texture& TextureHolder::get(Textures::ID id)
template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}


//const sf::Texture& TextureHolder::get(Textures::ID id) const
template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

#pragma endregion