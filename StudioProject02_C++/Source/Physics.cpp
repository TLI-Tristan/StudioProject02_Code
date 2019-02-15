#include "Physics.h"
#include <math.h>


Physics::Physics()
{
	gravity = 9.8;
	coeffFriction = 0.3;
}


Physics::~Physics()
{
}

void Physics::setCoeffFriction(float cof)
{
	coeffFriction = cof;
}

float Physics::calKineticEnergy(float mass, float speed) {

	float kineticEnergy;

	kineticEnergy = 0.5 * mass * (speed * speed);

	return kineticEnergy;
}

//float Physics::calMomentum() {
//
//	float momentum;
//
//	momentum = movingEntity.getMass() * movingEntity.getSpeed();
//
//	return momentum;
//}

float Physics::calFriction(float mass) {

	float friction;

	friction = mass * gravity * coeffFriction;

	return friction;

}

float Physics::calFinalKE(float mass, float speed) {

	//car and object collision - inelastic

	//TODO CHANGE LOGIC
	
		float finalKE;
		finalKE = calKineticEnergy(mass, speed) /100 * 5;
		
		return finalKE;


}

float Physics::calFinalSpeed(float mass, float speed)
{
	float finalSpeed;
	
	finalSpeed = sqrt(calFinalKE(mass, speed) * 2 * mass);

	return finalSpeed;
}

