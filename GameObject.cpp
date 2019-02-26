#include "stdafx.h"
#include "GameObject.h"



GameObject::GameObject()
{
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();
	drawCurrent(target, states);
}

void GameObject::drawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	// Do nothing by default
}

GameObject::~GameObject()
{
}