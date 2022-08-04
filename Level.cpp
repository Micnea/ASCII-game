#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>


Level::Level() {

}

void Level::loadlevel(string fileName, Player& player) {
	//loads level from file
	ifstream file;

	file.open(fileName);

	if (file.fail()) {
		cout << "ERROR WHILE LOADING THE LEVEL";
		system("PAUSE");
		exit(1);
	}

	string line;
	while (getline(file, line)) {
		_levelData.push_back(line);
	}

	

	//processes the level

	char space;

	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			space = _levelData[i][j];
			switch (space)
			{
			case '@': //player
				player.setPosition(j, i);
				break;
			case 'O'://ogre
				_monster.push_back(Monsters("Ogre", space, 1, 17, 1, 20, 60));
				_monster.back().setPosition(j, i);
				break;
			case 'S'://slime
				_monster.push_back(Monsters("Slime", space, 1, 13, 1, 15, 40));
				_monster.back().setPosition(j, i);
				break;
			/*case 'A'://attack bonus
				_blessings.push_back(Blessings("Bonus attack",space,5,0,0));
				_blessings.back().setPosition(j, i);
				break;*/
			}
		}
	}
}



//map printing on terminal
void Level::print() {

	cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}

	printf("\n");
}


//player moving on the map


void Level::tryMove(char input, Player& player) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch (input)
	{
		//move up
	case 'w':
	case 'W':
		processPlayerMoves(player, playerX, playerY - 1);
		break;
		//move down
	case 's':
	case 'S':
		processPlayerMoves(player, playerX, playerY + 1);
		break;
		//move left
	case 'a':
	case 'A':
		processPlayerMoves(player, playerX - 1, playerY);
		break;
		//move right
	case 'd':
	case 'D':
		processPlayerMoves(player, playerX + 1, playerY);
		break;
	default:
		printf("UNRECOGNISED INPUT\n");
		system("PAUSE");
		break;
	}
}

char Level::getSpace(int x, int y) {
	char space = _levelData[y][x];
	return space;
}

void Level::setSpace(int x, int y, char space) {
	_levelData[y][x] = space;
}

//processes the player movement in the space of hte map
void Level::processPlayerMoves(Player& player, int newX, int newY) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	char moveSpace = getSpace(newX, newY);
	switch (moveSpace)
	{
	case '.':
		//changes position of the player
		player.setPosition(newX, newY);
		//changes the current position from player to space
		setSpace(playerX, playerY, '.');
		//changes from space to a player based on the players movement
		setSpace(newX, newY, '@');
		break;
	case '#':
		break;
	/*case 'A':
		bonuses(player, newX, newY);*/
	default:
		battle(player, newX, newY);
	}
}
void Level::battle(Player& player, int newX, int newY) {
	int monsterX;
	int monsterY;
	int attackdmgroll;
	int attackrez;
	string monsterName; 

	for (int i = 0; i < _monster.size(); i++) {
		_monster[i].getPosition(monsterX, monsterY);
		monsterName = _monster[i].getName();
		if (newX == monsterX && newY == monsterY) {
			//player attack
			attackdmgroll = player.attack();
			printf("You have damaged the %s for %d damage \n",monsterName.c_str(), attackdmgroll);
			attackrez = _monster[i].damageTaken(attackdmgroll);
			if (attackrez != 0) {
				print();
				printf("The %s has died!\n", monsterName.c_str());
				system("PAUSE");
				player.addExperience(attackrez);
				setSpace(newX, newY, '.');
				return;
			}
			//monster attack
			attackdmgroll = _monster[i].attack();
			printf("You have taken %d damage \n",attackdmgroll);
			attackrez = player.damageTaken(attackdmgroll);
			if (attackrez == 1) {
				setSpace(newX, newY, 'X');
				print();
				printf("You died!\n");
				system("PAUSE");
				return;
			}
			system("PAUSE");
			return;	
		}
	}
}
/*
void Level::bonuses(Player& player, int newX, int newY) {
	int bonusX;
	int bonusY;
	int bonusrez;
	int bonus;
	string bonusName;



	for (int i = 0; i < _blessings.size(); i++) {
		_blessings[i].getPosition(bonusX, bonusY);
		bonusName = _blessings[i].getName();
		if (newX == bonusX && newY == bonusY) {
			printf("You have found the %d\n", bonusName.c_str());
			bonus = player.attack();
			bonusrez = _blessings[i].bonusatak(bonus);
			printf("The bleessing is now a part of you");
			system("PAUSE");
		}
	}
}
*/