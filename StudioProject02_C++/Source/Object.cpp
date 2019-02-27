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

	this->initialPosition = pos;
}


Object::~Object()
{

}

void Object::update(double dt)
{
	

	if (name == "part1MoivngBlock") {


		if (position.x <= -50) {

			direction.x = 1;
		}
		if (position.x >= 50) {

			direction.x = -1;
		}

		position.x += speed.x * direction.x * dt;
	}

	if (name == "movingBlock2" || name == "movingBlock5") {


		if (position.z <= -940) {

			direction.z = 1;
		}
		if (position.z >= -650) {

			direction.z = -1;
		}

		position.z += speed.z * direction.z * dt;
	}

	if (name == "movingBlock3" || name == "movingBlock4" || name == "movingBlock6") {


		if (position.z <= initialPosition.z - 30) {

			direction.z = 1;
		}
		if (position.z >= initialPosition.z + 30) {

			direction.z = -1;
		}

		position.z += speed.z * direction.z * dt;
	}

	if (name == "crusher") {

		if (position.y >= initialPosition.y + 40) {

			position.y = initialPosition.y;

		}
		else {

			position.y += speed.y * direction.y * dt;

		}



	}


	if (name == "movingspike") {

		if (direction.z == 1 && position.z >= -810) {

			position.z = initialPosition.z;

		}
		else if(direction.z == -1 && position.z <= -800){

			position.z = initialPosition.z;

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
