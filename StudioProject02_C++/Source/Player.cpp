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
	deceleration = (0.0, 0.0, 0.0);
	changeCamera = false;
	ghostMode = true;
	isItPlayer = true;
	this->name = name;
	this->impulseDone = true;
	calAcceleration();
	calDeceleration();
	this->jumping = false;
	this->collidingWithFloor = true;
	this->falling = true;
	this->impulseON = false;
	
}

Player::Player() {

}

Player::~Player()
{
}

void Player::calAcceleration() {

	acceleration.z = (horsePower - c_Physics.calFriction(this->mass) ) / this->mass;

	acceleration.y = (jumpForce - c_Physics.calWeight(this->mass)) / this->mass;

}

void Player::calDeceleration() {

	deceleration.z = (c_Physics.calFriction(this->mass) / this->mass);

	deceleration.y = (c_Physics.calWeight(this->mass) / this->mass);
}

//void Player::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor)
//{
//	collided = isThereCollision;
//	this->collidingWithFloor = isItCollidingWithFloor;
//}

void Player::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, std::string collidedItem)
{
	collided = isThereCollision;
	//this->collidingWithFloor = isItCollidingWithFloor;
	this->collidingWithFloor = true;
	this->collidedItemName = collidedItem;
}

void Player::update(double dt)
{

	if (name == "player01") {

		if (impulseON == true) {
			if (collided == true && collidedItemName != "platform") {


				speed.z = c_Physics.calFinalSpeed(mass, speed.z);
				impulseDone = false;


			}

			if (impulseDone == false) {

				if (speed.z > -0.05 && speed.z < 0.05) {

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

				position.z += speed.z;

			}
		}
		

		if (falling == true && jumping == false) {

			speed.y -= deceleration.y * dt;
			position.y += speed.y;

		}

		if (collidingWithFloor == true) {
			falling = false;
		}
		else {
			falling = true;
		}

		if (jumping == true) {

			speed.y -= deceleration.y * dt;
			position.y += speed.y;

			if (position.y > -1 && position.y < 1) {
				speed.y = 0.0;
				jumping = false;
			}

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

			if (Application::IsKeyPressed(VK_SPACE) && jumping == false && collidingWithFloor == true)
			{
				jumping = true;
				direction.y = 1;
				speed.y = 2.0;
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

//void Player::update(double dt)
//{
//
//	if (name == "player01") {
//
//		if (collided == true && collidingWithFloor == false) {
//				speed.z = c_Physics.calFinalSpeed(mass, speed.z);
//				impulseDone = false;
//
//		}
//
//		if (impulseDone == false) {
//
//			if (speed.z > -0.05 && speed.z < 0.05) {
//
//				speed.z = 0.0;
//				impulseDone = true;
//				collided = false;
//			}
//
//			if (speed.z > 0.0) {
//
//				speed.z -= deceleration.z * dt;
//			}
//			else if (speed.z < 0.0) {
//
//				speed.z += deceleration.z * dt;
//			}
//
//			position.z += speed.z;
//			
//		}
//
//		/*if (collidingWithFloor == false && falling == false) {
//
//			falling = true;
//			speed.y = 0.0;
//
//		}*/
//
//		if (falling == true && jumping == false) {
//
//			speed.y -= deceleration.y * dt;
//			position.y += speed.y;
//
//		}
//
//		if (collidingWithFloor == true) {
//			falling = false;
//		}
//		else {
//			falling = true;
//		}
//
//		if (jumping == true) {
//
//			speed.y -= deceleration.y * dt;
//			position.y += speed.y;
//
//			if (position.y > -1 && position.y < 1) {
//				position.y = 0.0;
//				jumping = false;
//			}
//
//		}
//
//
//		if (impulseDone == true) {
//
//			if (Application::IsKeyPressed('Z'))
//			{
//				direction.z = 1;
//				if (speed.z < 0.8) {
//					speed.z += acceleration.z * dt * direction.z;
//				}
//				position.z += speed.z;
//				movingObj = true;
//			}
//
//			if (Application::IsKeyPressed('X'))
//			{
//				direction.z = -1;
//				if (speed.z > -0.8) {
//					speed.z += acceleration.z * dt * direction.z;
//					movingObj = true;
//				}
//				position.z += speed.z;
//				movingObj = true;
//			}
//
//			if (Application::IsKeyPressed(VK_SPACE) && jumping == false && collidingWithFloor == true)
//			{
//				jumping = true;
//				direction.y = 1;
//				speed.y = 2.0;
//			}
//
//
//			if (!Application::IsKeyPressed('Z') &&
//				!Application::IsKeyPressed('X')) {
//
//				direction = (0, 0, 0);
//				if (speed.z > -0.05 && speed.z < 0.05) {
//
//					speed.z = 0.0;
//				}
//
//				if (speed.z > 0.0) {
//
//					speed.z -= deceleration.z * dt;
//				}
//				else if (speed.z < 0.0) {
//
//					speed.z += deceleration.z * dt;
//
//				}
//
//				position.z += speed.z;
//			}
//
//		}
//
//	}
//}


