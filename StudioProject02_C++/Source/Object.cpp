#include "Object.h"



Object::Object()
{
}

Object::Object(const Vector3& pos, bool isItMoving, bool isItMovable, float rangeX, float rangeY, float rangeZ, Vector3 speed, float mass, const Vector3& dir, std::string name)
{
	this->position = pos;
	this->movingObj = isItMoving;
	this->movableObj = isItMovable;
	this->sizeX = rangeX;
	this->sizeY = rangeY;
	this->sizeZ = rangeZ;
	this->speed = speed;
	this->mass = mass;
	isItPlayer = false;
	this->name = name;
	this->direction = dir;
}


Object::~Object()
{

}

void Object::update(double dt)
{
	if (name == "gong_trap") {

		if (position.x <= -60)
		{
			direction.x = 1;
		}

		if (position.x >= 60)
		{
			direction.x = -1;
		}

		position.x += speed.x * dt* direction.x;

		

	}

	if (name == "cube") {

		/*if (position.z <= -60)
		{
			direction.z = 1;
		}

		if (position.z >= -20)
		{
			direction.z = -1;
		}

		position.z += speed.z * dt* direction.z;*/


		if (Application::IsKeyPressed('U')) {

			position.y += 50 * dt;

		}
		if (Application::IsKeyPressed('J')) {

			position.y -= 50 * dt;

		}
		if (Application::IsKeyPressed('T')) {

			position.x += 50 * dt;

		}
		if (Application::IsKeyPressed('G')) {

			position.x -= 50 * dt;

		}
		if (Application::IsKeyPressed('H')) {

			position.z += 50 * dt;

		}
		if (Application::IsKeyPressed('F')) {

			position.z -= 50 * dt;

		}

	}


	if (name == "part1MoivngBlock") {


		if (position.x <= -50) {

			direction.x = 1;
		}
		if (position.x >= 50) {

			direction.x = -1;
		}

		position.x += speed.x * direction.x * dt;
	}



	

}

void Object::collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, Entity* collidiedItem)
{
}