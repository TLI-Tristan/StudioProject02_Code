//****************************************//
// file physics.h
//
//
//
//****************************************//
#ifndef PHYSICS_H
#define PHYSICS_H

#include "Entity.h"

class Physics {
public:
	Physics();
	~Physics();
	float calFinalKE(Entity &firstEntity,Entity &secondEntity);
	float calMomentum(Entity &movingEntity);
	float calKineticEnergy(Entity &movingEntity);
	float calFriction(Entity &movingEntity);

private:
	float gravity;
	float coeffFriction;
	



};

#endif 