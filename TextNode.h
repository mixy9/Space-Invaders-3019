#pragma once

#include "stdafx.h"
#include "ResourceHolder.h"


class TextNode : public sf::Text
{
private:
	ResourceHolder<sf::Font> m_font;

public:

	TextNode() {};

	~TextNode() {};

	TextNode(cStr string, size_t size, float positionX, float positionY, sf::Color(color), cStr font)
	{
		m_font.load(Resource::Fonts, font);
		this->setString(string);
		this->setFont(*m_font.get(font));
		this->setFillColor(sf::Color(color));
		this->setCharacterSize(Screen::screenWidth / size);
		this->setPosition(sf::Vector2f(Screen::screenWidth / positionX, Screen::screenHeight / positionY));
	}
};