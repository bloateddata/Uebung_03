#pragma once
#include "Configuration.h"
#include <cstdlib>
#include <ctime>
#include "SimpleScreen.h"
#include <vector>
#include "Playground.h"

SimpleScreen* Playground::getSimpleScreen()
{
	return nullptr;
}
Playground::Playground(SimpleScreen* sscreen) : sscreen(sscreen)
{
	srand((unsigned int) time(NULL));
	init();
};
void Playground::init()
{
	for (int i = 0; i < CONFIGURATION::PLAYGROUND_XSIZE; i++)
	{
		for (int j = 0; j < CONFIGURATION::PLAYGROUND_YSIZE; j++)
		{
			area[i][j] = NULL;
		}
	}
}
void Playground::addGameObject(GameObject* go_ptr)
{
	if (inbound(go_ptr->getPosition().getX(), go_ptr->getPosition().getY()))
	{
		area[go_ptr->getPosition().getX()][go_ptr->getPosition().getY()] = go_ptr;
	}
	go_ptr->draw(true); 
};

void Playground::removeGameObject(GameObject* go_ptr)
{
	if (inbound(go_ptr->getPosition().getX(), go_ptr->getPosition().getY()))
	{
		area[go_ptr->getPosition().getX()][go_ptr->getPosition().getY()] = NULL;
		sscreen->setChar(go_ptr->getPosition().getX(),go_ptr->getPosition().getY(), CONFIGURATION::PLAYGROUND_BACKGROUND);
	}

};

bool Playground::isFree(int x, int y)
{
	if (inbound(x,y))
	{
		return area[x][y] == NULL;
	}
	return NULL;
}

void Playground::draw()
{
	for (int i = 0; i < CONFIGURATION::PLAYGROUND_XSIZE; i++)
	{
		for (int j = 0; j < CONFIGURATION::PLAYGROUND_YSIZE; j++)
		{
			if (area[i][j] != NULL)
			{
				area[i][j]->draw(true);
			}
		}
	}
}


Position Playground::getLandingPosition(int x)
{
	if (inbound(x, 0))
	{
		for (int i = 1; i < CONFIGURATION::PLAYGROUND_YSIZE-1; i++)
		{
			if (!isFree(x,i+1))
			{
				return Position(x, i);
			}
		}
	}
	return Position(0, 0);
}

bool Playground::inbound(int x, int y)
{
	if (x < 0 || x >= CONFIGURATION::PLAYGROUND_XSIZE || y < 0 || y >= CONFIGURATION::PLAYGROUND_YSIZE)
	{
		return false;
	}
	return true;

}
std::vector <GameObject*> Playground::neighbourhood(int distance, GameObject* go_ptr)
{
	std::vector <GameObject*> temp;
	for (int i = 0; i < CONFIGURATION::PLAYGROUND_XSIZE-1; i++)
	{
		for (int j = 0; j < CONFIGURATION::PLAYGROUND_YSIZE-1; j++)
		{
			if (!isFree(i,j))
			{
				if (area[i][j]->getPosition().distanceManhattan(new Position(go_ptr->getPosition()))<= distance)
				{
					temp.push_back(area[i][j]);
				}
			}
		}
	}
	return temp;
}
std::vector <Position> Playground::neighbourhood(int distance, Position* pos_ptr)
{
	std::vector <Position> temp;
	for (int i = 0; i < CONFIGURATION::PLAYGROUND_XSIZE - 1; i++)
	{
		for (int j = 0; j < CONFIGURATION::PLAYGROUND_YSIZE - 1; j++)
		{
			if (!isFree(i, j))
			{
				if (Position(i, j).distanceManhattan(pos_ptr) <= distance)
				{
					temp.push_back(Position(i,j));
				}
			}
		}
	}
	return temp;
}


