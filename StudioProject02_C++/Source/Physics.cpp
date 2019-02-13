#include "Physics.h"



Physics::Physics()
{
	gravity = 9.8;
	coeffFriction = 0.02;
}


Physics::~Physics()
{
}

float Physics::calKineticEnergy(Entity &movingEntity) {

	float kineticEnergy;

	kineticEnergy = 0.5 * movingEntity.getMass() * (movingEntity.getSpeed() * movingEntity.getSpeed());

	return kineticEnergy;
}

float Physics::calMomentum(Entity &movingEntity) {

	float momentum;

	momentum = movingEntity.getMass() * movingEntity.getSpeed();

	return momentum;
}

float Physics::calFriction(Entity &movingEntity) {

	float friction;

	friction = movingEntity.getMass() * gravity * coeffFriction;

	return friction;

}

float Physics::calFinalKE(Entity &firstEntity, Entity &secondEntity) {

	//car and object collision - inelastic
	if(firstEntity.getAbletoMove() == false || secondEntity.getAbletoMove() == false){
	
		float finalKE;
		finalKE = (calKineticEnergy(firstEntity) + calKineticEnergy(secondEntity)) /100 * 5;
		
		return finalKE;
	}


}