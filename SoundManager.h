#pragma once

#include "stdafx.h"
#include "ResourceHolder.h"



class SoundManager
{
private:
	ResourceHolder<sf::SoundBuffer> m_soundBuffer;

	static SoundManager* instance;

	sPtr<sf::Sound> m_sound;
	sf::Music m_music;

	SoundManager();

	enum class MusicState
	{
		PLAYING,
		PAUSED
	};
	static MusicState currentState;

public:
	static SoundManager* getInstance();

	void playSound(Resource::ID id, std::string filename);
	void playMusic(std::string filename);
	void pauseMusic();
	void stopMusic();
	void getVolume(int number);

	bool isPaused();
	bool isPlaying();

	~SoundManager();
};


