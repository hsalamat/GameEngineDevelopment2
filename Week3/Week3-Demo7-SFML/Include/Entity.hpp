
#pragma once
#include <SceneNode.hpp>


class Entity : public SceneNode

{
public:
	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;

	virtual	void		updateCurrent(sf::Time dt);

public:
	sf::Vector2f		mVelocity;
};

