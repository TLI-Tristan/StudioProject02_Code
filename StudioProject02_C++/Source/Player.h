#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

// splitscreen
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Player : public Entity 
{
public:
	Player();
	~Player();
	Player(const Vector3& pos, const Vector3& dir, float rangeX, float rangeY, float rangeZ, float mass, std::string name);
	void calAcceleration();
	void calDeceleration();
	void collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, Entity* collidiedItem);
	void update(double dt);
	void checkPoint2();

private:

	float horsePower;
	float jumpForce;
	Vector3 acceleration; // ms^-2 //need to decide myself
	Vector3 deceleration;
	bool part2CheckpointReached;
	bool cameraChanged;
	bool ghostMode;
	bool collided;
	bool impulseDone;
	bool collidingWithFloor;
	bool falling;

	Entity* collidiedItem;


};

#endif

