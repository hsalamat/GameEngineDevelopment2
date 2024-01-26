#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#pragma region step 3
#include <Category.hpp>
#pragma endregion

#include <vector>
#include <memory>


#pragma region step 7
struct Command;
#pragma endregion

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;


	public:
								SceneNode();

		void					attachChild(Ptr child);
		Ptr						detachChild(const SceneNode& node);
		
		void					update(sf::Time dt);

		sf::Vector2f			getWorldPosition() const;
		sf::Transform			getWorldTransform() const;

#pragma region step 8
		void					onCommand(const Command& command, sf::Time dt);
		virtual unsigned int	getCategory() const;
#pragma endregion



	private:
		virtual void			updateCurrent(sf::Time dt);
		void					updateChildren(sf::Time dt);

		virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		std::vector<Ptr>		mChildren;
		SceneNode*				mParent;
};

