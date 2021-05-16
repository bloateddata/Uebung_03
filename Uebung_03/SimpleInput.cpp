#include "SimpleInput.h"
#include "Configuration.h"
#include <windows.h>
#include <iostream>
//Microsoft Codetabelle
//https://msdn.microsoft.com/de-de/library/windows/desktop/dd375731(v=vs.85).aspx

SimpleInput::SimpleInput()
{
}

SimpleInput::~SimpleInput()
{
}

char SimpleInput::getSteuerung(long interval)
{
	Sleep(interval);
	const int KEY_UP = 0x1;
	if ((GetAsyncKeyState(0x57) & KEY_UP) == KEY_UP)
		return 'w';
	else if ((GetAsyncKeyState(0x41) & KEY_UP) == KEY_UP)
		return 'a';
	else if ((GetAsyncKeyState(0x53) & KEY_UP) == KEY_UP)
		return 's';
	else if ((GetAsyncKeyState(0x44) & KEY_UP) == KEY_UP)
		return 'd';
	else if ((GetAsyncKeyState(0x45) & KEY_UP) == KEY_UP)
		return 'e';
	else
		return 'x';
}

char SimpleInput::getWASD(long interval)
{
	Sleep(interval);
	const int KEY_UP = 0x1;
	if ((GetAsyncKeyState(0x57) & KEY_UP) == KEY_UP) // 'w';
		return CONFIGURATION::POWER_UP;
	else if ((GetAsyncKeyState(0x41) & KEY_UP) == KEY_UP) // 'a';
		return CONFIGURATION::ANGLE_UP;
	else if ((GetAsyncKeyState(0x53) & KEY_UP) == KEY_UP) // 's';
		return CONFIGURATION::POWER_DOWN;
	else if ((GetAsyncKeyState(0x44) & KEY_UP) == KEY_UP) // 'd';
		return CONFIGURATION::ANGLE_DOWN;
	else if ((GetAsyncKeyState(0x45) & KEY_UP) == KEY_UP) // 'e';
		return CONFIGURATION::LAUNCH_ACTION;
	else
		return CONFIGURATION::INPUT_INVALID;
}

char SimpleInput::getArrow(long interval)
{
	Sleep(interval);
	const int KEY_UP = 0x1;
	//VK UP
	if ((GetAsyncKeyState(0x26) & KEY_UP) == KEY_UP) // '8';
		return CONFIGURATION::POWER_UP;
	//VK LEFT
	else if ((GetAsyncKeyState(0x25) & KEY_UP) == KEY_UP) // '4';
		return CONFIGURATION::ANGLE_DOWN;
	//VK DOWN
	else if ((GetAsyncKeyState(0x28) & KEY_UP) == KEY_UP) // '5';
		return CONFIGURATION::POWER_DOWN;
	//VK RIGHT
	else if ((GetAsyncKeyState(0x27) & KEY_UP) == KEY_UP) // '6';
		return CONFIGURATION::ANGLE_UP;
	//Enter
	else if ((GetAsyncKeyState(0x0D) & KEY_UP) == KEY_UP) // 'e';
		return CONFIGURATION::LAUNCH_ACTION;
	else
		return CONFIGURATION::INPUT_INVALID;
}
