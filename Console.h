#pragma once
#include <iostream>
#include <process.h>
#include <Windows.h>

class Console {
protected:
	int x, y, direction;

public:
	Console() {
		CONSOLE_CURSOR_INFO cursorinfo = { 0, };
		cursorinfo.dwSize = 1;
		cursorinfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
	}

	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void setColor(int i) {

	}
};