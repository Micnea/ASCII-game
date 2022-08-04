#pragma once
#include "Player.h"
#include "Level.h"
//#include "Blessings.h"
#include <string>

using namespace std;

class GameMech
{
public:
	GameMech(string levelfilename);

	void startGame();
	void playerMovement();
	

private:
	Level _Level;
	Player _player;
	//Blessings _blessings;
};