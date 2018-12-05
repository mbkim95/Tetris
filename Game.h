#pragma once
#include <iostream>
#include <fstream>
#include <process.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>
#include "Console.h"
#include "Desk.h"
#include "Block.h"
using namespace std;

class Game : public Console {
private:
	Desk desk;
	Block *block;
	int board[22][12];
	int score = 0;
	bool gameover = false;
	int b = 7;
	int t = 0;
	int speed = 1000;

	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static unsigned int __stdcall run(void *arg) {
		Game *game = (Game *)arg;

		while (1) {
			game->move();
		}
		return 0;
	}

public:
	Game() {
		x = 8;
		y = 0;
		direction = 1;
		setting();
		srand((unsigned int)time(NULL));
		block = new Block(rand() % b);	
	}

	void checkTime() {
		Sleep(speed);
		t++;
		if (t == 60) {
			cout << "TimeUp" << endl;
			b = 13;
			speed = 400;
		}
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
		checkTime();
		if (!gameover) {
			if (direction == 38) {
				if (canRotate())
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
				if (checkLeft())
					x -= 2;
				direction = 1;
			}
			else if (direction == 39) {
				if (checkRight())
					x += 2;
				direction = 1;
			}
			system("cls");
			printBoard();
			block->setXY(x, y);
			checkGameOver();
			block->printBlock();			
			deleteLine();
			srand((unsigned int)time(NULL));
			if (!checkDown()) {
				x = 8;
				y = 0;
				int bomb = rand() % 20;
				if (bomb == 0) {
					block = new Block(777);
				}
				else {
					block = new Block(rand() % b);
					
				}				  
			}			
		}
		else {
			GameOver();			
			return;
		}
	}

	void GameOver() {
		system("cls");
		gotoXY(0, 1);
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩          ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩          ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩          ▩▩▩▩" << endl;
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩    ▩▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩  ▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩    ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩        ▩▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩  ▩▩▩  ▩▩▩▩" << endl;
		cout << "▩▩▩▩        ▩▩▩▩▩" << endl;
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
		cout << "▩▩▩▩▩▩▩▩▩▩▩▩▩" << endl;
	}

	int checkGameOver() {
		int x = block->getX();
		int y = block->getY();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block->isFilled(j, i) && board[y + i][x / 2 + j] != 0) {
					gameover = true;
					return 1;
				}
			}
		}
		return 0;
	}

	int checkDown() {
		int x = block->getX();
		int y = block->getY();
		for (int i = 0; i < 4; i++) {
			int y_max = block->getMaxY(i);
			if (y_max >= 0 && board[y + y_max + 1][x / 2 + i] != 0) {
				fillBlock();
				return 0;
			}
		}
		return 1;
	}

	int checkRight() {
		int x = block->getX();
		int y = block->getY();
		for (int i = 0; i < 4; i++) {
			int x_max = block->getMaxX(i);
			if (x_max >= 0 && board[y + i][x / 2 + x_max + 1] != 0) {				
				return 0;
			}
		}
		return 1;
	}

	int checkLeft() {
		int x = block->getX();
		int y = block->getY();
		for (int i = 0; i < 4; i++) {
			int x_min = block->getMinX(i);
			if (x_min >= 0 && board[y + i][x / 2 + x_min - 1] != 0) {
				return 0;
			}
		}
		return 1;
	}

	void deleteLine(){
		for (int i = 20; i >= 1; i--) {
			if (checkLine(i)) {
				score += 10;
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

	int canRotate() {
		int x = block->getX();
		int y = block->getY();	

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block->isFilled_rotation(j, i))
					if(board[y + i][x / 2 + j] != 0)
						return 0;
			}
		}
		return 1;
	}

	void clearBoard() {
		for(int i=1; i<21; i++)
			for (int j = 1; j < 11; j++) {
				board[i][j] = 0;
			}
	}

	void fillBlock() {
		int x = block->getX();
		int y = block->getY();

		if (block->isBomb()) {
			clearBoard();
			delete block;
			return;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block->isFilled(i, j) == 1) {
					board[y+j][x/2+i] = 1;
				}
			}
		}
		delete block;
	}

	void printBoard() {
		printf("\n");
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 12; j++) {
				if (board[i][j] == 0)
					printf("  ");
				else if (board[i][j] == 1)
					printf("■");
				else if (board[i][j] == 2) {
					printf("□");
				}
			}
			printf("\n");
		}
		printf("\n SCORE : %d\n", score);
	}

	void fileLoad() {
		ifstream ifs;

		ifs.open("score.txt");				// list.txt 파일을 읽어옵니다.

		if (!ifs) {
			cout << "파일을 열 수 없습니다.";
			exit(0);
		}
		int data;

		vector<int> v;

		while (ifs >> data) {
			v.push_back(data);
		}

		cout << endl;
		cout << "My score : " << data << endl;
		cout << endl;
		sort(v.begin(), v.end(),greater<int>());

		for (int i = 0; i < v.size(); i++) {
			cout << i + 1 << " : " << v[i] << endl;
		}

		ifs.close();
	}

	void fileSave(string filename, int score) {
		ofstream ofs;

		ofs.open(filename, ios::app);

		if (!ofs) {
			cout << "파일을 저장할 수 없습니다.";
			exit(0);
		}

		ofs << score << endl;

		ofs.close();
	}

	int getScore() {
		return this->score;
	}

	bool isGameOver() {
		return this->gameover;
	}

	void start() {
		(_beginthreadex(NULL, 0, run, (void*)this, 0, NULL));
	}
};