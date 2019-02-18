#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity 
{
public:
	Player();
	~Player();
	Player(const Vector3& pos, const Vector3& dir, float rangeX, float rangeY, float rangeZ, float mass, std::string name);
	void calAcceleration();
	void calDeceleration();
	void collisionDetector(bool isThereCollision, bool isItCollidingWithFloor, std::string collidedItem);
	void update(double dt);

private:

	float horsePower;
	float jumpForce;
	Vector3 acceleration; // ms^-2 //need to decide myself
	Vector3 deceleration;
	Vector3 direction;
	bool changeCamera;
	bool ghostMode;
	bool collided;
	bool impulseDone;
	bool jumping;
	bool collidingWithFloor;
	bool falling;
	bool impulseON;
	std::string collidedItemName;
	// pointer to revive point


};

#endif

