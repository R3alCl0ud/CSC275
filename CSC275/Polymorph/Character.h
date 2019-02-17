#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class Character
{
public:
	Character();
	Character(int attack, int defense);
	~Character();
	int getDefense();
	int getAttack();
	void setAttack(int a);
	void setDefense(int h);
	virtual void printInfo();
	virtual void printInfo(bool custom);
private:
	int attack;
	int defense;
};
#endif 
