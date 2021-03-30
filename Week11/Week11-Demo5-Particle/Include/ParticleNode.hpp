#pragma region step 5
#pragma once

#include <SceneNode.hpp>
#include <ResourceIdentifiers.hpp>
#include <Particle.hpp>

#include <SFML/Graphics/VertexArray.hpp>

#include <deque>


class ParticleNode : public SceneNode
{
public:
	ParticleNode(Particle::Type type, const TextureHolder& textures);

	void					addParticle(sf::Vector2f position);
	Particle::Type			getParticleType() const;
	virtual unsigned int	getCategory() const;


private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	void					addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
	void					computeVertices() const;


private:
	std::deque<Particle>	mParticles;
	const sf::Texture&		mTexture;
	Particle::Type			mType;

	//mVertexArray is mutable, since it's not part of the object's logical state.
	//This allows optimizations. We only rebuild the vertex array if something has changed, 
	//and directly before drawing (instead of after each update0
	mutable sf::VertexArray	mVertexArray;
	mutable bool			mNeedsVertexUpdate;
};



#pragma endregion

