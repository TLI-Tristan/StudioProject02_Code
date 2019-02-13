#ifndef COLLISION_H
#define COLLISION_H

#include "Entity.h"
#include "Object.h"
#include "Player.h"
#include <vector>

class Collision
{
public:
	Collision();
	~Collision();
	bool CollisionCheck(std::vector <Entity*> &entityPtr);

};

#endif