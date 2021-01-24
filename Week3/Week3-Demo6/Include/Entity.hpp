#pragma region step 3
#pragma once
#include <SceneNode.hpp>


class Entity : public SceneNode

{
public:
	virtual	void		updateCurrent(sf::Time dt);
	//virtual	void		update(sf::Time dt);

#pragma endregion

	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;


public:
	sf::Vector2f		mVelocity;
};


