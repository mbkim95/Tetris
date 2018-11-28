#pragma once
#include <iostream>
#include <Windows.h>
#include "Key.h"
using namespace std;

BOOL WINAPI MoveWindow(_In_ HWND hwnd, _In_ int x, _In_ int y, _In_ int nWidth, _In_ int nHeight, _In_ BOOL bRepaint);

class Desk {
public:
	Desk() {
		HWND console = GetConsoleWindow();
		MoveWindow(console, 100, 200, 500, 550, TRUE);
		newDesk();
	}

	void newDesk() {
		cout << endl << "콘솔 위치 및 가로세로 크기 설정" << endl;
		cout << "□□□□□□□□□□□□" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□□□□□□□□□□□□" << endl;
	}

	void printDesk() {
		cout << endl;
		cout << "□□□□□□□□□□□□" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□                    □" << endl;
		cout << "□□□□□□□□□□□□" << endl;
	}
};