#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Collision.h"

class Player : public Entity 
{
public:
	Player();
	Player(const Vector3& dir);
	void calAcceleration();
	~Player();
	void checkKeypress();
	Collision collisionDetector;

private:

	float horsePower;
	float acceleration; // ms^-2 //need to decide myself
	Vector3 direction;


	// pointer to revive point


};

#endif

