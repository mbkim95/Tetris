#pragma once
#include <iostream>
#include <Windows.h>
#include "Game.h"
using namespace std;

class KeyEvent {
private:
	HANDLE hIn;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;
	Game* game;

	static unsigned int __stdcall run(void *arg) {
		KeyEvent *key = (KeyEvent *)arg;
		while (1) {
			int temp = key->getKey();
			if (temp > 36 && temp < 41)
				key->game->setDirection(temp);
		}
		return 0;
	}
public:
	KeyEvent() {
		hIn = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}

	int getKey() {
		ReadConsoleInput(hIn, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) {
			if (InRec.Event.KeyEvent.bKeyDown) {
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else {
				return -1;
			}
		}
		return -1;
	}

	void start(Game *game) {
		this->game = game;
		(_beginthreadex(NULL, 0, run, (void*)this, 0, NULL));
	}
};