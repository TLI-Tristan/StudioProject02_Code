#ifndef ENTITY_H
#define ENTITY_H

#include "Vector3.h"

class Entity
{
public:
	Entity(const Vector3& pos, bool isItMoving, bool isItMovable);
	Entity();
	~Entity();
	void updateSpeedStatus();
	virtual checkKeypress() = 0;
	bool getAbletoMove();
	float getMass();
	float getSpeed();

protected:
	Vector3 position;
	bool movingObj; // see if the obj is moving.
	float speed; // ms^-1

private:
	float mass; // kg
	bool movableObj; // see if the obj is able to move upon collison


};


#endif // !ENTITY_H
