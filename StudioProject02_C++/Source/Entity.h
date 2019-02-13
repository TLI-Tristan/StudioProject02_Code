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
	int getRangeX();
	int getRangeY();
	int getRangeZ();
	virtual void update() = 0;
	bool getIsItPlayer();
	std::string getName();

protected:
	std::string name;
	Vector3 position;
	//float posX;
	//float posY;
	//float posZ;
	bool movingObj; // see if the obj is moving.
	float speed; // ms^-1
	int sizeX;
	int sizeY;
	int sizeZ;
	float mass; // kg
	bool movableObj; // see if the obj is able to move upon collison
	bool collisionON;
	bool isItPlayer;

	


};


#endif // !ENTITY_H
