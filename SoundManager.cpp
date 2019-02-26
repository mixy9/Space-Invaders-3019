#include "stdafx.h"
#include "SoundManager.h"


// Initializing static variables
SoundManager* SoundManager::instance = nullptr;
SoundManager::MusicState SoundManager::currentState = MusicState::PLAYING;

SoundManager::SoundManager()
{
}

SoundManager* SoundManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SoundManager;
	}
	return instance;
}

void SoundManager::playSound(Resource::ID id, std::string filename)
{
	m_sound = std::make_shared<sf::Sound>();
	m_soundBuffer.load(id, filename);
	m_sound->setBuffer(*m_soundBuffer.get(filename));
	m_sound->play();
	m_sound->setPitch(2);
	m_sound->setVolume(20);  
}

void SoundManager::getVolume(int number)
{
	m_music.setVolume(m_music.getVolume() + number);
}

void SoundManager::playMusic(std::string filename)
{
	if (isPlaying())
	{
		if (!m_music.openFromFile(filename))
		{
			throw std::runtime_error("Error! Failed to open music file " + filename);
		}
		else 
		{
			m_music.play();
			m_music.setVolume(10);
			m_music.setLoop(true);
		}
	}
}

void SoundManager::pauseMusic()
{
	m_music.pause();
}

void SoundManager::stopMusic()
{
	m_music.stop();
}

bool SoundManager::isPaused()
{
	return currentState == MusicState::PAUSED;
}

bool SoundManager::isPlaying()
{
	return currentState == MusicState::PLAYING;
}

SoundManager::~SoundManager()
{
	if (instance)
		delete instance;
}
