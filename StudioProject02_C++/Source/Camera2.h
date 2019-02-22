#ifndef CAMERA_2_H
#define CAMERA_2_H

#include "Camera.h"
#include "Entity.h"
#include "Player.h"
#include "Object.h"

class Camera2 : public Camera
{
public:
	//Vector3 position;
	//Vector3 target;
	//Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	Camera2();
	~Camera2();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up, std::string name);
	virtual void Update(double dt, Entity* player01);
	virtual void Reset();
	virtual bool collision(Vector3 pos);

private:
	bool lockCamera;
	std::string name;
};

#endif