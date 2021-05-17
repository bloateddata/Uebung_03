#pragma once
#include "Playground.h"
#include "Position.h"
#include "Rock.h"
#include "Player.h"

//Anmerkung: Threads werden in einem späteren Kapitel behandelt.
#include<thread>
//Enthält Zeiten (Sekunden, Millisekunden, Mikrosekunden,...)
#include <chrono>   

Rock::Rock(GameObject* owner_ptr)
{
	xspeed = 0;
	yspeed = 0;
	this->owner_ptr = owner_ptr; 
	position = Position(owner_ptr->getPosition().getX(), owner_ptr->getPosition().getY()-1);
	symbol = CONFIGURATION::GAMEOBJECT_ROCK;
	playground = owner_ptr->getPlayground();
}

void Rock::setXSpeed(double xspeed)
{
	this->xspeed = xspeed;
}

void Rock::setYSpeed(double yspeed)
{
	this->yspeed = yspeed;
}

void Rock::proceed()
{
	xspeed += (CONFIGURATION::WIND * 0.05);
	yspeed += (CONFIGURATION::GRAVITY * 0.05);
	move();
}

void Rock::move()
{
	Position new_p = getPosition();
	new_p.setX(new_p.getX() + 0.1 * xspeed);                
	new_p.setY(new_p.getY() + 0.1 * yspeed);                  

	getPlayground()->getSimpleScreen()->gotoxy(0, 41);
	std::cout << "Rock - " << getPosition().to_string() << std::endl;

	getPlayground()->getSimpleScreen()->gotoxy(0, 42);
	std::cout << "Next - " << new_p.to_string() << std::endl;


	if (position.getX() == new_p.getX() || position.getY() == new_p.getY())
		return;

	if (!playground->inbound(new_p.getX(), new_p.getY()))
	{
			while (new_p.getX() > CONFIGURATION::PLAYGROUND_XSIZE-1)
			{
				new_p.setX(new_p.getX() - 1);
			}

			while (new_p.getY() > CONFIGURATION::PLAYGROUND_YSIZE)
			{
				new_p.setY(new_p.getY() - 1);
			}
	}

	if (playground->isFree(new_p.getX(), new_p.getY()))
	{
		playground->removeGameObject(this);
		this->setPosition(new_p);
		playground->addGameObject(this);
	}
	else
	{
		explosionAnimation(CONFIGURATION::BOMB_RADIUS);
	}
}

void Rock::explosionAnimation(int radius)
{
	std::vector<GameObject*> object = playground->neighbourhood(radius, this);
	std::vector<Position> pos = playground->neighbourhood(radius, new Position(this->getPosition()));

	for (int i = 0; i < (int)object.size(); i++)
	{
		if (object.at(i)->getType() == CONFIGURATION::GAMEOBJECT_GROUND)
		{
			playground->removeGameObject(object.at(i));
			//playground->addGameObject(new GameObject(object.at(i)->getPosition(), 'D', object.at(i)->getPlayground()));
		}
		else if (object.at(i)->getType() == CONFIGURATION::GAMEOBJECT_PLAYER_1 || object.at(i)->getType() == CONFIGURATION::GAMEOBJECT_PLAYER_2)
		{
			((Player*)object.at(i))->decreaseLives();
		}
	}
	
	for (int i = 0; i < (int)pos.size(); i++)
	{
		playground->getSimpleScreen()->setChar(pos.at(i).getX() + 5,
		pos.at(i).getY() + 1, CONFIGURATION::PLAYGROUND_BACKGROUND);
	}
	((Player*)this->owner_ptr)->setAway(false);

	this->position.setX(owner_ptr->getPosition().getX());
	this->position.setY(owner_ptr->getPosition().getY() - 1);
	
}	
