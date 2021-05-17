#pragma once
#include "SimpleScreen.h"
#include "Game.h"
#include <iostream>

int main()
{
	Game* game = new Game();
	game->run(); 
	return 0;
}