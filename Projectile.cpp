#include "stdafx.h"
#include "Projectile.h"


Projectile::Projectile() :
	m_speed(17.f),
	m_velocity(0.f, 0.f),
	m_projectileTimer(0)
{
	m_sprite = std::make_shared<SpriteNode>(Filename::projectile, NULL, NULL, 3200.f, 1500.f);
	m_sprite->setOrigin(31.f, 57.f);
}

void Projectile::trackMouse(sf::Vector2f mousePos, Player &player)
{  
	player.m_crosshair->setPosition(mousePos);
	m_aimDirection = Vector::normalise(mousePos - player.playerCenter());
	player.m_sprite->setRotation(Vector::Angle(m_aimDirection));
	m_sprite->setRotation(Vector::Angle(m_aimDirection));
	this->shoot(player);
}

void Projectile::deleteProjectiles()
{
	// If projectiles are out of window bounds, delete them.
	std::vector<sPtr<SpriteNode>>::iterator deleteProjectiles = std::remove_if(m_projectiles.begin(), m_projectiles.end(),
	[](sPtr<SpriteNode> projectile)
	{
		return projectile->getPosition().y <= 0 || projectile->getPosition().y >= Screen::screenHeight ||
			   projectile->getPosition().x <= 0 || projectile->getPosition().x >= Screen::screenWidth;
	});
	m_projectiles.erase(deleteProjectiles, m_projectiles.end());
}

void Projectile::collisionWithEnemy(Enemies& e, Player& player)
{ 
	for (auto i = 0; i < m_projectiles.size(); i++)
	{
		for (auto j = 0; j < e.m_enemies.size(); j++)
		{ 
			// Collision of projectiles and enemies.
			if (m_projectiles[i]->getGlobalBounds().intersects(e.m_enemies[j]->getGlobalBounds()))
			{ 
				e.m_enemies[j]->decreaseHealth();
				m_projectiles.erase(m_projectiles.begin() + i); 
				if (e.m_enemies[j]->isDead())
				{
					// Increase player's score when an enemy is destroyed.
					player.m_score++;
					e.m_alive = false;
				}
				break; 
			}
		}
	}
}

void Projectile::draw()
{
	for (auto& p : m_projectiles)
	{
		Screen::window.draw(*p);
	}
}

void Projectile::shoot(Player& player)
{
	// Shoot'Em Up.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_projectileTimer >= PROJECTILE_TIMER)
	{
		m_sprite->setPosition(player.playerCenter());
		m_velocity = m_aimDirection * m_speed;
		m_projectiles.push_back(std::make_shared<SpriteNode>(*m_sprite));
		SoundManager::getInstance()->playSound(Resource::Sounds, Filename::laserSound);
		m_projectileTimer = 0; 
	}
	else m_projectileTimer++; 
}

void Projectile::update(sf::Time& elapsedTime)
{ 
	for (auto& projectiles : m_projectiles)
	{
		// Projectiles move in the mouse direction. 
		projectiles->move(m_velocity);
	}
}

Projectile::~Projectile()
{
}
