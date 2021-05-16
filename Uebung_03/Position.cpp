#pragma once
#include "Position.h"
void Position::setX(int x)
{
	this->x = x;
}
int Position::getX()
{
	return x;
}

void Position::setY(int y)
{
	this->y = y;
}

int Position::getY()
{
	return y;
}

std::string Position::to_string()
{
	return "Position: x= " + std::to_string(x) +" y= "+ std::to_string(y);
}

int Position::distanceManhattan(const Position* pos_ptr)
{
	return abs(this->x - pos_ptr->x) + abs(this->y - pos_ptr->y);
}

Position::Position() { x = 0; y = 0; }

Position::Position(int x, int y) { this->x = x; this->y = y; }
Position::~Position() {}
