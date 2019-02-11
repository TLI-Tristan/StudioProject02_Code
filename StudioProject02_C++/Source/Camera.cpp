#include "Camera.h"
#include "Application.h"
/******************************************************************************/
/*!
\brief
Default constructor
*/
/******************************************************************************/
Camera::Camera()
{
	Reset();
}

/******************************************************************************/
/*!
\brief
Destructor
*/
/******************************************************************************/
Camera::~Camera()
{
}

/******************************************************************************/
/*!
\brief
Initialize camera

\param pos - position of camera
\param target - where the camera is looking at
\param up - up vector of camera
*/
/******************************************************************************/
void Camera::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = pos;
	this->target = target;
	this->up = up;
}

/******************************************************************************/
/*!
\brief
Reset the camera settings
*/
/******************************************************************************/
void Camera::Reset()
{
	position.Set(1, 0, 0);
	target.Set(0, 0, 0);
	up.Set(0, 1, 0);
}

/******************************************************************************/
/*!
\brief
To be called every frame. Camera will get user inputs and update its position and orientation

\param dt - frame time
*/
/******************************************************************************/
void Camera::Update(double dt)
{
	if(Application::IsKeyPressed(VK_UP))
		position.y += 100.f * dt;
	if(Application::IsKeyPressed(VK_DOWN))
		position.y -= 100.f * dt;
	if(Application::IsKeyPressed(VK_LEFT))
		position.z += 100.f * dt;
	if(Application::IsKeyPressed(VK_RIGHT))
		position.z -= 100.f * dt;
	if (Application::IsKeyPressed('C'))
		position.x += 100.f * dt;
	if (Application::IsKeyPressed('V'))
		position.x -= 100.f * dt;

	if (Application::IsKeyPressed('Z')) {
		position.x += 100.f * dt;
		position.y += 100.f * dt;
		position.z += 100.f * dt;
	}
	if (Application::IsKeyPressed('X')) {
		position.x -= 100.f * dt;
		position.y -= 100.f * dt;
		position.z -= 100.f * dt;

	}
		

}