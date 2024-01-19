#pragma once
#pragma region Step1

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <SFML\Graphics.hpp>

//class TextureHolder
template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void						load(Identifier id, const std::string& filename);

	Resource&					get(Identifier id);
	const Resource&				get(Identifier id) const;

private:
	std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
};

#include "ResourceHolder.inl"

#pragma endregion