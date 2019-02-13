#ifndef SCENE_SP02_H
#define SCENE_SP02_H

#include "Scene.h"
#include "Camera2.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include "MatrixStack.h"
#include "Light.h"
#include <string>

class SceneSP02 : public Scene
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

		U_LIGHT2_POSITION,
		U_LIGHT2_COLOR,
		U_LIGHT2_POWER,
		U_LIGHT2_KC,
		U_LIGHT2_KL,
		U_LIGHT2_KQ,
		U_LIGHT2_TYPE,
		U_LIGHT2_SPOTDIRECTION,
		U_LIGHT2_COSCUTOFF,
		U_LIGHT2_COSINNER,
		U_LIGHT2_EXPONENT,

		//U_LIGHT3_POSITION,
		//U_LIGHT3_COLOR,
		//U_LIGHT3_POWER,
		//U_LIGHT3_KC,
		//U_LIGHT3_KL,
		//U_LIGHT3_KQ,
		//U_LIGHT3_TYPE,
		//U_LIGHT3_SPOTDIRECTION,
		//U_LIGHT3_COSCUTOFF,
		//U_LIGHT3_COSINNER,
		//U_LIGHT3_EXPONENT,

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
		GEO_CAR,
		GEO_OBSTACLEFALL,
		GEO_OBSTACLEBLOCKS,
		GEO_WORLDFLOOR,
		GEO_TRAPS,
		GEO_BRIDGE,
		GEO_BLOCKS,
		GEO_WORLD2FLOOR,
		GEO_MOVINGBLOCKS,
		NUM_GEOMETRY,
	};

public:
	SceneSP02();
	~SceneSP02();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	float carspeed;
	double carposz = 0;
	double carposy = 0;
	double carposx = 0;
	float jumpheight;
	float carjumptime;
	bool stage2 = false;
	int carrot = 0;
	int rotatespeed = 5;
private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	void RenderSkybox();
	void RenderGameScene();
	void RenderPlayers();
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	//void RenderPictureOnScreen(Mesh* mesh, float x, float y);
	//void RenderLight();


	Camera2 camera;
	MS modelStack, viewStack, projectionStack;
	Light light[3];

	void RenderMesh(Mesh *mesh, bool enableLight);

	float f_fps;
	std::string s_fps;

	std::string x;
	std::string y;
	std::string z;

	double delay;
	

};

#endif