#ifndef SCENE_CUSTOMIZATIONMENU_H
#define SCENE_CUSTOMIZATIONMENU_H

#include "Scene.h"
#include "Camera2.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include "MatrixStack.h"
#include "Light.h"
#include "Audio.h"

// splitscreen
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// audio


class SceneCustomizationMenu : public Scene
{
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,

		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,

		U_TEXT_ENABLED,
		U_TEXT_COLOR,

		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,
		U_LIGHTENABLED,
		U_NUMLIGHTS,
		U_TOTAL,
	};

	enum GEOMETRY_TYPE
	{
		GEO_QUAD,
		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,
		GEO_TEXT,
		GEO_AXES,
		GEO_PLAYER,
		NUM_GEOMETRY,
	};

	enum carParts
	{
		TEXTURE,
		CHASSIS,
		WHEEL,
		ENGINE,
		SAVE,
		RETURN
	};

public:
	SceneCustomizationMenu();
	~SceneCustomizationMenu();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:

	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	void RenderSkybox();
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	//void RenderPictureOnScreen(Mesh* mesh, float x, float y);
	void RenderLight();

	Camera2 camera;
	MS modelStack, viewStack, projectionStack;
	Light light[2];
	Audio audio;

	void RenderMesh(Mesh *mesh, bool enableLight);
	int customization[4];

	float f_fps;
	std::string s_fps;

	std::string x;
	std::string y;
	std::string z;

	double delay;
	double dt;

	int choice;
	int arrowY;
	int arrowX;
	float Rotatecar;
	bool changeTexture;
	bool changeModel;
	bool changeTyre;
	bool changeEngine;


};

#endif
