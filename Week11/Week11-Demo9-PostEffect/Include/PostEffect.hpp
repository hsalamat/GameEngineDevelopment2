#pragma region step 1
#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <ResourceIdentifiers.hpp>
#include <ResourceHolder.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <array>
namespace sf
{
	class RenderTarget;
	class RenderTexture;
	class Shader;
}

class PostEffect : sf::NonCopyable
{
public:
	PostEffect();
	virtual					~PostEffect();
	virtual void			apply(const sf::RenderTexture& input, sf::RenderTarget& output);

	static bool				isSupported();


protected:
	static void				applyShader(const sf::Shader& shader, sf::RenderTarget& output);

private:
	ShaderHolder		mShaders;
	typedef std::array<sf::RenderTexture, 2> RenderTextureArray;

	sf::RenderTexture	mBrightnessTexture;
	RenderTextureArray	mFirstPassTextures;
	RenderTextureArray	mSecondPassTextures;

	void				prepareTextures(sf::Vector2u size);
	void				filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
	void				blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
	void				blurMultipass(RenderTextureArray& renderTextures);
	void				downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
	void				add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& target);

};

#pragma endregion

