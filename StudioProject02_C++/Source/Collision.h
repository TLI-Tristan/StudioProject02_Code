#ifndef COLLISION_H
#define COLLISION_H

#include "Entity.h"

class Collision
{
public:
	Collision();
	~Collision();
	bool CollisionCheck(Entity &firstEntity, Entity &secondEntity);

};

#endif