#pragma once

#include <Category.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <set>
#include <memory>
#include <utility>


struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;

#pragma region step 3 - 1
		//We store the pointers to colliding entities in Pair
		typedef std::pair<SceneNode*, SceneNode*> Pair;
#pragma endregion

	public:
		explicit				SceneNode(Category::Type category = Category::None);

		void					attachChild(Ptr child);
		Ptr						detachChild(const SceneNode& node);
		
		void					update(sf::Time dt, CommandQueue& commands);

		sf::Vector2f			getWorldPosition() const;
		sf::Transform			getWorldTransform() const;

		void					onCommand(const Command& command, sf::Time dt);
		virtual unsigned int	getCategory() const;


#pragma region step 3 - 2
		//We need to compare every scene node with every scene node to determine if a collision between two occurs

		//1. First we evaluates a collision between a node and its children			
		void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);

		//2. check the whole scene graph against all nodes
		void					checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);

		void					removeWrecks();
		virtual sf::FloatRect	getBoundingRect() const;
		virtual bool			isMarkedForRemoval() const;
		virtual bool			isDestroyed() const;

#pragma endregion


	private:
		virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
		void					updateChildren(sf::Time dt, CommandQueue& commands);

		virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

#pragma region step 3-3
		void					drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;

#pragma endregion


	private:
		std::vector<Ptr>		mChildren;
		SceneNode*				mParent;
		Category::Type			mDefaultCategory;
};

float	distance(const SceneNode& lhs, const SceneNode& rhs);

#pragma region step 3-4
bool	collision(const SceneNode& lhs, const SceneNode& rhs);
#pragma endregion



