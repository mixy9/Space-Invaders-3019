#pragma once

#include "GameObject.h"
#include "TextNode.h"
#include "SpriteNode.h"
#include "SoundManager.h"



class GameDesign : public GameObject
{
private:
	unsigned int m_currentlySelectedItem;

	sPtr<TextNode> quit, play, title, repeat, end;
	std::vector<sPtr<TextNode>> m_gameDesignButtons;
	sPtr<SpriteNode> interfaceHud, backgroundSprite, playBackground, endBackground;
	sf::Clock clock;

public:
	GameDesign();

	int moveUp();
	int moveDown();
	int getPressedItem();

	void drawEnd();
	void drawPlay();
	void selectMenu();

	virtual void draw();
	virtual void initialize();
	virtual void update(sf::Time& elapsedTime);

	~GameDesign();
};

