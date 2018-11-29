#pragma once
#include <iostream>
#include <vector>
#include "Console.h"
#include "Game.h"
using namespace std;

class Block : public Console {
private:
	vector<vector<vector<short>>> block;
	int rotation = 0;

public:
	Block(int i) {
		if (i == 1) {									// で, た, ぬ, っ
			block = { {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
			{{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
			{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}
			};
		}

		if (i == 2) {									// け
			block = { {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			};
		}

		if (i == 3) {									// ぱ び
			block = { {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
			{{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
			{{0,1,0,0}, {0,1,0,0},{0,1,0,0},{0,1,0,0}},
			{{0,0,0,0}, {0,0,0,0},{1,1,1,1},{0,0,0,0}} 
			};
		}
	}

	void printBlock() {		
		for (int i = 0; i < block[rotation].size(); i++) {
			gotoXY(x, y + i);
			int tmp_x = x;
			for (int j = 0; j < block[rotation][i].size(); j++) {
				if (block[rotation][i][j] == 1) {
					cout << "＝";					
					tmp_x += 2;
				}
				else {
					tmp_x += 2;
					gotoXY(tmp_x, y+i);
				}
			}
		}
		//cout << endl << this->x << ' ' << this->y;
	}

	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}

	int getMaxY(int x) {
		for (int i = 3; i >= 0; i--) {
			if (block[rotation][i][x] == 1)
				return i;
		}
		return -999;
	}

	int isFilled(int x, int y) {
		if (block[rotation][y][x] == 1)
			return 1;
		return 0;
	}

	void rotate() {
		rotation++;
		if (rotation >= 4)
			rotation = 0;
	}
};