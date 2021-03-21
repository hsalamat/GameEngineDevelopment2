#pragma once
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>

#pragma region step 7-1
#include <TextNode.hpp>
#pragma endregion


class Aircraft : public Entity
{
	public:
		enum Type
		{
			Eagle,
			Raptor,
#pragma region step 7-2
			TypeCount
#pragma endregion
		};


	public:
#pragma region step 7-3
		Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);
#pragma endregion
		virtual unsigned int	getCategory() const;


	private:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Type					mType;
		sf::Sprite				mSprite;

#pragma region step 7-4
		TextNode*				mHealthDisplay;
		void					updateTexts();
#pragma endregion
};

