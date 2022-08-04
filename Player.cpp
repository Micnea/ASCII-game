#include "Player.h"
#include <random>
#include <time.h>
#include <iostream>
#include <Windows.h>

using namespace std;

//intializes position to 0
Player::Player() {
	_x = 0;
	_y = 0;
}

//intializes player properties
void Player::init(int health, int attack, int defense, int level, int experience) {
	_health = health;
	_attack = attack;
	_defense = defense;
	_level = level;
	_experience = experience;
}

int Player::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackvalueroll(2, _attack);
	return attackvalueroll(randomEngine);
}


int Player::health() {
	int maxHealth = 100;

	while (_health < 50) {
		_health = _health + (maxHealth * 0.1);
	}
	if (_health > maxHealth) {
		_health = maxHealth;
	}
	
	return _health;
}


void Player::addExperience(int experience) {
	_experience += experience;
	int maxHealth = 100;
	//leveling up
	if (_experience >= 100) {
		printf("You have leveled up!\n");
		_experience -= 100;
		_level++;
		_attack += 5;
		_health = maxHealth + (maxHealth * 0.1);
		_defense += 7;
		system("PAUSE");
	}
}
/*
void Player::bonusatk(int attack) {
	_attack += attack*0.2;
}

void Player::bonusdef(int defense) {
	_defense += defense * 0.1;
}

void Player::bonushp(int health) {
	_health += health * 0.1;
}
*/

int Player::experience() {
	return _experience;
}

int Player::level() {
	return _level;
}

int Player::damageTaken(int attack) {
	attack = attack - _defense;
	if (attack > 0) {
		_health = _health - attack;
		if (_health <= 0) {
			return 1;
		}
		
	}
	return 0;
}

//setting player position
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

//getting position of the player using reference variables
void Player::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}