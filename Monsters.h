#pragma once
#include <string>
using namespace std;


class Monsters
{
public:
	Monsters(string name, char space, int level, int attack, int defense, int health, int xp);
	
	//setting monster position
	void setPosition(int x, int y);

	//getting monster position
	void getPosition(int& x, int& y);
	string getName() { return _name; }

	int attack();
	int damageTaken(int attack);


private:
	string _name;//giving monsters names so they can be accesed
	char _space;
	//monster properties
	int _health;
	int _attack;
	int _defense;
	int _level;
	int _xpValue;
	//monster positions
	int _x;
	int _y;
};

