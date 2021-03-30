#pragma region step 8
#pragma once

#include <SceneNode.hpp>
#include <Particle.hpp>

//Emitters can be considered purely logical scene nodes that emit particles into particle system
//They are not directly related to rendering.
//We can have multiple emitters that emit to a single particle system.
//We only need one ParticleNode instance per effect, even with dozens of emitter
//EmitterNode is attached to a missile. As soon as particles have been emitted, they are managed by particle node.

class ParticleNode;

class EmitterNode : public SceneNode
{
public:
	explicit				EmitterNode(Particle::Type type);


private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);

	void					emitParticles(sf::Time dt);


private:
	sf::Time				mAccumulatedTime;
	Particle::Type			mType;
	ParticleNode*			mParticleSystem; //The pointer mParticleSystem points to the ParticleNode into which the EmitterNode emits particle
};

#pragma endregion

