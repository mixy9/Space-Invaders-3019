#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>  
#include <conio.h> 

#include <ctime>
#include <mutex>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <memory>
#include <thread> 
#include <cassert>
#include <sstream>
#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <exception>
#include <functional> 
#include <unordered_map> 

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.h"


template <typename T>
using sPtr = std::shared_ptr<T>;


namespace Vector
{
	inline double PI()
	{
		return std::acos(-1);
	}

	/* Understanding how to calculate the length (also known as magnitude) of a vector we use Pythagoras formula to 
	   describe the relationship between the sides and hypotenuse of a right triangle. 
	   The Pythagorean theorem is: a² + b² = c² or √a² + b². Armed with this formula, we can now compute the magnitude 
	   of vector as follows: */
	inline sf::Vector2f normalise(sf::Vector2f vector)
	{
		// Length of vector
		float magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
		return sf::Vector2f(vector.x, vector.y) / magnitude;
	}

	/* To convert from slope to radians it's atan. One radian is equivalent to 180 / PI degrees. 
	   Therefore we can use atan2 for our vector to compute arc tangent with two parameters. */
	inline float Angle(sf::Vector2f vector)
	{   
		return (atan2(vector.y, vector.x) * 180 / PI()) + 90u;
	}
}


namespace Screen
{
	extern sf::RenderWindow window;

	extern unsigned int screenWidth;
	extern unsigned int screenHeight;
}


namespace Filename
{
	// Fonts:
	extern cStr font;
	extern cStr font2;

	// Textures: 
	extern cStr projectile; 
	extern cStr player;
	extern cStr crosshair;
	extern cStr explosion;
	extern cStr enemy;
	extern cStr enemy2;
	extern cStr background;
	extern cStr endBackground;
	extern cStr playBackground; 

	// Audio:
	extern cStr laserSound; 
	extern cStr musicFilename; 
}


