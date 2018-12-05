#pragma once
#include <iostream>
#include <vector>
#include "Console.h"
using namespace std;

#define BLACK 0
#define D_BLUE 1
#define D_GREEN 2 
#define D_SKYBLUE 3
#define D_RED 4
#define D_VIOLET 5
#define D_YELLOW 6
#define GRAY 7
#define D_GRAY 8
#define BLUE 9
#define GREEN 10
#define SKYBLUE 11
#define RED 12
#define VIOLET 13
#define YELLOW 14
#define WHITE 15

class Block : public Console {
private:
	vector<vector<vector<short>>> block;
	int rotation = 0;
	bool bomb = false;
	char background = BLACK;
	char foreground;																																									

public:
	Block(int i) {
		if (i == 0) {								// ㅗ, ㅏ, ㅜ, ㅓ			
			block = { {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
			{{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
			{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}
			};
		}

		if (i == 1) {									// ㅁ
			block = { {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
			};
		}

		if (i == 2) {									// ㅡ ㅣ
			block = { {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
			{{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
			{{0,1,0,0}, {0,1,0,0},{0,1,0,0},{0,1,0,0}},
			{{0,0,0,0}, {0,0,0,0},{1,1,1,1},{0,0,0,0}} 
			};
		}

		if (i == 3) {									// ㄹ
			block = { { { 0,1,0,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 }},
			{ { 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 }},
			{ { 0,1,0,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 }},
			{ { 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 }}
			};
		}

		if (i == 4) {									// ㄹ 반대
			block = { { { 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 1,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 1,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 5) {									// ㄱ
			block = { { { 0,1,0,0 },{ 0,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,1,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 6) {									// ㄱ 반대
			block = { { { 0,0,0,1 },{ 0,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 } },
			{ { 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,1,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } }
			};
		}
		// 추가 블록
		if (i == 7) {									// ㄱ 
			block = { { { 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,1 },{ 0,0,0,0 } },
			{ { 0,0,0,1 },{ 0,0,0,1 },{ 0,1,1,1 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,1 },{ 0,0,0,0 } },
			{ { 0,1,1,1 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 8) {									// T
			block = { { { 0,1,1,1 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } },
			{ { 0,0,0,1 },{ 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,0 } },
			{ { 0,0,1,0 },{ 0,0,1,0 },{ 0,1,1,1 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 9) {									// +
			block = { { { 0,1,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 10) {									// -ㅁ
			block = { { { 0,0,1,0 },{ 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } },
			{ { 0,1,1,0 },{ 0,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,1,1,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } },
			{ { 1,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 11) {									// -_
			block = { { { 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,1,0 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,1,0 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 12) {									// -_
			block = { { { 1,1,1,0 },{ 1,0,1,0 },{ 1,0,1,0 },{ 0,0,0,0 } },
			{ { 1,1,1,0 },{ 0,0,1,0 },{ 1,1,1,0 },{ 0,0,0,0 } },
			{ { 1,0,1,0 },{ 1,0,1,0 },{ 1,1,1,0 },{ 0,0,0,0 } },
			{ { 1,1,1,0 },{ 1,0,0,0 },{ 1,1,1,0 },{ 0,0,0,0 } }
			};
		}

		if (i == 777) {
			block = { { { 0,0,0,0 },{ 0,0,2,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,0,0 },{ 0,0,2,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,0,0 },{ 0,0,2,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			{ { 0,0,0,0 },{ 0,0,2,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
			};
			bomb = true;
		}

		foreground = i + 1;
	}

	void printBlock() {		
		for (int i = 0; i < block[rotation].size(); i++) {
			setColor(foreground, background);
			gotoXY(x, y + i);
			int tmp_x = x;
			for (int j = 0; j < block[rotation][i].size(); j++) {
				if (block[rotation][i][j] == 1) {
					cout << "■";					
					tmp_x += 2;
				}
				else if (block[rotation][i][j] == 2) {
					cout << "★";
					tmp_x += 2;
				}else {
					tmp_x += 2;
					gotoXY(tmp_x, y+i);
				}
			}
		}
		setColor(WHITE, background);
	}

	bool isBomb() {
		return this->bomb;
	}

	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}

	int getMaxX(int y) {
		for (int i = 3; i >= 0; i--) {
			if (block[rotation][y][i] != 0)
				return i;
		}
		return -999;
	}

	int getMinX(int y) {
		for (int i = 0; i < 4; i++) {
			if (block[rotation][y][i] != 0)
				return i;
		}
		return -999;
	}

	int getMaxY(int x) {
		for (int i = 3; i >= 0; i--) {
			if (block[rotation][i][x] != 0)
				return i;
		}
		return -999;
	}

	int getMaxX_rotation(int y) {
		for (int i = 3; i >= 0; i--) {
			if (isFilled_rotation(i, y))
				return i;
		}
		return -999;
	}

	int getMinX_rotation(int y) {
		for (int i = 0; i < 4; i++) {
			if (isFilled_rotation(i, y))
				return i;
		}
		return -999;
	}

	int getMaxY_rotation(int x) {
		for (int i = 3; i >= 0; i--) {
			if (isFilled_rotation(x, i) == 1)
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

	int isFilled_rotation(int x, int y) {
		int r = getNextRotation();
		if (block[r][y][x] == 1)
			return 1;
		return 0;
	}

	int getNextRotation() {
		int ret = rotation + 1;
		if (ret >= 4) 
			ret = 0;
		return ret;
	}

	void setColor(char color, char backGround) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backGround << 4) + color);
	}
};