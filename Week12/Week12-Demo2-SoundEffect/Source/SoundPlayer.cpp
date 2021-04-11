#pragma region step 5
#include <SoundPlayer.hpp>

#include <SFML/Audio/Listener.hpp>

#include <cmath>


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

void SoundPlayer::play(SoundEffect::ID effect)
{
	mSounds.push_back(sf::Sound(mSoundBuffers.get(effect)));
	mSounds.back().play();
}



void SoundPlayer::removeStoppedSounds()
{
	mSounds.remove_if([](const sf::Sound& s)
	{
		return s.getStatus() == sf::Sound::Stopped;
	});
}

#pragma endregion
