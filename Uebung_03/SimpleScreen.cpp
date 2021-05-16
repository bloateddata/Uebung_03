//============================================================================
// Name        : SimpleScreen.cpp
// Author      : Alexander von Bodisco
// Version     : 1.0
// Copyright   : Free for students of HS Augsburg
// Description : Cursor Position Example for Windows
//============================================================================

#pragma once
#include <windows.h>
#include <iostream>
#include "SimpleScreen.h"

SimpleScreen::SimpleScreen()
{
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	setcursor(0, 0);
}


SimpleScreen::~SimpleScreen()
{
	//Aktuell nichts weiter notwendig.
}
void SimpleScreen::setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}
/*
* Funktion setzt den Cursor an Position x,y der Console
*/
void SimpleScreen::gotoxy(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x, y });
	return;
}
/*
* Funktion löscht alle Zeichen auf der Konsole mit OS Boardmitteln
*/
void SimpleScreen::clear()
{
	//Löschen der Console
	system("cls");
	return;
}
/*
* Funktion zeichnet das Zeichen c an die Stelle (x,y)
*/
void SimpleScreen::setChar(short x, short y, char c)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x, y });
	std::cout << c;
	return;
}

