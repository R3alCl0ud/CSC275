#include "Player.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

int main(int argc, char** argv) {


	Player* player = new Player("Perry", 3);
	Enemy* zombie = new Enemy("Zombie", 30);
	Character* character = new Character(10, 40);

	player->printInfo(true);
	player->printInfo(false);
	player->setAttack(20);
	player->printInfo(true);
	player->printInfo(false);
	zombie->printInfo(true);
	character->printInfo(false);

	system("pause");

	return 0;
}