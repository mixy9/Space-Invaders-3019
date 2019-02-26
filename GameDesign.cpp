#include "stdafx.h"
#include "GameDesign.h"


GameDesign::GameDesign() :
	m_currentlySelectedItem(0)
{
}

void GameDesign::initialize()
{  
	backgroundSprite = std::make_shared<SpriteNode>(Filename::background, Screen::screenWidth, Screen::screenHeight, NULL, NULL);
	backgroundSprite->setScale(Screen::screenWidth / backgroundSprite->getLocalBounds().width, Screen::screenHeight / backgroundSprite->getLocalBounds().height);

	playBackground = std::make_shared<SpriteNode>(Filename::playBackground, Screen::screenWidth, Screen::screenHeight, NULL, NULL);
	playBackground->setScale(Screen::screenWidth / playBackground->getLocalBounds().width, Screen::screenHeight / playBackground->getLocalBounds().height);

	endBackground = std::make_shared<SpriteNode>(Filename::endBackground, Screen::screenWidth, Screen::screenHeight, NULL, NULL);
	endBackground->setScale(Screen::screenWidth / endBackground->getLocalBounds().width, Screen::screenHeight / endBackground->getLocalBounds().height);

	quit = std::make_shared<TextNode>(QUIT_BUTTON, 25u, 2.3f, 1.25f, sf::Color::White, Filename::font);
	play = std::make_shared<TextNode>(PLAY_BUTTON, 35u, 4.3f, 1.15f, sf::Color(128, 128, 255), Filename::font);
	repeat = std::make_shared<TextNode>(REPEAT_BUTTON, 25u, 2.9f, 1.50f, sf::Color::White, Filename::font); 
	title = std::make_shared<TextNode>(TITLE, 23u, 3.6f, 2.8f, sf::Color(230, 230, 230), Filename::font2);

	m_gameDesignButtons.push_back(repeat);
	m_gameDesignButtons.push_back(quit);
}

int GameDesign::getPressedItem()
{
	return m_currentlySelectedItem; 
}

int GameDesign::moveUp()
{ 
	m_currentlySelectedItem = (m_currentlySelectedItem + m_gameDesignButtons.size() - 1) % (m_gameDesignButtons.size());
	return m_currentlySelectedItem;
}

int GameDesign::moveDown()
{ 	
	m_currentlySelectedItem = (m_currentlySelectedItem + 1) % (m_gameDesignButtons.size());
    return m_currentlySelectedItem;
}

void GameDesign::selectMenu()
{
	if (m_currentlySelectedItem == 0)
	{ 
		repeat->setFillColor(sf::Color(51, 173, 255));
		quit->setFillColor(sf::Color::White);
	}
	else
	{
		quit->setFillColor(sf::Color(51, 173, 255));  
		repeat->setFillColor(sf::Color::White);
	} 
}

void GameDesign::drawEnd()
{
	Screen::window.draw(*endBackground);
	Screen::window.draw(*repeat);
	Screen::window.draw(*quit); 
}
 
void GameDesign::drawPlay()
{
	Screen::window.draw(*playBackground); 
}

void GameDesign::draw()
{
	Screen::window.draw(*backgroundSprite);
	Screen::window.draw(*title);
	Screen::window.draw(*play); 
}

void GameDesign::update(sf::Time& elapsedTime)
{
	selectMenu(); 	  
	if (clock.getElapsedTime().asSeconds() >= 0.5f)
	{ 
		play->setFillColor(sf::Color(128, 128, 255));
	}
	if (clock.getElapsedTime().asSeconds() >= 1.f)
	{ 
		play->setFillColor(sf::Color::Transparent);
		clock.restart();
	}
}

GameDesign::~GameDesign()
{
}