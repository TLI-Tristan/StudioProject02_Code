#ifndef SCENE_GAMEMENU_H
#define SCENE_GAMEMENU_H

#include "Scene.h"
#include "Camera2.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include "MatrixStack.h"



class SceneGameMenu : public Scene
{
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MATERIAL_AMBIENT,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_MATERIAL_DIFFUSE,
		U_LIGHTENABLED,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,


		U_TOTAL,
	};

	enum GEOMETRY_TYPE
	{
		GEO_QUAD,
		GEO_TEXT,
		GEO_AXES,
		NUM_GEOMETRY,
	};

public:
	SceneGameMenu();
	~SceneGameMenu();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:

	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	//void RenderPictureOnScreen(Mesh* mesh, float x, float y);

	Camera2 camera;
	MS modelStack, viewStack, projectionStack;

	void RenderMesh(Mesh *mesh, bool enableLight);

	float f_fps;
	std::string s_fps;

	std::string x;
	std::string y;
	std::string z;

	double delay;
	double dt;

};

#endif
