#include "Player.h"



Player::Player(const Vector3& dir)
{
	horsePower = 100;
	speed = 0.0;
	acceleration = 0.0;
	
	
	this->direction = dir;
	//this->up = up;
	
}

Player::Player() {

}

Player::~Player()
{
}

void Player::calAcceleration() {

	acceleration = horsePower / getMass();

}

