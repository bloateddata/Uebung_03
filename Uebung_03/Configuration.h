#pragma once
class CONFIGURATION
{
public:
	//PLAYGROUND - DIMENSION
	static const int PLAYGROUND_XSIZE = 150;
	static const int PLAYGROUND_YSIZE = 25;
	static const int PLAYGROUND_OFFSETX = 5;
	static const int PLAYGROUND_OFFSETY = 1;
	static const int PLAYGROUND_BORDERWIDTH = 1;

	static const char PLAYGROUND_BACKGROUND = ' ';
	static const char PLAYGROUND_EXPLOSION = '§';

	//GAMEOBJECT - INPUT
	static const int POWER_UP = 0;
	static const int POWER_DOWN = 1;
	static const int ANGLE_UP = 2;
	static const int ANGLE_DOWN = 3;
	static const int LAUNCH_ACTION = 4;
	static const int INPUT_INVALID = 5;

	//GAMEOBJECT - PLAYER
	static const char GAMEOBJECT_PLAYER_1 = 'X';
	static const char GAMEOBJECT_PLAYER_2 = 'O';
	
	//GAMEOBJECT - OBSTACLES NON-MOVEABLE / SOLID
	static const char GAMEOBJECT_ROCK = '*';
	static const char GAMEOBJECT_GROUND = '#';
	static const char GAMEOBJECT_BORDER = '@';

	//GAMEPLAY
	static const int NUMBER_OF_PLAYERS = 2;
	static const int GAMESPEED = 30;
	static const int BOMB_RADIUS = 4;
	
	static const int GRAVITY = 100;//DEFAULT 100
	static const int WIND = 30; //DEFAULT 30

	//GAME - PLAYER VALUES
	static const int PLAYER_INIT_LIVES = 2;
	static const int PLAYER_INIT_ANGLE = 40;
	static const int PLAYER_INIT_POWER = 400;

};
