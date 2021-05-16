#pragma once
#include "GameObject.h"
#include "Position.h"
#include "Playground.h"
#include <vector>

class Rock : public GameObject
{
private:
	double xspeed;
	double yspeed;
	GameObject* owner_ptr;

	//Bewegt den Felsen in die aktuelle Richtung
	void move();
public:
	//Erzeugt eine Rock-Instanz mit Geschwindigkeit 0 an der Position des owners
	Rock(GameObject* owner_ptr);

	void setXSpeed(double xspeed);

	void setYSpeed(double yspeed);

	//Verändert die Geschwindigkeit falls der Felsen "unterwegs" ist.
	void proceed();
	
	

	//Ausgabe der Animation mit angegebenen Radius auf der Konsole
	void explosionAnimation(int radius);

};