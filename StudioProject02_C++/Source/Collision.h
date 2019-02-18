#ifndef COLLISION_H
#define COLLISION_H

#include "Entity.h"
#include "Object.h"
#include "Player.h"
#include <vector>
#include "Physics.h"

class Collision
{
public:
	Collision();
	~Collision();
	bool getIsItCollidingWithFloor();
	bool collisionCheck(std::vector <Entity*> &entityPtr);
	bool collisionCheck(Entity& firstEntity, std::vector <Entity*> &entityPtr);

private:
	bool isItCollidingWithFloor;
	

};

#endif