#pragma once
#include "Entity.h"
#include "Application.h"

class Object : public Entity
{
public:
	Object();
	Object(const Vector3& pos, bool isItMoving, bool isItMovable, float rangeX, float rangeY, float rangeZ, Vector3 speed, float mass, std::string name);
	~Object();
	void update(double dt);
	void collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, std::string collidedItem);

};

