#include "Character.h"


Character::Character() {
	this->defense = 0;
	this->attack = 0;
}

Character::Character(int a, int d) {
	this->attack = a;
	this->defense = d;
}

Character::~Character() {

}

int Character::getDefense() {
	return this->defense;
}

int Character::getAttack() {
	return this->attack;
}

void Character::setAttack(int a) {
	this->attack = a;
}

void Character::setDefense(int d) {
	this->defense = d;
}

void Character::printInfo(bool custom) {
	printf("Character Info:\n\tAttack: %i, Defense: %i\n\n", this->getAttack(), this->getDefense());
}
void Character::printInfo() {
	printf("Character Info:\n\tAttack: %i, Defense: %i\n\n", this->getAttack(), this->getDefense());
}