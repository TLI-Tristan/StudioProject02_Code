#ifndef ENTITY_H
#define ENTITY_H

#include "Vector3.h"

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
	int getRangeLength();
	int getRangeWidth();
	int getRangeHeight();
	virtual void update() = 0;

protected:
	Vector3 position;
	bool movingObj; // see if the obj is moving.
	float speed; // ms^-1
	int sizeLength;
	int sizeWidth;
	int sizeHeight;
	float mass; // kg
	bool movableObj; // see if the obj is able to move upon collison
	bool collisionON;

	


};


#endif // !ENTITY_H
