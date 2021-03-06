#include "stdafx.h"
#include "Player.h"
#include "Enemies.h"
#include "Application.h"


extern float clamp(const float x, const float a, const float b)
{
	return std::min(std::max(a, x), b);
}

namespace Filename
{
	// Fonts:
	cStr font("Fonts/Kameleon.ttf");
	cStr font2("Fonts/Azonix.otf");

	// Textures:  
	cStr player("Graphics/spaceship.png");
	cStr crosshair("Graphics/crosshair.png");
	cStr explosion("Graphics/explosion.png");
	cStr projectile("Graphics/fire.png"); 
	cStr enemy("Graphics/enemy.png");
	cStr enemy2("Graphics/enemy3.png");
	cStr background("Graphics/background.jpg");
	cStr endBackground("Graphics/endBackground.jpg");
	cStr playBackground("Graphics/bg.jpg");

	// Audio:
	cStr laserSound("Audio/laser.wav"); 
	cStr musicFilename("Audio/musicSpace.ogg"); 
}

namespace Screen
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Invaders 3019", sf::Style::Fullscreen);

	extern unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
	extern unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;
}

int main()
{
	Application application;
	if (!application.initialize())
		return EXIT_FAILURE;
	return application.execute();
}