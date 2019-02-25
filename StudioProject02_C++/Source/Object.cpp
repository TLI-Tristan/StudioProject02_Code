#include "Object.h"



Object::Object()
{
}

Object::Object(const Vector3& pos, bool isItMoving, bool isItMovable, float rangeX, float rangeY, float rangeZ, Vector3 speed, float mass, const Vector3& dir, std::string name)
{
	this->position = pos;
	this->movingObj = isItMoving;
	this->movableObj = isItMovable;
	this->sizeX = rangeX;
	this->sizeY = rangeY;
	this->sizeZ = rangeZ;
	this->speed = speed;
	this->mass = mass;
	isItPlayer = false;
	this->name = name;
	this->direction = dir;

	this->initialX = pos.x;
	this->initialY = pos.y;
	this->initialZ = pos.z;
}


Object::~Object()
{

}

void Object::update(double dt)
{
	

	//if (name == "part1MoivngBlock") {


	//	if (position.x <= -50) {

	//		direction.x = 1;
	//	}
	//	if (position.x >= 50) {

	//		direction.x = -1;
	//	}

	//	position.x += speed.x * direction.x * dt;
	//}

	if (name == "movingBlock2") {


		if (position.z <= -940) {

			direction.z = 1;
		}
		if (position.z >= -650) {

			direction.z = -1;
		}

		position.z += speed.z * direction.z * dt;
	}

	if (name == "movingBlock3" || name == "movingBlock4") {


		if (position.z <= initialZ - 30) {

			direction.z = 1;
		}
		if (position.z <= initialZ + 30) {

			direction.z = -1;
		}

		position.z += speed.z * direction.z * dt;
	}

	

}

void Object::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, Entity* collidiedItem)
{
}

void Object::checkPoint2()
{
}
