#pragma once
#include "Position.h"
#include "Configuration.h"

class Playground;

class GameObject
{
protected:
	//Position innerhalb des Spielfeldes
	Position position;
	//Zeichen repräsentiert das Symbol
	char symbol;
	//Zeiger auf das Spielfeld 
	Playground* playground = NULL;

public:
	//Leerer Konstruktor (setzt nur das symbol auf ' ')
	GameObject();
	//3-Param Konstruktor setzt die Attribute auf die übergebenen Parameter
	GameObject(Position p, char symbol, Playground* playground = NULL);
	//Funktion zeichnet das Symbol an der entsprechenden Stelle (mit oder ohne offset)
	virtual void draw(bool offset);
	//Gibt die Position zurück
	Position getPosition();
	//Setzt die Position auf die übergebene Stelle
	void setPosition(Position p);
	//Übernimmt den übergebenen Zeiger 
	void setPlayground(Playground* pg);
	//Gibt das Playground Attribut zurück 
	Playground* getPlayground();
	
	//Gibt das Zeichen des GameObjektes zurück
	char getType();

};
