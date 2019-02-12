#include "Entity.h"



Entity::Entity(const Vector3& pos, bool isItMoving, bool isItMovable)
{
	this->position = pos;
	this->movingObj = isItMoving;
	this->movableObj = isItMovable;

}

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