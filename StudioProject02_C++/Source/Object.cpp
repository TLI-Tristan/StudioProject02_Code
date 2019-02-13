#include "Object.h"



Object::Object()
{
}

Object::Object(const Vector3& pos, bool isItMoving, bool isItMovable, int rangeLength, int rangeWidth, int rangeHeight, bool isCollisionON, float speed, float mass)
{
	this->position = pos;
	this->movingObj = isItMoving;
	this->movableObj = isItMovable;
	this->sizeLength = rangeLength;
	this->sizeWidth = rangeWidth;
	this->sizeHeight = rangeHeight;
	this->collisionON = isCollisionON;
	this->speed = speed;
	this->mass = mass;

}


Object::~Object()
{
}
