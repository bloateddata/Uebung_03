#pragma once
#include "Playground.h"
#include "Position.h"
#include "Player.h"

//Anmerkung: Threads werden in einem späteren Kapitel behandelt.
#include<thread>
//Enthält Zeiten (Sekunden, Millisekunden, Mikrosekunden,...)
#include <chrono>   

Player::Player(int player_number = 1)
{
	this->player_number = player_number;
	lives = CONFIGURATION::PLAYER_INIT_LIVES;
	angle = CONFIGURATION::PLAYER_INIT_ANGLE;
	power = CONFIGURATION::PLAYER_INIT_POWER;
	if (player_number == 1)
	{
		symbol = CONFIGURATION::GAMEOBJECT_PLAYER_1;
	}
	else
	{
		symbol = CONFIGURATION::GAMEOBJECT_PLAYER_2;
	}

	rock_away = false;
	rock_ptr = NULL;
}

bool Player::action(int input)
{
	switch (input)
	{
	case CONFIGURATION::POWER_UP:
	{
		power += 5;
		break;
	}
	case CONFIGURATION::POWER_DOWN:
	{
		power -= 5;
		break;
	}
	case CONFIGURATION::ANGLE_UP:
	{
		angle++;
		break;
	}
	case CONFIGURATION::ANGLE_DOWN:
	{
		angle--;
		break;
	}
	case CONFIGURATION::LAUNCH_ACTION:
	{
		if (!rock_away)
		{
			((Rock*)rock_ptr)->setYSpeed(-0.1 * (double)power * sin((double)angle * 3.14159 / 180.0));
			((Rock*)rock_ptr)->setXSpeed(0.1 * (double)power * cos((double)angle * 3.14159 / 180.0) * (player_number == 1 ? 1.0 : -1.0));
			rock_away = true;
			playground->addGameObject(rock_ptr);
		}
		break;
	}
	default:
		return false;
	}
	return true;
}

void Player::proceed()
{
	if (rock_away)
	{
		((Rock*)rock_ptr)->proceed();
	}
}

void Player::decreaseLives()
{
	lives--;
	!lives ? symbol =  ' ' : symbol = symbol;
}

std::string Player::to_string()
{
	std::string temp = "***********************\n* Troll\t";
	temp += std::to_string(getPlayerNumber()) + "\t-\t" + (player_number == 1 ? "X" : "O") + "\t\t\t\t\t\t\t\t\t*\n";
	temp += "***********************\n";
	temp += rock_away ? "* Status : ROCK NOT READY *\n" : "* Status : ROCK READY *\n";
	temp += "*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
	temp += "* Angle: " + std::to_string(angle) + "\t\t\t\t\t\t\t\t\t\t\t*\n";
	temp += "* Power: " + std::to_string(power) + "\t\t\t\t\t\t\t\t\t\t*\n";
	temp += "*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n";
	temp += "* Lives: " + std::to_string(getLives()) + "\t\t\t\t\t\t\t\t\t\t\t\t*\n";
	temp += "***********************\n";
	return temp;
};



int Player::getPlayerNumber()
{
	return player_number;
}

int Player::getLives()
{
	return lives;
}

bool Player::isAway()
{
	return rock_away;
}

void Player::setAway(bool)
{
	rock_away = !rock_away;
}
