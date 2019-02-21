#include "Entity.h"

Entity::Entity() {

}

Entity::~Entity()
{
}

float Entity::getMass() {

	return mass;
}

Vector3 Entity::getSpeed() {

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

float Entity::getHeighestX()
{
	return (position.x + sizeX);
}

float Entity::getHeighestY()
{
	return (position.y + sizeY);
}

float Entity::getHeighestZ()
{
	return (position.z + sizeZ);
}

float Entity::getLowestX()
{
	return (position.x - sizeX);
}

float Entity::getLowestY()
{
	return (position.y - sizeY);
}

float Entity::getLowestZ()
{
	return (position.z - sizeZ);
}

Vector3 Entity::getDirection()
{
	return direction;
}

bool Entity::getIsItPlayer()
{
	return isItPlayer;
}

std::string Entity::getName()
{
	return name;
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

bool Entity::getIsItMoving() {

	return movingObj;
}