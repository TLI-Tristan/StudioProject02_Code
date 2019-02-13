#pragma once
#include "Entity.h"
class Object : public Entity
{
public:
	Object();
	Object(const Vector3& pos, bool isItMoving, bool isItMovable, int rangeLength, int rangeWidth, int rangeHeight, bool isCollisionON, float speed, float mass);
	~Object();
};

