#include "stdafx.h"
#include "Enemies.h"



Enemies::Enemies()  
{
}

void Enemies::initialize()
{   
	m_texture.load(Resource::Textures, Filename::explosion);
	m_rectSprite = (sf::IntRect(0, 0, 128, 128)); 
	/*if (m_alive == false)
	{
		m_explosion.setTexture(*m_texture.get(Filename::explosion));
		m_explosion.setTextureRect(m_rectSprite);
	}*/
}

void Enemies::clearEnemies()
{
	m_enemies.clear();
}

void Enemies::draw()
{
	Screen::window.draw(m_explosion);
	for (auto& enemy : m_enemies)
	{
		enemy->draw();
	} 
}

void Enemies::dir(Player& player)
{
	//m_direction = Vector::normalise(player.playerCenter() - m_orangeEnemy->getPosition());
	//m_velocity = m_direction * 10.f;
	//m_sprite->setRotation(Vector::Angle(m_direction));

	//if (player.getPosition().x > m_sprite->getPosition().x)
	//{
	//	m_sprite->move(m_sprite->getPosition() / (m_speed * elapsedTime));
	//}

	//if (player.getPosition().x < m_sprite->getPosition().x)
	//{
	//	m_sprite->move(m_sprite->getPosition() / (m_speed * elapsedTime));
	//}

	//if (player.getPosition().y > m_sprite->getPosition().y)
	//{
	//	m_sprite->move(m_sprite->getPosition() / (m_speed * elapsedTime));
	//}

	//if (player.getPosition().y < m_sprite->getPosition().y)
	//{
	//	m_sprite->move(m_sprite->getPosition() / (m_speed * elapsedTime));
	//}
}

void Enemies::collideWithPlayer(Player& player)
{
	for (auto& e : m_enemies)
	{
		if (e->getGlobalBounds().intersects(player.m_sprite->getGlobalBounds()))
		{
			player.m_health--; 
		}
	}  
}

void Enemies::destroyEnemy()
{
	std::vector<sPtr<Enemy>>::iterator deleteEnemies = std::remove_if(m_enemies.begin(), m_enemies.end(),
	[](sPtr<Enemy> enemy)
	{
		return enemy->isDead() || enemy->getPosition().x >= Screen::screenWidth;
	});
	m_enemies.erase(deleteEnemies, m_enemies.end());
}

void Enemies::update(sf::Time& elapsedTime)
{ 
	if (m_enemySpawnTimer >= ENEMY_TIMER)
	{
		m_enemies.push_back(std::make_shared<Enemy>(m_sprite)); 
		m_enemySpawnTimer = 0;
	}
	else m_enemySpawnTimer++;

	for (auto& e : m_enemies) 
	{ 
		e->update(elapsedTime);
	}
	this->destroyEnemy();
}

Enemies::~Enemies()
{
}