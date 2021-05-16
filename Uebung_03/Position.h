#pragma once
#include <iostream>
#include <string>

class Position
{
protected:
	int x;
	int y;
public:
	void setX(int x);

	int getX();

	void setY(int y);

	int getY();

	std::string to_string();

	int distanceManhattan(const Position* p);

	Position();

	Position(int x, int y);

	~Position();

};
