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
	int board[22][12];

	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static unsigned int __stdcall run(void *arg) {
		Game *game = (Game *)arg;

		while (1) {
			game->move();
			Sleep(150);
		}
		return 0;
	}

public:
	Game() {
		x = 10;
		y = 2;
		direction = 1;
		setting();
		block = new Block(2);
	}

	void setting() {
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 12; j++) {
				board[i][j] = 0;
			}
		}

		for (int i = 0; i < 12; i++) {
			board[0][i] = 2;
			board[21][i] = 2;
		}

		for (int i = 0; i < 22; i++) {
			board[i][0] = 2;
			board[i][11] = 2;
		}
	}

	void setDirection(int i) {
		direction = i;
	}

	void move() {
		if (direction == 38) {
			block->rotate();
			direction = 2;
		}
		if (direction == 1) {
			y++;
		}

		if (direction == 40) {
			y++;
			direction = 1;
		}
		else if (direction == 37) {
			x -= 2;
			direction = 1;
		}
		else if (direction == 39) {
			x += 2;
			direction = 1;
		}
		system("cls");
		printBlock();
		gotoXY(x, y);
		block->setXY(x, y);
		deleteLine();
		block->printBlock();
		int chk = checkMove();

		if (chk == 1) {
			x = 8;
			y = 2;
			block = new Block(2);
		}
	}

	int checkMove() {
		int x = block->getX();
		int y = block->getY();
		for (int i = 0; i < 4; i++) {
			int y_max = block->getMaxY(i);
			if (y_max >= 0 && board[y + y_max + 1][x / 2 + i] != 0) {
				fillBlock();
				return 1;
			}
		}
		return 0;
	}

	void deleteLine(){
		for (int i = 20; i >= 1; i--) {
			if (checkLine(i)) {
				for (int j = 1; j < 11; j++) {
					board[i][j] = 0;
				}
				pullLine(i);
			}
		}
	}

	void pullLine(int y) {
		for (int i = y; i > 1; i--) {
			for (int j = 1; j < 11; j++) {
				if (board[i - 1][j] == 1) {
					board[i][j] = board[i - 1][j];
					board[i - 1][j] = 0;
				}
			}
		}
	}

	int checkLine(int y) {
		for (int i = 1; i < 11; i++) {
			if (board[y][i] == 0)
				return 0;
		}
		return 1;
	}

	void fillBlock() {
		int x = block->getX();
		int y = block->getY();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block->isFilled(i, j) == 1) {
					board[y+j][x/2+i] = 1;
				}
			}
		}
		y = 2;
		block = new Block(1);
	}

	void printBlock() {
		printf("\n");
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 12; j++) {
				if (board[i][j] == 0)
					printf("  ");
				else if (board[i][j] == 1)
					printf("бс");
				else if (board[i][j] == 2) {
					printf("бр");
				}
			}
			printf("\n");
		}
	}

	void start() {
		(_beginthreadex(NULL, 0, run, (void*)this, 0, NULL));
	}
};