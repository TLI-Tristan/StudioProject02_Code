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
	bool collisionCheck(Entity& firstEntity, std::vector <Entity*> &entityPtr);
	bool checkCollisionWithTheFloor(Entity& firstEntity, std::vector <Entity*> &entityPtr);

	Entity* getCollidiedItem();


private:
	std::string collidedItemName;
	Entity* collidiedItem;
	

};

#endif