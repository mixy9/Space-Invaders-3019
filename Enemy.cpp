#include "stdafx.h"
#include "Enemy.h" 


Enemy::Enemy() 
{
}

Enemy::Enemy(sPtr<SpriteNode>& enemySprite) 
{   
	this->m_alive = true; 

	this->m_sprite = std::make_shared<SpriteNode>(Filename::enemy, NULL, NULL, 2500.f, 1700.f);
	this->m_sprite->setPosition(rand() % Screen::screenWidth, 0.f);
	this->m_sprite->setOrigin(100.f, 100.f);
	this->m_health = ENEMY_HEALTH; 
}

int Enemy::decreaseHealth()
{
	return this->m_health--;
}

bool Enemy::isDead()
{ 
	return this->m_health == 0;
}

bool Enemy::isAlive(bool alive)
{
	return this->m_alive == alive;
}

sf::FloatRect Enemy::getGlobalBounds()
{
	 return m_sprite->getGlobalBounds();
}

sf::Vector2f Enemy::enemyCenter()
{
	return sf::Vector2f(m_sprite->getPosition().x, m_sprite->getPosition().y);
}

void Enemy::setPosition(float posX, float posY)
{
	m_sprite->setPosition(posX, posY);
}

void Enemy::draw()
{ 
	Screen::window.draw(*m_sprite); 
}

bool Enemy::animateEnemyExplosion()
{
	if (clock.getElapsedTime().asMilliseconds() > 100.f)
	{
		if (m_rectSprite.left == LAST_RECTANGLE)
		{
			m_rectSprite.left = NULL;
			m_rectSprite.top += (LAST_RECTANGLE / 3);
		}
		else
		{
			m_rectSprite.left += (LAST_RECTANGLE / 3);
		} 
		m_explosion.setTextureRect(m_rectSprite);
		clock.restart();
	}
	return true;
}

void Enemy::update(sf::Time& elapsedTime)
{ 
	m_sprite->move(0.f, 2.f); 
}

Enemy::~Enemy()
{
}



