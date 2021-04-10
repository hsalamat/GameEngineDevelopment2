#pragma region step 4
#ifndef BOOK_SOUNDPLAYER_HPP
#define BOOK_SOUNDPLAYER_HPP

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>


class SoundPlayer : private sf::NonCopyable
{
public:
	SoundPlayer();

	void						play(SoundEffect::ID effect);
	void						removeStoppedSounds();


private:
	SoundBufferHolder			mSoundBuffers;
	std::list<sf::Sound>		mSounds;
};

#endif // BOOK_SOUNDPLAYER_HPP

#pragma endregion

