#pragma once
#include <iostream>
#include <vector>
#include "Console.h"
using namespace std;

class Block : public Console {
private:
	vector<vector<vector<short>>> block;
	int rotation = 0;

public:
	Block(int i) {
		if (i == 1) {									// で, た, ぬ, っ
			block = { {{0,1,0},{1,1,1},{0,0,0}},
			{{0,1,0},{0,1,1},{0,1,0}},
			{{0,0,0},{1,1,1},{0,1,0}},
			{{0,1,0},{1,1,0},{0,1,0}}
			};
		}

		if (i == 2) {									// け
			block = { {{1,1},{1,1}},
			{{1,1},{1,1}},
			{{1,1},{1,1}},
			{{1,1},{1,1}} 
			};
		}

		if (i == 3) {									// ぱ び
			block = { {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
			{{0, 0, 0, 0}, {0, 0, 0, 0},{ 1, 1, 1, 1 } ,{0, 0, 0, 0}},
			{{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
			{{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1,}, {0, 0, 0, 0}} 
			};
		}
	}

	void printBlock() {
		for (int i = 0; i < block[rotation].size(); i++) {
			gotoXY(x, y + i);
			for (int j = 0; j < block[rotation][i].size(); j++) {
				if (block[rotation][i][j] == 0)
					cout << "  ";
				else
					cout << "＝";
			}
		}
	}

	void rotate() {
		rotation++;
		if (rotation >= 4)
			rotation = 0;
	}
};