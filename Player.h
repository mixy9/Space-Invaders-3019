#pragma once

#include "stdafx.h"

#include "TextNode.h"
#include "GameObject.h"
#include "SpriteNode.h" 



class Player : public GameObject
{
protected:
	std::unique_ptr<SpriteNode> m_sprite, m_crosshair;
	sPtr<TextNode> m_hudScore, m_hudHealth, m_result, m_star;
	sf::Int32 m_updateTime;
	sf::Clock m_clock;

	static const int m_distance = 40;
	unsigned int m_seconds, m_score, m_health;

public:
	Player();
	~Player();

	friend class Projectile;
	friend class Enemies;

	sf::Vector2f playerCenter();
	sf::Sprite& setSprite();
	 
	void drawResult();
	void resetScore();

	bool win();
	bool lose();

	virtual void draw();
	virtual void initialize();
	virtual void update(sf::Time& elapsedTime);
};

