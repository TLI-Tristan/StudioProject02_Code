//****************************************//
// file physics.h
//
//
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
	float calMomentum();
	float calKineticEnergy(float mass, float speed);
	float calFriction(float mass);

private:
	float gravity;
	float coeffFriction;
	



};

#endif 