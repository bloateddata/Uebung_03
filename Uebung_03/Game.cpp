#pragma once
#include "Configuration.h"
#include "SimpleScreen.h"
#include "SimpleInput.h"
#include "help.h"
#include "Player.h"
#include "Playground.h"
#include "Position.h"
#include "GameObject.h"
#include <sstream>
#include <string>
#include <vector>
#include "Game.h"

void Game::drawLogo()	//150x25
{
	
	std::vector<std::string> str;
	str.push_back( "  *   )              (    (       (  (                          \n");
	str.push_back("` )  /    (          )\\    \\      )\\))(   '    )                \n");
	str.push_back(" ( ) _))  )(     (  ( _) ( _)    ( _)()\\ )  ( /    )(    (      \n");
	str.push_back(" _(_())  (  )\\   )\\   _    _     _( ))\\_ () )(_)) ( )\\    \\     \n");
	str.push_back("|_   _|  (_(_)  ((_) | |  | |    \\ \\( _)/ /((_ _   ( _) ((_)   \n");
	str.push_back("  | |    | '_| / _ \\ | |  | |     \\ \\/\\/ / / _` | | '_| (_-<    \n");
	str.push_back("  |_|    |_|   \\___/ |_|  |_|      \\_/\\_/  \\__,_| |_|   /__/    \n");
	
	int y = CONFIGURATION::PLAYGROUND_YSIZE + CONFIGURATION::PLAYGROUND_BORDERWIDTH + CONFIGURATION::PLAYGROUND_OFFSETY + 1;

	for (size_t i = 0; i < str.size(); i++)
	{
		s->gotoxy(50, y++);
		std::cout << str[i];
	}

}

void Game::drawLegend()
{
	std::vector<std::string> temp = { "X - Troll 1", "O - Troll 2", "* - Rock", "# - Ground" , "\n", "------------------", "\n", "Gravity: 250 m/s", "Wind: 30 m/s", "Wind-Dir.: ----->" };

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].length(); j++)
		{
			s->setChar((CONFIGURATION::PLAYGROUND_XSIZE + CONFIGURATION::PLAYGROUND_BORDERWIDTH) + j + 6, i + 6, temp[i][j]);
		}
	}
}



void Game::drawPlayerStats(int player_number)
{
	std::vector<std::string> player0 = Split_String(player[0]->to_string());
	std::vector<std::string> player1 = Split_String(player[1]->to_string());

	int y = CONFIGURATION::PLAYGROUND_BORDERWIDTH + CONFIGURATION::PLAYGROUND_OFFSETY + 1;
	//Player 0
	for (int i = 0; i < player0.size(); i++)
	{
		for (int j = 0; j < player0[i].length(); j++)
		{
			s->setChar(j + 6, (CONFIGURATION::PLAYGROUND_YSIZE + CONFIGURATION::PLAYGROUND_BORDERWIDTH + i + 2), player0[i][j]);
		}
	}

	//Player 1
	for (int i = 0; i < player1.size(); i++)
	{
		for (int j = 0; j < player1[i].length() + 1; j++)
		{
			s->setChar((CONFIGURATION::PLAYGROUND_XSIZE + CONFIGURATION::PLAYGROUND_BORDERWIDTH) - j + 5, (CONFIGURATION::PLAYGROUND_YSIZE + CONFIGURATION::PLAYGROUND_BORDERWIDTH + i + 2), player1[i][player1[i].length() - j]);
		}
	}
}

void Game::drawResult()
{
	Game::s->clear();
	std::vector<std::string> str;
	
	if (player[0]->getLives()>player[1]->getLives())
	{
		str.push_back("Player " + std::to_string(player[0]->getPlayerNumber()) + " has won the game\n");
		str.push_back("Lives left: " + std::to_string(player[0]->getLives())+"\n");
	}
	else
	{
		str.push_back("Player " + std::to_string(player[1]->getPlayerNumber()) + " has won the game\n");
		str.push_back("Lives left: " + std::to_string(player[1]->getLives())+"\n");
	}
	
	int y = 10;

	for (size_t i = 0; i < str.size(); i++)
	{
		s->gotoxy(CONFIGURATION::PLAYGROUND_XSIZE/2, y++);
		std::cout << str[i];
	}

}

Game::Game()
{
	init();
}

//Create and add players
void Game::initPlayers()
{
	player[0] = new Player(0);
	player[1] = new Player(1);
	player[0]->setPlayground(pg);
	player[1]->setPlayground(pg);
	srand(time(0));
	player[0]->setPosition(pg->getLandingPosition((rand() % 4 + CONFIGURATION::PLAYGROUND_XSIZE / 4)));
	player[1]->setPosition(pg->getLandingPosition((rand() % 4 + (CONFIGURATION::PLAYGROUND_XSIZE - (CONFIGURATION::PLAYGROUND_XSIZE / 4)))));
	s->gotoxy(0, 50); std::cout << player[0]->getPosition().to_string();
	s->gotoxy(0, 51); std::cout << player[1]->getPosition().to_string();
	pg->addGameObject(player[0]);
	pg->addGameObject(player[1]);

	player[0]->setRock(new Rock(player[0]));
	player[1]->setRock(new Rock(player[1]));

}

void Game::initBorder()
{
	for (int i = 0; i < CONFIGURATION::PLAYGROUND_YSIZE; i++)
	{
		pg->addGameObject(new GameObject(Position(0, i), CONFIGURATION::GAMEOBJECT_BORDER, pg));
		pg->addGameObject(new GameObject(Position(CONFIGURATION::PLAYGROUND_XSIZE - 1, i), CONFIGURATION::GAMEOBJECT_BORDER, pg));
	}

	for (int i = 0; i < CONFIGURATION::PLAYGROUND_XSIZE; i++)
	{
		pg->addGameObject(new GameObject(Position(i, 0), CONFIGURATION::GAMEOBJECT_BORDER, pg));
		pg->addGameObject(new GameObject(Position(i, CONFIGURATION::PLAYGROUND_YSIZE - 1), CONFIGURATION::GAMEOBJECT_BORDER, pg));
	}
}

void Game::initGround()
{
	for (int i = 1; i < CONFIGURATION::PLAYGROUND_XSIZE; i++)
	{
		for (int j = 0; j < CONFIGURATION::PLAYGROUND_YSIZE * 0.3; j++)
		{
			pg->addGameObject(new GameObject(pg->getLandingPosition(i), CONFIGURATION::GAMEOBJECT_GROUND, pg)); 
		}
	}
}

void Game::init()
{
	pg = new Playground(s);

	initBorder();
	initGround();
	initPlayers();
	drawLegend();
	drawLogo();
	drawPlayerStats(0);
	drawPlayerStats(1);
	pg->draw();
}

void Game::run()
{
	while (allPlayersAlive())
	{
		turn(0);
		turn(1);
		drawLogo();
		drawPlayerStats(0);
		drawPlayerStats(1);
		drawLegend();
		pg->draw();
	}
	drawResult();
}

bool Game::allPlayersAlive()
{
	return player[0]->getLives() && player[1]->getLives(); 
}


void Game::turn(int player_number)
{
	//IHR CODE
	SimpleInput si;
	int in = CONFIGURATION::INPUT_INVALID;
	if (player_number == 0)
	{
		in = si.getWASD(CONFIGURATION::GAMESPEED);
	}
	else
	{
		in = si.getArrow(CONFIGURATION::GAMESPEED);
	}
	player[player_number]->action(in);
	player[player_number]->proceed();
}

