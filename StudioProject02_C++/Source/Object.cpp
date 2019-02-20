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
}


Object::~Object()
{

}

void Object::update(double dt)
{
	if (name == "gong_trap") {

		/*if (position.x <= -60)
		{
			direction.x = 1;
		}

		if (position.x >= 60)
		{
			direction.x = -1;
		}

		position.x += speed.x * dt* direction.x;*/
		if (Application::IsKeyPressed('Q')) {
			position.x -= 100 * dt;
		}
		if (Application::IsKeyPressed('E')) {
			position.x += 100 * dt;
		}

	}





	

}

void Object::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, std::string collidedItem)
{
}