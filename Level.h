#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Monsters.h"
//#include "Blessings.h"

using namespace std;

class Level
{
public:
	Level();
	void loadlevel(string fileName, Player &player);
	void print();
	void tryMove(char input, Player& player);
	//getting where the player is placed in space
	char getSpace(int x, int y);
	//changes the spaces to the correct ones based on player
	void setSpace(int x, int y, char space);
	void battle(Player& player, int newX, int newY);
	//void bonuses(Player& player, int newX, int newY);

private:
	void processPlayerMoves(Player& player, int newX, int newY);
	vector <string> _levelData;
	vector <Monsters> _monster;
	//vector <Blessings> _blessings;
};