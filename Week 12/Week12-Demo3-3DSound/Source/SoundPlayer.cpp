#include <SoundPlayer.hpp>

#include <SFML/Audio/Listener.hpp>

#include <cmath>

#pragma region step 2

namespace
{
	// Sound coordinate system, point of view of a player in front of the screen:
	// X = left; Y = up; Z = back (out of the screen)

	//The distance between the listener and the screen plane
	const float ListenerZ = 300.f;

	//Attenuation factor determines how fast a sound is attenuated depending on the distance
	//the higher the factor, the weaker the sound becomes for a given distance
	const float Attenuation = 8.f;

	//2D minimum distance is the number of world units between the listener's place in 2D world and the sound
	const float MinDistance2D = 200.f;

	//3D minimum distance has to be computed with the Pythagorean theorem
	const float MinDistance3D = std::sqrt(MinDistance2D*MinDistance2D + ListenerZ*ListenerZ);
}

#pragma endregion

SoundPlayer::SoundPlayer()
	: mSoundBuffers()
	, mSounds()
{
	mSoundBuffers.load(SoundEffect::AlliedGunfire, "Media/Sound/AlliedGunfire.wav");
	mSoundBuffers.load(SoundEffect::EnemyGunfire, "Media/Sound/EnemyGunfire.wav");
	mSoundBuffers.load(SoundEffect::Explosion1, "Media/Sound/Explosion1.wav");
	mSoundBuffers.load(SoundEffect::Explosion2, "Media/Sound/Explosion2.wav");
	mSoundBuffers.load(SoundEffect::LaunchMissile, "Media/Sound/LaunchMissile.wav");
	mSoundBuffers.load(SoundEffect::CollectPickup, "Media/Sound/CollectPickup.wav");
	mSoundBuffers.load(SoundEffect::Button, "Media/Sound/Button.wav");

	// Listener points towards the screen (default in SFML)
	sf::Listener::setDirection(0.f, 0.f, -1.f);
}

#pragma region step 3
void SoundPlayer::play(SoundEffect::ID effect)
{
	//mSounds.push_back(sf::Sound(mSoundBuffers.get(effect)));
	//mSounds.back().play();

	//getListenerPosition functions transforms the 3D listener position back to 2D graphice coordinates
	play(effect, getListenerPosition());
}

//play() functions takes a 2D graphices position and computes 3D audio position by negating Y and set Z=0
void SoundPlayer::play(SoundEffect::ID effect, sf::Vector2f position)
{
	mSounds.push_back(sf::Sound());
	sf::Sound& sound = mSounds.back();

	sound.setBuffer(mSoundBuffers.get(effect));
	sound.setPosition(position.x, -position.y, 0.f);
	sound.setAttenuation(Attenuation);
	sound.setMinDistance(MinDistance3D);

	sound.play();
}

#pragma endregion

void SoundPlayer::removeStoppedSounds()
{
	mSounds.remove_if([](const sf::Sound& s)
	{
		return s.getStatus() == sf::Sound::Stopped;
	});
}

void SoundPlayer::setListenerPosition(sf::Vector2f position)
{
	sf::Listener::setPosition(position.x, -position.y, ListenerZ);
}

sf::Vector2f SoundPlayer::getListenerPosition() const
{
	sf::Vector3f position = sf::Listener::getPosition();
	return sf::Vector2f(position.x, -position.y);
}

