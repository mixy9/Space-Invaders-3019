#pragma once

#include "ResourceHolder.h"
#include "SpriteNode.h"
#include "GameObject.h"
#include "Player.h"



class Enemy : public GameObject
{
protected:
	sf::Vector2f m_direction, m_velocity, m_posX, m_posY;
	ResourceHolder<sf::Texture> m_texture;
	sPtr<SpriteNode> m_sprite;
	sf::IntRect m_rectSprite;
	sf::Sprite m_explosion;
	sf::Clock clock;  

	bool m_alive; 
	unsigned int m_health;

public:
	Enemy();
	~Enemy();

	Enemy(sPtr<SpriteNode>& enemySprite);

	sf::Vector2f enemyCenter();
	sf::FloatRect getGlobalBounds();

	bool isDead(); 
	bool isAlive(bool alive);
	bool animateEnemyExplosion();

	int decreaseHealth();

	void setPosition(float posX, float posY);

	virtual void draw();
	virtual void initialize() {};
	virtual void update(sf::Time& elapsedTime);
};

