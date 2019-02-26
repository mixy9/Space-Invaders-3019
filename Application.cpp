/* Mihaela Trempetiæ
2019
*/

#include "stdafx.h"
#include "Application.h"



Application::Application()
{
}

int Application::execute()
{
	while (Screen::window.isOpen())
	{
		Screen::window.clear();
		display();
		Screen::window.display();
		processEvents();
		update();
	}
	return EXIT_SUCCESS;
}

bool Application::initialize()
{
	Screen::window.setMouseCursorVisible(false);
	Screen::window.setKeyRepeatEnabled(false);
	Screen::window.setFramerateLimit(60);

	pEnemy = nullptr; 
	gameDesign.initialize();
	player.initialize();
	enemies.initialize(); 

	SoundManager::getInstance()->playMusic(Filename::musicFilename);

	return true;
}

void Application::update()
{
	delta = clock.restart();
	delta = clock.getElapsedTime();
	gameDesign.update(delta);
	
	if (gameState == GameState::PLAYING)
	{ 
		mouseScreenPosition = sf::Mouse::getPosition();
		mouseWorldPosition = Screen::window.mapPixelToCoords(sf::Mouse::getPosition());
 
		player.update(delta);

		projectile.trackMouse(mouseWorldPosition, player);
		projectile.update(delta);
		projectile.deleteProjectiles();
		projectile.collisionWithEnemy(enemies, player);
		 
		enemies.update(delta);
		enemies.collideWithPlayer(player); 

		if (player.win())
		{
			gameState = GameState::END;
		}
		if (player.lose())
		{
			gameState = GameState::GAME_OVER;
		}
	}
	else if (gameState == GameState::END || gameState == GameState::GAME_OVER)
	{
		SoundManager::getInstance()->stopMusic();
		clock.restart();
		enemies.clearEnemies();
	}
}

void Application::display()
{
	switch (gameState)
	{
	case GameState::INTRO:
		gameDesign.draw();
		break; 
	case GameState::PLAYING:
		gameDesign.drawPlay(); 
		player.draw();
		projectile.draw();
		enemies.draw();
		break;
	case GameState::END:
		gameDesign.drawEnd();
		player.drawResult();
		break;
	case GameState::GAME_OVER:
		gameDesign.drawEnd(); 
		player.drawGameOver();
		break;
	}
}

void Application::processEvents()
{
	while (Screen::window.pollEvent(Event))
	{
		if ((Event.type == sf::Event::Closed) || (Event.type == sf::Event::KeyPressed)
			&& (Event.key.code == sf::Keyboard::Escape))
		{
			Screen::window.close();
		} 
		if (Event.type == sf::Event::MouseWheelMoved)
		{
			int mouseDelta = 0;
			mouseDelta += Event.mouseWheel.delta;
			SoundManager::getInstance()->getVolume(mouseDelta); 
		}
		if (Event.type == sf::Event::KeyPressed)
		{
			if (gameState == GameState::INTRO)
			{
				gameState = GameState::PLAYING;
				player.resetScore();
			}
			if (gameState == GameState::END || gameState == GameState::GAME_OVER)
			{ 
				if (Event.key.code == sf::Keyboard::Up)
				{
					gameDesign.moveUp(); 
				}
				else if (Event.key.code == sf::Keyboard::Down)
				{
					gameDesign.moveDown();
				}
				else if (Event.key.code == sf::Keyboard::Return)
				{
					switch (gameDesign.getPressedItem())
					{
					case 0:
						gameState = GameState::INTRO; 
						SoundManager::getInstance()->playMusic(Filename::musicFilename);
						break;
					case 1:
						Screen::window.close();
						break;   
					} 
				}
			} 
		} // End of key event type 
	}
}

Application::~Application()
{
}
