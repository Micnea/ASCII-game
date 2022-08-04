#include "GameMech.h"
#include <iostream>
#include <conio.h>
#include "Player.h"


//setup game
GameMech::GameMech(string levelfilename) {

	_player.init(100, 13, 4, 1, 0);
	_Level.loadlevel(levelfilename, _player);
	_Level.print();

	system("PAUSE");
}

void GameMech::startGame() {
	bool isDone = false;
	while (isDone == false) {
		_Level.print();
		playerMovement();
	}
}

//player moving on the map
void GameMech::playerMovement() {
		char input;
		cout << "Move comands are w|s|a|d \n" << "Player is @\n";
		cout << "HP:";
		cout << _player.health() << endl;
		cout << "Experience:" << _player.experience()<< endl;
		cout << "Level:" << _player.level()<<endl;
		input = _getch();
		_Level.tryMove(input, _player);
		
}


