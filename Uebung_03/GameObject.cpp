#pragma once
#include "Position.h"
#include "Configuration.h"
#include "Playground.h"
#include "GameObject.h"

GameObject::GameObject() 
{  
	symbol = CONFIGURATION::PLAYGROUND_BACKGROUND;
}

GameObject::GameObject(Position position, char symbol, Playground* playground) 
{
	this->position = position;
	this->symbol = symbol;
	this->playground = playground;
}

void GameObject::setPosition(Position position) 
{
	this->position = position;
}

void GameObject::setPlayground(Playground* pg)
{
	playground = pg;
}

Playground* GameObject::getPlayground()
{
	return playground;
}

Position GameObject::getPosition()
{
	return position;
}
char GameObject::getType()
{
	return symbol;
}

void GameObject::draw(bool offset)
{
	if (offset)
	{
		playground->getSimpleScreen()->setChar(this->position.getX() + CONFIGURATION::PLAYGROUND_OFFSETX + CONFIGURATION::PLAYGROUND_BORDERWIDTH, this->position.getY() + CONFIGURATION::PLAYGROUND_OFFSETY + CONFIGURATION::PLAYGROUND_BORDERWIDTH, symbol); //gotoxy(this->position.getX() + CONFIGURATION::PLAYGROUND_OFFSETX + CONFIGURATION::PLAYGROUND_BORDERWIDTH, this->position.getY() + CONFIGURATION::PLAYGROUND_OFFSETY + CONFIGURATION::PLAYGROUND_BORDERWIDTH);
	}
	else
	{
		playground->getSimpleScreen()->setChar(this->position.getX(), this->position.getY(),symbol);
	}
}