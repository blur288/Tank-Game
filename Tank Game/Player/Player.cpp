#include "Player.h"

Player::Player()
{
	this->Y = rand() % 11;
	this->X = rand() % 19;

	this->HealthPoints = 3;
}
