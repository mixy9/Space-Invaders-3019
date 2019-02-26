#pragma once
#include "stdafx.h"
#include "ResourceHolder.h"
#include "SoundManager.h"
#include "Player.h"  
#include "Enemies.h" 


class Projectile : public GameObject
{
private: 
	std::vector<sPtr<SpriteNode>> m_projectiles;
	sf::Vector2f m_velocity, m_aimDirection;
	sPtr<SpriteNode> m_sprite;

	float m_speed;
	unsigned int m_projectileTimer;

public:
	Projectile();
	~Projectile();

	void trackMouse(sf::Vector2f mousePos, Player& player);
	void collisionWithEnemy(Enemies& e, Player& player);
	void deleteProjectiles();
	void shoot(Player& player);

	virtual void draw();
	virtual void initialize() {};
	virtual void update(sf::Time& elapsedTime);
};

