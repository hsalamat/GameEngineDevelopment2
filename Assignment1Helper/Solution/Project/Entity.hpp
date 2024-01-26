#pragma once
#include "SceneNode.hpp"

class Entity :
    public SceneNode
{
public:
	Entity(Game* game);
	void				setVelocity(XMFLOAT2 velocity);
	void				setVelocity(float vx, float vy);
	XMFLOAT2			getVelocity() const;

	virtual	void		updateCurrent(const GameTimer& gt);

public:
	XMFLOAT2		mVelocity;
};

