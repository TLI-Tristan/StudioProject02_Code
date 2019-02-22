#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	Scene() {}
	~Scene() {}

	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render(int) = 0;
	virtual void Exit() = 0;
};

#endif