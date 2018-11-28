#pragma once
#include <iostream>
#include <process.h>
#include <Windows.h>
#include "Console.h"
#include "Desk.h"
#include "Block.h"
using namespace std;

class Game : public Console {
private:
	Desk desk;
	Block *block;

	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static unsigned int __stdcall run(void *arg) {
		Game *game = (Game *)arg;

		while (1) {
			game->move();
			Sleep(300);
		}
		return 0;
	}
public:
	Game() {
		x = 10;
		y = 2;
		direction = 1;
		block = new Block(1);
	}

	void setDirection(int i) {
		direction = i;
	}

	void move() {
		if (direction == 38) {
			block->rotate();
			direction = 1;
		}
		if (direction == 1) {
			y++;
		}

		if (direction == 40) {
			y++;
			direction = 1;
		}
		else if (direction == 37) {
			x-=2;
			direction = 1;
		}
		else if (direction == 39) {
			x+=2;
			direction = 1;
		}
		system("cls");
		desk.printDesk();
		gotoXY(x, y);
		block->setXY(x, y);
		block->printBlock();
	}

	void start() {
		(_beginthreadex(NULL, 0, run, (void*)this, 0, NULL));
	}
};