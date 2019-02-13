#include "Entity.h"

Entity::Entity() {

}

Entity::~Entity()
{
}

float Entity::getMass() {

	return mass;
}

float Entity::getSpeed() {

	return speed;
}

Vector3 Entity::getPosition()
{
	return position;
}

int Entity::getPosX()
{
	return position.x;
}

int Entity::getPosY()
{
	return position.y;
}

int Entity::getPosZ()
{
	return position.z;
}

int Entity::getRangeLength()
{
	return sizeLength;
}

int Entity::getRangeWidth()
{
	return sizeWidth;
}

int Entity::getRangeHeight()
{
	return sizeHeight;
}

void Entity::updateSpeedStatus() {

	if (speed == 0.0) {
		movingObj = false;
	}
	else {
		movingObj = true;
	}

}

bool Entity::getAbletoMove() {
	
	return movableObj;
}