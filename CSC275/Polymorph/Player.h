#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
class Player : public Character {
public:
	Player();
	Player(string n, int l);
	~Player();
	void setLives(int lives);
	int getLives();
	string getName();
	void setName(string n);
	virtual void printInfo(bool custom) override;
private:
	int lives;
	string name;
};

#endif