#include "Camera2.h"
#include "Application.h"
#include "Mtx44.h"

#include "SceneSP02.h"
Camera2::Camera2()
{

	lockCamera = true;
	stage2Camera = false;
}

Camera2::~Camera2()
{
}



bool Camera2::collision(Vector3 pos) { //camera boundary if needed

	if (pos.x > 498 || pos.x < -498 ||
		pos.y > 148 || pos.y < -148 ||
		pos.z > 298 || pos.z < -298) {

		return false;
	}
	else {
		return true;
	}




}

void Camera2::Init(const Vector3& pos, const Vector3& target, const Vector3& up, std::string name, bool lockCamera)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();
	this->name = name;
	this->lockCamera = lockCamera;
}


void Camera2::Update(double dt, Entity* player01)
{

	if (lockCamera == true && stage2Camera == false) {

		this->target = player01->getPosition();

		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();

		this->position.x = player01->getPosX();
		this->position.y = player01->getPosY() + 80;
		this->position.z = player01->getPosZ() + 100;


	}
	else if (stage2Camera == true && lockCamera == true) {


		this->target = player01->getPosition();

		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();

		this->position.x = player01->getPosX() + 100;
		this->position.y = player01->getPosY() + 20;
		this->position.z = player01->getPosZ();

	}
	else{

	//if(name == "player02") {

		static const float CAMERA_SPEED = 150.f;
		if (Application::IsKeyPressed(VK_LEFT))
		{
			float yaw = (float)(CAMERA_SPEED * dt);
			Mtx44 rotation;
			rotation.SetToRotation(yaw, 0, 1, 0);
			Vector3 view = (target - position).Normalized();

			view = rotation * view;
			target = position + view;
			up = rotation * up;
		}
		if (Application::IsKeyPressed(VK_RIGHT))
		{
			float yaw = (float)(-CAMERA_SPEED * dt);
			Mtx44 rotation;
			rotation.SetToRotation(yaw, 0, 1, 0);
			Vector3 view = (target - position).Normalized();

			//position = rotation * position;
			view = rotation * view;
			target = position + view;
			up = rotation * up;
		}
		if (Application::IsKeyPressed(VK_UP))
		{
			float pitch = (float)(CAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);

			view = rotation * view;
			target = position + view;
		}
		if (Application::IsKeyPressed(VK_DOWN))
		{
			float pitch = (float)(-CAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);

			view = rotation * view;
			target = position + view;
		}

		if (Application::IsKeyPressed('W')) {

			Vector3 view = (target - position).Normalized();
			//if (collision(position + view * (float)(50.f * dt))) {
			position = position + view * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}

		}
		if (Application::IsKeyPressed('A')) {

			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);

			//if (collision(position - right * (float)(50.f * dt))) {
			position = position - right * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}
		}
		if (Application::IsKeyPressed('S')) {

			Vector3 view = (target - position).Normalized();
			//Vector3 right = view.Cross(up);

			//if (collision(position - view * (float)(50.f * dt))) {
			position = position - view * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}

		}
		if (Application::IsKeyPressed('D')) {

			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);

			//if (collision(position + right * (float)(50.f * dt))) {
			position = position + right * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}

		}

	}
}

void Camera2::Update(double dt)
{

		//if(name == "player02") {

		static const float CAMERA_SPEED = 150.f;
		if (Application::IsKeyPressed(VK_LEFT))
		{
			float yaw = (float)(CAMERA_SPEED * dt);
			Mtx44 rotation;
			rotation.SetToRotation(yaw, 0, 1, 0);
			Vector3 view = (target - position).Normalized();

			view = rotation * view;
			target = position + view;
			up = rotation * up;
		}
		if (Application::IsKeyPressed(VK_RIGHT))
		{
			float yaw = (float)(-CAMERA_SPEED * dt);
			Mtx44 rotation;
			rotation.SetToRotation(yaw, 0, 1, 0);
			Vector3 view = (target - position).Normalized();

			//position = rotation * position;
			view = rotation * view;
			target = position + view;
			up = rotation * up;
		}
		if (Application::IsKeyPressed(VK_UP))
		{
			float pitch = (float)(CAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);

			view = rotation * view;
			target = position + view;
		}
		if (Application::IsKeyPressed(VK_DOWN))
		{
			float pitch = (float)(-CAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);

			view = rotation * view;
			target = position + view;
		}

		if (Application::IsKeyPressed('W')) {

			Vector3 view = (target - position).Normalized();
			//if (collision(position + view * (float)(50.f * dt))) {
			position = position + view * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}

		}
		if (Application::IsKeyPressed('A')) {

			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);

			//if (collision(position - right * (float)(50.f * dt))) {
			position = position - right * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}
		}
		if (Application::IsKeyPressed('S')) {

			Vector3 view = (target - position).Normalized();
			//Vector3 right = view.Cross(up);

			//if (collision(position - view * (float)(50.f * dt))) {
			position = position - view * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}

		}
		if (Application::IsKeyPressed('D')) {

			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);

			//if (collision(position + right * (float)(50.f * dt))) {
			position = position + right * (float)(50.f * dt);
			target = position + view * (float)(50.f * dt);
			//}

		}

	
}

void Camera2::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}