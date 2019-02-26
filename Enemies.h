#pragma once
#include "Enemy.h"
#include "Player.h"
#include "SoundManager.h"


class Enemies : public Enemy
{
private: 
	std::vector<sPtr<Enemy>> m_enemies; 
	sf::Vector2f m_position;
	Enemy* m_enemy;

	unsigned int m_enemySpawnTimer = 0; 

public:
	friend class Projectile;

	Enemies();
	~Enemies();
	
	void collideWithPlayer(Player& player);
	void dir(Player& player);
	void destroyEnemy();
	void clearEnemies();

	virtual void draw();
	virtual void initialize();
	virtual void update(sf::Time& elapsedTime);
};

