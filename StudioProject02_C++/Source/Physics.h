//****************************************//
// file: physics.h
// by: HuiFeng(Tristan) 
//
// this is used to calculate mainly the gravity and impulse on collision
// if any question just ask me.
// let me know if you change anyting here too
//
//****************************************//
#ifndef PHYSICS_H
#define PHYSICS_H

class Physics {
public:
	Physics();
	~Physics();
	void setCoeffFriction(float cof);
	float calFinalKE(float mass, float speed);
	float calFinalSpeed(float mass, float speed);
	float calWeight(float mass);
	float calKineticEnergy(float mass, float speed);
	float calFriction(float mass);

private:
	float gravity;
	float coeffFriction;
	



};

#endif 