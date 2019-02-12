#include "Player.h"
#include "Application.h"


Player::Player(const Vector3& dir)
{
	horsePower = 100;
	speed = 0.0;
	acceleration = 0.0;
	changeCamera = false;
	
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

void Player::checkKeypress() {

	if (changeCamera == false) {


		if (Application::IsKeyPressed('W')) {

		}
		if (Application::IsKeyPressed('S')) {

		}
		if (Application::IsKeyPressed('A')) {

		}
		if (Application::IsKeyPressed('D')) {

		}
	}
	else {



	}


}