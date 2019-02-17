#include "Enemy.h"

Enemy::Enemy() : Character(0,0)
{
	Enemy("", 0);
}

Enemy::Enemy(string t, int h) : Character(0, 0)
{
	this->setType(t);
	this->setHealth(h);
}

Enemy::~Enemy()
{
	delete &this->type;
}

void Enemy::printInfo(bool custom) {
	if (custom == true) {
		printf("Enemy Info:\n\tType: %s, Health: %i\n\n", this->getType().c_str(), this->getHealth());
	}
	else {
		Character::printInfo(false);
	}
}

void Enemy::setHealth(int h) {
	if (h >= 0) {
		this->health = 0;
	}
}

void Enemy::setType(string t) {
	this->type = t;
}

int Enemy::getHealth() {
	return this->health;
}

string Enemy::getType() {
	return this->type;
}