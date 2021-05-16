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
	
	//Routine zur Ausführung der Spieleraktion
	bool action(int input);

	//Dekrementiert die Anzahl der Leben
	void decreaseLives();

	//Verändert den Spieler in Abhängigkeit des Zustands, z.B. timer-Dekrement
	void proceed();

	//Gibt die String repräsentation des Spieler zurück.
	std::string to_string();

	//Gibt die Spielernummer zurück
	int getPlayerNumber();

	//Gibt das Attribut lives zurück
	int getLives();

	bool isAway();

	void setAway(bool);

};
