#pragma once
#include "Configuration.h"
#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include "SimpleScreen.h"
#include <vector>
class GameObject;

class Playground
{
	friend class GameObject;
private:
	SimpleScreen* sscreen;
	void init();
public:
	//Index represents coordinates within playground
	GameObject* area[(int)CONFIGURATION::PLAYGROUND_XSIZE][(int)CONFIGURATION::PLAYGROUND_YSIZE];

	Playground(SimpleScreen* sscreen);
	SimpleScreen* getSimpleScreen();

	//Fügt den Zeiger in das area - Attribut an Index [x] [y] der Position ein.
	void addGameObject(GameObject* go_ptr);

	//"Nullt" den Zeiger im area - Attribut an Index [x] [y] der Position.
	void removeGameObject(GameObject* go_ptr);

	bool isFree(int x, int y);

	//Optional Aufteilung in Moveable und solid
	void draw();

	Position getLandingPosition(int x);

	/*Position getRandomFreeArea(int distance)
	{
		int x = -1;
		int y = -1;

		//Wird endlos, falls keine entsprechende Area frei ist....
//		neighbourhood(int distance, Position * pos_ptr)
		Position p;
		do
		{
			p.setX(rand() % (CONFIGURATION::PLAYGROUND_XSIZE - 2 * distance) + distance);
			p.setY(rand() % (CONFIGURATION::PLAYGROUND_YSIZE - 2 * distance) + distance);


		} while (!isFree(p.getX(), p.getY()) && neighbourhood(distance, &p).size() < 1);

		return Position(x, y);
	}*/
	bool inbound(int x, int y);
	std::vector <GameObject*> neighbourhood(int distance, GameObject* go_ptr);
	std::vector <Position> neighbourhood(int distance, Position* pos_ptr);

};
