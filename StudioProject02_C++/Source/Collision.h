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
	bool collisionCheck(std::vector <Entity*> &entityPtr);
	void collisionImpact(Entity& firstEntity, Entity& secondEntity);
	

};

#endif