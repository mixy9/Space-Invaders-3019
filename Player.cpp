#include "stdafx.h"
#include "Player.h"


Player::Player() :
	m_score(0),
	m_seconds(0),
	m_health(100)
{
	m_sprite = std::make_unique<SpriteNode>(Filename::player, 1.7f, 1.2f, 3000.f, 2200.f);
	m_sprite->setOrigin(125.f, 140.f);
}

sf::Vector2f Player::playerCenter()
{
	return sf::Vector2f(m_sprite->getPosition().x, m_sprite->getPosition().y);
}

sf::Sprite& Player::setSprite()
{
	return *m_sprite;
}

void Player::initialize()
{
	m_crosshair = std::make_unique<SpriteNode>(Filename::crosshair, NULL, NULL, 3000.f, 1800.f);
	m_crosshair->setOrigin(75.f, 72.f);

	m_result = std::make_shared<TextNode>("", 34u, 36.f, 5.2f, sf::Color::White, Filename::font);
	m_hudScore = std::make_shared<TextNode>("", 36u, 1.25f, 1.13f, sf::Color(51, 173, 255), Filename::font);
	m_hudHealth = std::make_shared<TextNode>("", 36u, 45.f, 1.13f, sf::Color(51, 173, 255), Filename::font);

	m_sprite->setPosition((float)Screen::screenWidth / 2.f, (float)Screen::screenHeight / 2.f); 
}
 
void Player::drawResult()
{
	Screen::window.draw(*m_result);
}

void Player::resetScore()
{
	m_score = 0;
	m_health = 100;
}

bool Player::win()
{
	return m_score == 3;
}

bool Player::lose()
{
	return m_health == 0;
}

void Player::draw()
{
	Screen::window.draw(*m_hudScore);
	Screen::window.draw(*m_hudHealth);
	Screen::window.draw(*m_crosshair);
	Screen::window.draw(*m_sprite);
}

void Player::update(sf::Time& elapsedTime)
{
	std::stringstream hudScoreStream, hudHealthStream, resultStream;

	// Update HUD
	hudHealthStream << "Health: " << m_health << "%";
	hudScoreStream  << "Score: " << m_score;
	m_hudScore->setString(hudScoreStream.str());
	m_hudHealth->setString(hudHealthStream.str());

	// Update results
	resultStream << "Congratulations,\nyou saved the Earth!\n\nYour score: " << m_score;
	m_result->setString(resultStream.str());
	m_updateTime = m_clock.restart().asMilliseconds();

	// Player's movement and collision with window bounds
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_sprite->getPosition().x > 70.f)
	{
		m_sprite->move(-m_distance * m_updateTime / 50.0, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_sprite->getPosition().x <= Screen::screenWidth - 70.f)
	{
		m_sprite->move(m_distance * m_updateTime / 50.0, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_sprite->getPosition().y > 70.f)
	{
		m_sprite->move(0, -m_distance * m_updateTime / 50.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_sprite->getPosition().y <= Screen::screenHeight - 70.f)
	{
		m_sprite->move(0, m_distance * m_updateTime / 50.0);
	}
}

Player::~Player()
{
}
