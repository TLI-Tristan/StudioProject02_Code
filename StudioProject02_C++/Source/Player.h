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
	Player(const Vector3& pos, const Vector3& dir, float rangeX, float rangeY, float rangeZ, float mass, std::string name, bool control);
	void calAcceleration();
	void calDeceleration();
	void collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, Entity* collidiedItem); //check for collision with platform / floor and obj, and get the collided item 
	void update(double dt); // move the player accoring to key pressed or receive impulse etc
	void checkPoint2(); // if player reached checkpoint 2
	void respawnAtLastCheckpoint(); //respawn when fall off playform

private:

	float horsePower; // the forward force
	Vector3 acceleration; // ms^-2 //need to decide myself
	Vector3 deceleration; // ms^-2
	bool part2CheckpointReached; // to see if player have reached check point
	bool collided; // if player collided with any obj except floor/ plaform
	bool impulseDone; // if player have finished receiving the impulse
	bool collidingWithFloor; // if player is on the platform, if not player will fall
	bool falling; // if player is falling off platform
	bool control; //to enable all controls or not

	Entity* collidiedItem; // to receive what item the player is colliding with
	


};

#endif

