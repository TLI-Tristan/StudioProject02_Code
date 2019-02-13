#include "Player.h"
#include "Application.h"

Player::Player(const Vector3& pos, const Vector3& dir, float rangeX, float rangeY, float rangeZ, bool isCollisionON, float mass, std::string name)
{
	this->position = pos;
	this->movingObj = false;
	this->movableObj = true;
	this->sizeX = rangeX;
	this->sizeY = rangeY;
	this->sizeZ = rangeZ;
	this->collisionON = isCollisionON;
	this->direction = dir;
	this->mass = mass;
	horsePower = 100;
	speed = 0.0;
	acceleration = 0.0;
	changeCamera = false;
	ghostMode = true;
	isItPlayer = true;
	this->name = name;
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

void Player::update()
{
}
