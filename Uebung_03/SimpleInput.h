#pragma once
class SimpleInput
{

public:
	SimpleInput();
	~SimpleInput();
	static char getWASD(long interval);
	static char getArrow(long interval);
	static char getSteuerung(long interval);

};

