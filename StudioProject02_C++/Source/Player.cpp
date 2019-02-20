#include "Player.h"
#include "Application.h"

Player::Player(const Vector3& pos, const Vector3& dir, float rangeX, float rangeY, float rangeZ, float mass, std::string name)
{
	this->position = pos;
	this->movingObj = false;
	this->movableObj = true;
	this->sizeX = rangeX;
	this->sizeY = rangeY;
	this->sizeZ = rangeZ;
	this->direction = dir;
	this->mass = mass;
	this->horsePower = 10000;
	this->jumpForce = 10000;
	speed = (0.0, 0.0, 0.0);
	acceleration = (0.0, 0.0, 0.0);
	deceleration = (0.0, 0.0, 0.0);;
	ghostMode = false;
	isItPlayer = true;
	this->name = name;
	this->impulseDone = true;
	calAcceleration();
	calDeceleration();
	this->collidingWithFloor = true;
	this->falling = true;
	this->part2CheckpointReached = false;
	this->cameraChanged = false;
	this->collidiedItem = nullptr;

}

Player::Player() {

}

Player::~Player()
{
}

void Player::calAcceleration() {

	acceleration.z = (horsePower - c_Physics.calFriction(this->mass) ) / this->mass;
	acceleration.x = 0;
	acceleration.y = (jumpForce - c_Physics.calWeight(this->mass)) / this->mass;

}

void Player::calDeceleration() {

	deceleration.z = (c_Physics.calFriction(this->mass) / this->mass);
	deceleration.x = (c_Physics.calFriction(this->mass) / this->mass);
	deceleration.y = (c_Physics.calWeight(this->mass) / this->mass);
}

void Player::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, Entity* collidedItem)
{
	collided = isThereCollision;
	this->collidingWithFloor = true;
	this->collidiedItem = collidedItem;
}

void Player::update(double dt)
{

	if (name == "player01") {


			if (collided == true && collidiedItem != nullptr && impulseDone == true) {

				if (collidiedItem->getName() != "platform") {

					if (collidiedItem->getAbletoMove() == false && collidiedItem->getIsItMoving() == false) {

						speed.z = c_Physics.calFinalSpeed(mass, speed.z);
						direction.z *= -1;
						speed.z *= direction.z;
						impulseDone = false;
					
					}
					else if(collidiedItem->getAbletoMove() == false && collidiedItem->getIsItMoving() == true) {

						if(collidiedItem->getDirection().x != 0){

							if (collidiedItem->getDirection().x == direction.x || direction.x == 0) {

								//speed.x += c_Physics.calFinalSpeed(collidiedItem->getMass(), collidiedItem->getSpeed().x);
								speed.x = 5;
								speed.x *= collidiedItem->getDirection().x;
								impulseDone = false;

							}
							else {
								speed.x -= c_Physics.calFinalSpeed(collidiedItem->getMass(), collidiedItem->getSpeed().x);
								direction.x *= -1;
								speed.x *= direction.x;
								impulseDone = false;
							}

						}
						else if (collidiedItem->getDirection().y != 0) {

							if (collidiedItem->getDirection().y == direction.y || direction.y == 0) {

								speed.y += c_Physics.calFinalSpeed(collidiedItem->getMass(), collidiedItem->getSpeed().y);
								speed.y *= collidiedItem->getDirection().y;
								impulseDone = false;

							}
							else {

								speed.y -= c_Physics.calFinalSpeed(collidiedItem->getMass(), collidiedItem->getSpeed().y);
								direction.y *= -1;
								speed.y *= direction.y;
								impulseDone = false;

							}

						}
						else if (collidiedItem->getDirection().z != 0) {

							if (collidiedItem->getDirection().z == direction.z || direction.z == 0) {

								speed.z += c_Physics.calFinalSpeed(collidiedItem->getMass(), collidiedItem->getSpeed().z);
								speed.z *= collidiedItem->getDirection().z;
								impulseDone = false;

							}
							else {

								speed.z -= c_Physics.calFinalSpeed(collidiedItem->getMass(), collidiedItem->getSpeed().z);
								direction.z *= -1;
								speed.z *= direction.z;
								impulseDone = false;

							}

						}


					}

				}

			}

			if (impulseDone == false) {

				if (speed.x > -0.05 && speed.x < 0.05 && 
					speed.y > -0.05 && speed.y < 0.05 &&
					speed.z > -0.05 && speed.z < 0.05) {

					speed.x = 0.0;
					speed.y = 0.0;
					speed.z = 0.0;
					impulseDone = true;
					collided = false;
				}

				if (speed.z > 0.0) {

					speed.z -= deceleration.z * dt;

				}
				else if (speed.z < 0.0) {

					speed.z += deceleration.z * dt;  
				}

				if (speed.x > 0.0) {

					speed.x -= deceleration.x * dt;

				}
				else if (speed.x < 0.0) {

					speed.x += deceleration.x * dt;
				}

				position.z += speed.z;
				position.x += speed.x;

			}
		
		

		if (falling == true) {

			speed.y -= deceleration.y * dt;
			position.y += speed.y;

		}

		if (collidingWithFloor == true) {
			falling = false;
			speed.y = 0.0;
		}
		else {
			falling = true;
		}


		if (impulseDone == true) {

			if (Application::IsKeyPressed('Z'))
			{
				direction.z = 1;
				if (speed.z < 0.8) {
					speed.z += acceleration.z * dt * direction.z;
				}
				position.z += speed.z;
				movingObj = true;
			}

			if (Application::IsKeyPressed('X'))
			{
				direction.z = -1;
				if (speed.z > -0.8) {
					speed.z += acceleration.z * dt * direction.z;
					movingObj = true;
				}
				position.z += speed.z;
				movingObj = true;
			}

			if (!Application::IsKeyPressed('Z') &&
				!Application::IsKeyPressed('X')) {

				direction = (0, 0, 0);
				if (speed.z > -0.05 && speed.z < 0.05) {

					speed.z = 0.0;
				}

				if (speed.z > 0.0) {

					speed.z -= deceleration.z * dt;
				}
				else if (speed.z < 0.0) {

					speed.z += deceleration.z * dt;

				}

				position.z += speed.z;
			}

		}

	}
}



