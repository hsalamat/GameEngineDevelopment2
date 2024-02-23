#pragma once
#include <Entity.hpp>
#include <ResourceIdentifiers.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <Command.hpp>
#include <TextNode.hpp>

class Aircraft : public Entity
{
	public:
		enum Type
		{
			Eagle,
			Raptor,
			Avenger,
			TypeCount
		};

	public:
		Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);
		virtual unsigned int	getCategory() const;
#pragma region step 3 - 1
		float					getMaxSpeed() const;
#pragma endregion

	private:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
		Type					mType;
		sf::Sprite				mSprite;
		TextNode*				mHealthDisplay;
		void					updateTexts();

#pragma region step 3 - 2
		//The distance already travelled for each direction
		float					mTravelledDistance;

		//which direction the plane is currently taking
		std::size_t				mDirectionIndex;

		//check if there are movement patterns for current type, otherwise the plane flies straight down
		void					updateMovementPattern(sf::Time dt);
#pragma endregion

};

