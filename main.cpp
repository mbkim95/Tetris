#include <iostream>
#include <Windows.h>
#include "Key.h"
using namespace std;

int main() {
	Game* game = new Game();
	KeyEvent key;
	key.start(game);

	game->start();
	while (!game->isGameOver()) {

	}
	game->GameOver();
	Sleep(2000);
	system("cls");
	game->fileSave("score.txt", game->getScore());
	game->fileLoad();
}