#pragma once
#include "stdafx.h"
#include "Enemy.h"
#include "Enemies.h"
#include "GameDesign.h" 
#include "Projectile.h"


class Application
{
private:
	GameDesign gameDesign;
	Enemies enemies;
	Enemy* pEnemy;
	Player player;
	Projectile projectile; 
	sf::Time delta;
	sf::Clock clock;

	sf::Event Event;

	sf::Vector2f mouseWorldPosition;
	sf::Vector2i mouseScreenPosition;

	enum class GameState
	{
		INTRO, PLAYING, GAME_OVER, END
	};
	GameState gameState = GameState::INTRO;

public:
	Application();

	int execute();

	bool initialize();

	void update();
	void display(); 
	void processEvents();

	~Application();
};

