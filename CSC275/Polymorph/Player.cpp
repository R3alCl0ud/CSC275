#include "Player.h"



Player::Player() : Character(0, 0)
{
	Player("", 1);

}
Player::Player(string n, int l) : Character(0, 0)
{
	setName(n);
	setLives(l);
}


Player::~Player()
{
}

void Player::printInfo(bool custom) {
	if (custom == true) {
		printf("Player Info:\n\tName: %s, Lives: %i\n\n", this->getName().c_str(), this->getLives());
	}
	else {
		Character::printInfo(false);
	}
}

void Player::setName(string n) {
	this->name = n;
}
void Player::setLives(int l) {
	if (l >= 1) {
		this->lives = l;
	}
}

int Player::getLives() { return this->lives; }

string Player::getName() { return this->name; }

