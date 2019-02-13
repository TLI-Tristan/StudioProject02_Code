#pragma once
#include "Entity.h"
#include "Application.h"

class Object : public Entity
{
public:
	Object();
	Object(const Vector3& pos, bool isItMoving, bool isItMovable, int rangeLength, int rangeWidth, int rangeHeight, bool isCollisionON, float speed, float mass, std::string name);
	~Object();
	void update();

};

