#include "Monsters.h"
#include <random>
#include <time.h>
#include <iostream>


using namespace std;



Monsters::Monsters(string name, char space, int level, int attack, int defense, int health, int xp) {
	_name = name;
	_space = space;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_xpValue = xp;
}
//setting monster position
void Monsters::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

//getting position of the monster
void Monsters::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}

int Monsters::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackvalueroll(0, _attack);
	return attackvalueroll(randomEngine);
}

int Monsters::damageTaken(int attack) {
	attack -= _defense;
	if (attack > 0) {
		_health -= attack;
		if (_health <= 0) {
			return _xpValue;
		}
	}
	return 0;
}