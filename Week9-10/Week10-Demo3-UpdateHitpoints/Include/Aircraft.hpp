#pragma once
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <TextNode.hpp>
#pragma region step 1-1
#include <Command.hpp>
#pragma endregion


class Aircraft : public Entity
{
	public:
		enum Type
		{
			Eagle,
			Raptor,
#pragma region step 1-2
			Avenger,
#pragma endregion
			TypeCount
		};


	public:
		Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);
		virtual unsigned int	getCategory() const;


	private:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

#pragma region step 1-3
		virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
#pragma endregion

	private:
		Type					mType;
		sf::Sprite				mSprite;
		TextNode*				mHealthDisplay;
		void					updateTexts();

};

