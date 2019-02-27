//****************************************//
// file: Entity.h
// by: HuiFeng(Tristan) 
//
// this is used for all the objects in game, including players
// refer to derived class for more details
//
// if any question just ask me.
// let me know if you change anyting here too
//
//****************************************//
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
	bool getIsItMoving();
	bool getAbletoMove();
	float getMass();
	Vector3 getSpeed();
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

	Vector3 getDirection();
	bool respawn;

	virtual void update(double dt) = 0;
	virtual void collisionDetector(bool isThereCollision, bool isItCollidingWithTheFloor, Entity* collidiedItem) = 0;
	bool getIsItPlayer();
	virtual void checkPoint2() = 0;
	std::string getName();
	Physics c_Physics;

protected:
	std::string name; // to differentiate each obj / player
	Vector3 direction; // direction the obj / player is moving
	Vector3 position; // current pos of the obj / player
	Vector3 initialPosition; //initial pos of the obj / player
	bool movingObj; // see if the obj is moving.
	Vector3 speed; // ms^-1
	float sizeX; // the size of collision box in x axis
	float sizeY; // the size of collision box in y axis
	float sizeZ; // the size of collision box in z axis
	float heighest_X; // the heighest size of collision box in x axis
	float heighest_Y; // the heighest size of collision box in y axis
	float heighest_Z; // the heighest size of collision box in z axis
	float lowest_X; // the lowest size of collision box in x axis
	float lowest_Y ;// the lowest size of collision box in y axis
	float lowest_Z; // the lowest size of collision box in z axis
	float mass; // kg
	bool movableObj; // see if the obj is able to move upon collison
	bool isItPlayer; // to differentiate obj from player
	double dt;


};


#endif // !ENTITY_H
