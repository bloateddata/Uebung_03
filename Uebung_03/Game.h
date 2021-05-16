#pragma once
#include "Configuration.h"
#include "SimpleScreen.h"
#include "SimpleInput.h"

#include "Player.h"
#include "Playground.h"
#include "Position.h"
#include "GameObject.h"
#include <sstream>
#include <string>

#include <vector>

class Game
{
private:
	Player* player[4];
	std::vector <GameObject*> border;
	std::vector <GameObject*> ground;
	Playground* pg = NULL;
	SimpleScreen* s = new SimpleScreen();

	//Print Logo - (OPTIONAL)
	void drawLogo();
	void drawLegend();
	void drawPlayerStats(int player_number);
	void drawResult();

	//Create and add players
	void initPlayers();

	//Create and add border to playground
	void initBorder();

	//Create ground objects and add them to the playground
	void initGround();

	//Inits the game by initializing all GameObjects and by drawing all stats
	void init();
	
	//Returns whether all players are alive
	bool allPlayersAlive();

	//Calls all required functions for each turn of a player
	void turn(int player_number);

public:
	Game();
	//loop => Reads input from players, evaluates input and draws results at game end
	void run();

};
