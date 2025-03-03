#pragma once

#include <Category.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>


struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;


	public:
#pragma region step 5 - 1
		//SceneNode();
		explicit				SceneNode(Category::Type category = Category::None);
#pragma endregion							

		void					attachChild(Ptr child);
		Ptr						detachChild(const SceneNode& node);		

		sf::Vector2f			getWorldPosition() const;
		sf::Transform			getWorldTransform() const;

		void					onCommand(const Command& command, sf::Time dt);
		virtual unsigned int	getCategory() const;
		void					update(sf::Time dt, CommandQueue& commands);

	private:
		virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
		void					updateChildren(sf::Time dt, CommandQueue& commands);
		virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		std::vector<Ptr>		mChildren;
		SceneNode*				mParent;
#pragma region step 5 - 2
		Category::Type			mDefaultCategory;
#pragma endregion

};


