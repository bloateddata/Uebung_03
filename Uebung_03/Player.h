#pragma once
#include "GameObject.h"
#include "Position.h"
#include "Rock.h"

class Player : public GameObject
{
protected:
	
	bool rock_away;
	int player_number;
	int lives;
	int angle;
	int power;

	GameObject* rock_ptr;

public:
	//Initialisiert alle Attribute
	Player(int player_number);

	void setRock(GameObject* rock_ptr)
	{
		this->rock_ptr = rock_ptr;
	}
	
	//Routine zur Ausf�hrung der Spieleraktion
	bool action(int input);

	//Dekrementiert die Anzahl der Leben
	void decreaseLives();

	//Ver�ndert den Spieler in Abh�ngigkeit des Zustands, z.B. timer-Dekrement
	void proceed();

	//Gibt die String repr�sentation des Spieler zur�ck.
	std::string to_string();

	//Gibt die Spielernummer zur�ck
	int getPlayerNumber();

	//Gibt das Attribut lives zur�ck
	int getLives();

	bool isAway();

	void setAway(bool);

};
