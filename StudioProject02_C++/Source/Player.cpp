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
	horsePower = 10000;
	speed = 0.0;
	acceleration = 0.0;
	changeCamera = false;
	ghostMode = true;
	isItPlayer = true;
	this->name = name;
	this->impulseDone = true;
	calAcceleration();
	calDeceleration();

}

Player::Player() {

}

Player::~Player()
{
}

void Player::calAcceleration() {

	acceleration = (horsePower - c_Physics.calFriction(this->mass) ) / this->mass;

}

void Player::calDeceleration()
{
	deceleration = (c_Physics.calFriction(this->mass) / this->mass);
}

void Player::collisionDetector(bool isThereCollision)
{
	collided = isThereCollision;
}

void Player::update(double dt)
{

	if (name == "player01") {


		if (collided == true) {

			if (name == "player01") {

				speed = c_Physics.calFinalSpeed(mass, speed)/150;
				impulseDone = false;

			}

		}

		if (impulseDone == false) {

			if (name == "player01") {

				if (speed > -0.05 && speed < 0.05) {

					speed = 0.0;
					impulseDone = true;
					collided = false;
				}

				if (speed > 0.0) {

					speed -= deceleration * dt;
				}
				else if (speed < 0.0) {

					speed += deceleration * dt;
				}

				position.z += speed;
			}
		}

	}

	if (impulseDone == true) {

		if (Application::IsKeyPressed('Z'))
		{
			direction.z = 1;
			if (speed < 0.8) {
				speed += acceleration * dt * direction.z;
			}
			position.z += speed;
			movingObj = true;
		}
		if (Application::IsKeyPressed('X'))
		{
			direction.z = -1;
			if (speed > -0.8) {
				speed += acceleration * dt * direction.z;
				movingObj = true;
			}
			position.z += speed;
			movingObj = true;
		}

		if (!Application::IsKeyPressed('Z') &&
			!Application::IsKeyPressed('X')) {

			if (speed > -0.05 && speed < 0.05) {
				speed = 0.0;

			}

			if (speed > 0.0) {

				speed -= deceleration * dt;
			}
			else if (speed < 0.0) {


				speed += deceleration * dt;

			}

			position.z += speed;
		}

	}
}


