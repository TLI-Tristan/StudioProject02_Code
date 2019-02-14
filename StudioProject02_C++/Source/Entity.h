#ifndef ENTITY_H
#define ENTITY_H

#include "Vector3.h"

#include "Physics.h"

class Entity
{
public:
	Entity();
	~Entity();
	void updateSpeedStatus();
	bool getAbletoMove();
	float getMass();
	float getSpeed();
	Vector3 getPosition();
	int getPosX();
	int getPosY();
	int getPosZ();

	float getHeighestX();
	float getHeighestY();
	float getHeighestZ();
	float getLowestX();
	float getLowestY();
	float getLowestZ();

	virtual void update(double dt) = 0;
	bool getIsItPlayer();
	std::string getName();
	Physics c_Physics;

protected:
	std::string name;
	Vector3 position;
	bool movingObj; // see if the obj is moving.
	float speed; // ms^-1
	float sizeX;
	float sizeY;
	float sizeZ;
	float heighest_X;
	float heighest_Y;
	float heighest_Z;
	float lowest_X;
	float lowest_Y;
	float lowest_Z;
	float mass; // kg
	bool movableObj; // see if the obj is able to move upon collison
	bool collisionON;
	bool isItPlayer;
	double dt;

	


};


#endif // !ENTITY_H
