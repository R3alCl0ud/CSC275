#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
class Enemy : public Character
{
public:
	Enemy();
	Enemy(string t, int h);
	~Enemy();
	virtual void printInfo(bool custom) override;
	void setType(string t);
	void setHealth(int d);
	int getHealth();
	string getType();
private:
	string type;
	int health;

};
#endif // !ENEMY_H

