#ifndef SCENE_FREEGAMEMODE_H
#define SCENE_FREEGAMEMODE_H

#include "Scene.h"
#include "Camera2.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include "MatrixStack.h"
#include "Light.h"
#include "Audio.h"
#include "TrackMaker.h"
#include "Collision.h"

// splitscreen
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>	

using namespace std;

extern double CRUSOR_X_POS;
extern double CRUSOR_Y_POS;

extern double x2Offset;
extern double y2Offset;

extern bool mouse_pressed;

class SceneFreeGameMode : public Scene
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
		GEO_STRAIGHT,
		GEO_TURNLEFT,
		GEO_TURNLEFT2,
		GEO_TURNRIGHT,
		GEO_TURNRIGHT2,
		GEO_CAR,
		GEO_PLATFORM,
		GEO_TEST,
		NUM_GEOMETRY,
	};

public:
	SceneFreeGameMode();
	~SceneFreeGameMode();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	//void ALLCamera(int angle);

	void ps4Controller(int x);

	int CreateOBJ(int x);

	void LoadMap(vector<string> b);

	void ChoseMapParts();

	void RenderPlayers(int x, int z, int y);

	Collision collisionChecker;

private:
	std::vector<Entity*> entityContainer;

	std::vector<int> allSpawningOBJ;

	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
	void RenderSkybox();
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	//void RenderPictureOnScreen(Mesh* mesh, float x, float y);
	void RenderLight();

	TrackMaker tm;
	Camera2 camera, camera2, camera3;
	MS modelStack, viewStack, projectionStack;
	Light light[2];
	Audio audio;

	vector<string> c;
	bool objPOINTER[10] = { false, };
	int parts;
	bool newplace = false;
	bool can_spawn = false;
	bool spawn_Car = false;

	float turnRight = 0, forwards = 0;

	void RenderMesh(Mesh *mesh, bool enableLight);

	float f_fps;
	std::string s_fps;

	std::string x;
	std::string y;
	std::string z;

	double delay;
	double dt;

	bool paused;
	int onesOnly = 0;

	int choice;
	int arrowY;

};

#endif
