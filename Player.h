#pragma once


class Player
{
public:
	//player ints
	Player();
	void init(int health, int attack, int defense, int level, int experience);

	//setting player position
	void setPosition(int x, int y);

	//getting player position
	void getPosition(int &x, int &y);

	void addExperience(int experience);
	//void bonusatk(int attack);
	//void bonusdef(int defense);
	//void bonushp(int health);

	int attack();
	int damageTaken(int attack);
	int health();
	int experience();
	int level();
	


private:
	//player properties
	int _health;
	int _attack;
	int _defense;
	int _level;
	int _experience;

	//player positions
	int _x;
	int _y;
};

