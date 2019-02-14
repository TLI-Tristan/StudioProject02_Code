#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity 
{
public:
	Player();
	Player(const Vector3& pos, const Vector3& dir, float rangeX, float rangeY, float rangeZ, bool isCollisionON, float mass, std::string name);
	void calAcceleration();
	void calDeceleration();
	~Player();
	void checkKeypress();
	void update(double dt);

private:

	float horsePower;
	float acceleration; // ms^-2 //need to decide myself
	float deceleration;
	Vector3 direction;
	bool changeCamera;
	bool ghostMode;

	// pointer to revive point


};

#endif

