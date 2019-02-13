#include "Object.h"



Object::Object()
{
}

Object::Object(const Vector3& pos, bool isItMoving, bool isItMovable, float rangeX, float rangeY, float rangeZ, bool isCollisionON, float speed, float mass, std::string name)
{
	this->position = pos;
	this->movingObj = isItMoving;
	this->movableObj = isItMovable;
	this->sizeX = rangeX;
	this->sizeY = rangeY;
	this->sizeZ = rangeZ;
	this->collisionON = isCollisionON;
	this->speed = speed;
	this->mass = mass;
	isItPlayer = false;
	this->name = name;
}


Object::~Object()
{

}

void Object::update()
{
	if (name == "gong") {

		if (Application::IsKeyPressed('Q'))
		{
			position.x -= 1.0;
		}

		if (Application::IsKeyPressed('E'))
		{
			position.x += 1.0;
		}

	}

	

}
