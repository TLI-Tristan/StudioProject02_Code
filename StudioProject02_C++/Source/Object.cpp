#include "Object.h"



Object::Object()
{
}

Object::Object(const Vector3& pos, bool isItMoving, bool isItMovable, float rangeX, float rangeY, float rangeZ, Vector3 speed, float mass, std::string name)
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
}


Object::~Object()
{

}

void Object::update(double dt)
{
	if (name == "gong") {

		if (Application::IsKeyPressed('Q'))
		{
			position.x -= 100.0 * dt;
		}

		if (Application::IsKeyPressed('E'))
		{
			position.x += 100.0 * dt;
		}

	}

	

}

void Object::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, std::string collidedItem)
{
}