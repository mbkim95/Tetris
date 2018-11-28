#include <iostream>
#include <Windows.h>
#include "Key.h"
using namespace std;

int main() {
	Game* game = new Game();
	KeyEvent key;
	key.start(game);
	
	game->start();
	while (1) {

	}
}