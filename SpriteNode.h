#pragma once

#include "stdafx.h"
#include "ResourceHolder.h"



class SpriteNode : public sf::Sprite
{
private:
	ResourceHolder<sf::Texture> m_texture;

public:

	SpriteNode() {};

	~SpriteNode() {};

	SpriteNode(cStr texture, float positionX, float positionY, float scaleX, float scaleY)
	{
		m_texture.load(Resource::Textures, texture);
		this->setTexture(*m_texture.get(texture));
		this->setPosition(sf::Vector2f(Screen::screenWidth / positionX, Screen::screenHeight / positionY));
		this->setScale(sf::Vector2f(Screen::screenWidth / scaleX, Screen::screenHeight / scaleY));
	}
};

