#ifndef SCENE_SP02_H
#define SCENE_SP02_H

#include "Scene.h"
#include "Camera2.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include "MatrixStack.h"
#include "Light.h"
#include <string>
#include <vector>
#include <iostream>
#include "Collision.h"
#include "Entity.h"
#include "Object.h"
#include "Player.h"
#include "Audio.h"

// splitscreen
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <fstream>
#include <vector>
#include <algorithm>




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

		U_LIGHT3_POSITION,
		U_LIGHT3_COLOR,
		U_LIGHT3_POWER,
		U_LIGHT3_KC,
		U_LIGHT3_KL,
		U_LIGHT3_KQ,
		U_LIGHT3_TYPE,
		U_LIGHT3_SPOTDIRECTION,
		U_LIGHT3_COSCUTOFF,
		U_LIGHT3_COSINNER,
		U_LIGHT3_EXPONENT,

		U_LIGHT4_POSITION,
		U_LIGHT4_COLOR,
		U_LIGHT4_POWER,
		U_LIGHT4_KC,
		U_LIGHT4_KL,
		U_LIGHT4_KQ,
		U_LIGHT4_TYPE,
		U_LIGHT4_SPOTDIRECTION,
		U_LIGHT4_COSCUTOFF,
		U_LIGHT4_COSINNER,
		U_LIGHT4_EXPONENT,

		U_LIGHT5_POSITION,
		U_LIGHT5_COLOR,
		U_LIGHT5_POWER,
		U_LIGHT5_KC,
		U_LIGHT5_KL,
		U_LIGHT5_KQ,
		U_LIGHT5_TYPE,
		U_LIGHT5_SPOTDIRECTION,
		U_LIGHT5_COSCUTOFF,
		U_LIGHT5_COSINNER,
		U_LIGHT5_EXPONENT,

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
		GEO_BLOCKFLOAT,
		GEO_OBSTACLEBLOCKS,
		GEO_WORLDFLOOR,
		GEO_WORLDFLOOR3,
		GEO_WORLDFLOOR4,
		GEO_TRAPS,
		GEO_BRIDGE,
		GEO_PLATFORM,

		GEO_GONG,

		GEO_BLOCKS,
		GEO_AXES,
		GEO_NEW2DWORLD,
		GEO_WORLD2FLOOR,
		GEO_WORLD2FLOORPART2,
		GEO_MOVINGBLOCKS1,
		GEO_BRIDGELEFT,
		GEO_BRIDGERIGHT,
		GEO_FALLENTRUNK,
		GEO_GATE,
		GEO_GIANTBLOCK,
		GEO_LEFTCLAMP,
		GEO_RIGHTCLAMP,
		GEO_LEFTMOVINGBLOCK,
		GEO_RIGHTMOVINGBLOCK,
		GEO_SLOWPAD,
		GEO_UPDOWNBLOCKS,
		GEO_FLOATINGBLOCK,
		GEO_STREETLAMP,
		NUM_GEOMETRY,
	};

public:
	SceneSP02();
	~SceneSP02();

	void getLeaderboard();
	void saveLeader();
	void getCar();



	void ALLCamera(int angle);


	Collision collisionChecker;

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void RenderSkybox();
	void RenderGamePlatformPart01();
	void RenderGamePlatformPart02();
	void RenderPart01Objects();
	void RenderPart02Objects();
	void RenderPlayers();
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	//void RenderPictureOnScreen(Mesh* mesh, float x, float y);
	void RenderLight();
	void RenderStreetLamps();
	

private:
	vector<string> carSet;
	string carName;
	string carOBJ;
	string carIM;
	std::vector<Entity*> entityContainer;
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];


	Camera2 camera, camera2, camera3;
	MS modelStack, viewStack, projectionStack;
	Light light[6];
	Audio audio;

	void RenderMesh(Mesh *mesh, bool enableLight);

	float f_fps;
	std::string s_fps;

	std::string x;
	std::string y;
	std::string z;

	double delay;
	double dt;
	bool collisionDetected;
	bool gameFinished;
	bool paused;

	bool checkpoint2;

	float rotateAngle;
	int choice;
	int arrowY;
	bool showStage2;
	bool shown;
	float time;

	vector<int> allTime;
	bool showBoard = false;
	int totalLength;
	// timer code

private:
	int i_milisecs;
	int i_secs;
	int i_mins;
	std::string s_milisecs;
	std::string s_secs;
	std::string s_mins;

	Player * Playercar;
	bool outofmap = false;

	float elaspedtime;
	float bouncetime;
	int flicker = 0;
};

#endif
