#include "SceneSP02.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "Mtx44.h"
#include "Application.h"
#include "Utility.h"
#include "LoadTGA.h"
#include "Collision.h"

SceneSP02::SceneSP02()
{
}

SceneSP02::~SceneSP02()
{
}

void SceneSP02::Init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	glEnable(GL_CULL_FACE);

	/*camera.Init(Vector3(10, 10, 30), Vector3(0, 0, 0), Vector3(0, 1, 0));*/

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	//Load vertex and fragment shaders

	//m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Blending.fragmentshader");
	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");

	//m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	//m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	//m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	//m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	//m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	//m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");

	//m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	//m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	//m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	//m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	//m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	//m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	//m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	//m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	//m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	//m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	//m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");

	//m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	//m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	//m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	//m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	//m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	//m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
	//m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
	//m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
	//m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
	//m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
	//m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");

	//m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
	//m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
	//m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
	//m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
	//m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");


	//m_parameters[U_LIGHT3_POSITION] = glGetUniformLocation(m_programID, "lights[3].position_cameraspace");
	//m_parameters[U_LIGHT3_COLOR] = glGetUniformLocation(m_programID, "lights[3].color");
	//m_parameters[U_LIGHT3_POWER] = glGetUniformLocation(m_programID, "lights[3].power");
	//m_parameters[U_LIGHT3_KC] = glGetUniformLocation(m_programID, "lights[3].kC");
	//m_parameters[U_LIGHT3_KL] = glGetUniformLocation(m_programID, "lights[3].kL");
	//m_parameters[U_LIGHT3_KQ] = glGetUniformLocation(m_programID, "lights[3].kQ");

	//m_parameters[U_LIGHT3_TYPE] = glGetUniformLocation(m_programID, "lights[3].type");
	//m_parameters[U_LIGHT3_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[3].spotDirection");
	//m_parameters[U_LIGHT3_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[3].cosCutoff");
	//m_parameters[U_LIGHT3_COSINNER] = glGetUniformLocation(m_programID, "lights[3].cosInner");
	//m_parameters[U_LIGHT3_EXPONENT] = glGetUniformLocation(m_programID, "lights[3].exponent");


	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");


	glUseProgram(m_programID);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//light[0].type = Light::LIGHT_POINT;
	//light[0].position.Set(-470, -20, 160);
	//light[0].color.Set(1, 1, 1);
	//light[0].power = 1;
	//light[0].kC = 1.f;
	//light[0].kL = 0.01f;
	//light[0].kQ = 0.001f;
	//light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	//light[0].cosInner = cos(Math::DegreeToRadian(30));
	//light[0].exponent = 3.f;
	//light[0].spotDirection.Set(0.f, 1.f, 0.f);

	//light[1].type = Light::LIGHT_SPOT;
	//light[1].position.Set(2, 144, 0);
	//light[1].color.Set(2, 144, 0);
	//light[1].power = 0;
	//light[1].kC = 1.f;
	//light[1].kL = 0.01f;
	//light[1].kQ = 0.001f;
	//light[1].cosCutoff = cos(Math::DegreeToRadian(45));
	//light[1].cosInner = cos(Math::DegreeToRadian(30));
	//light[1].exponent = 1.f;
	//light[1].spotDirection.Set(0.f, 1.f, 0.f);

	//light[2].type = Light::LIGHT_SPOT;
	//light[2].position.Set(-160, -30, -198);
	//light[2].color.Set(255, 255, 255);
	//light[2].power = 0.5;
	//light[2].kC = 1.f;
	//light[2].kL = 0.01f;
	//light[2].kQ = 0.001f;
	//light[2].cosCutoff = cos(Math::DegreeToRadian(3));
	//light[2].cosInner = cos(Math::DegreeToRadian(1));
	//light[2].exponent = 3.f;
	//light[2].spotDirection.Set(-1.45f, 0.15f, -1.f);


	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);

	glUniform1i(m_parameters[U_LIGHT2_TYPE], light[2].type);
	glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &light[2].color.r);
	glUniform1f(m_parameters[U_LIGHT2_POWER], light[2].power);
	glUniform1f(m_parameters[U_LIGHT2_KC], light[2].kC);
	glUniform1f(m_parameters[U_LIGHT2_KL], light[2].kL);
	glUniform1f(m_parameters[U_LIGHT2_KQ], light[2].kQ);
	glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], light[2].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT2_COSINNER], light[2].cosInner);
	glUniform1f(m_parameters[U_LIGHT2_EXPONENT], light[2].exponent);



	//glUniform1i(m_parameters[U_LIGHT3_TYPE], light[3].type);
	//glUniform3fv(m_parameters[U_LIGHT3_COLOR], 1, &light[3].color.r);
	//glUniform1f(m_parameters[U_LIGHT3_POWER], light[3].power);
	//glUniform1f(m_parameters[U_LIGHT3_KC], light[3].kC);
	//glUniform1f(m_parameters[U_LIGHT3_KL], light[3].kL);
	//glUniform1f(m_parameters[U_LIGHT3_KQ], light[3].kQ);
	//glUniform1f(m_parameters[U_LIGHT3_COSCUTOFF], light[3].cosCutoff);
	//glUniform1f(m_parameters[U_LIGHT3_COSINNER], light[3].cosInner);
	//glUniform1f(m_parameters[U_LIGHT3_EXPONENT], light[3].exponent);

	glUniform1i(m_parameters[U_NUMLIGHTS], 3);

	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID,
		"textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID,
		"textColor");

	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);

	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(255, 255, 255), 1000.f, 600.f, true);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//floor_tile.tga", true);

	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(255, 255, 255), 1000.f, 600.f, false);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//ceiling.tga", false);

	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(255, 255, 255), 600.f, 300.f, false);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//ceiling.tga");

	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(255, 255, 255), 600.f, 300.f, false);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//wall_with_door.tga");

	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(255, 255, 255), 1000.f, 300.f, false);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//wall4.tga", false);

	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(255, 255, 255), 1000.f, 300.f, false);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//wall4.tga", false);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");

	meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("car","Obj/SP_CarObj.obj");
	meshList[GEO_CAR]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Player(Vector3(0, 0, 110), Vector3(0, 0, 0), 5, 5, 6, 1000.0, "player01"));//0



	//entityContainer.push_back(new Object(Vector3(0, 0, -37), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //1
	//entityContainer.push_back(new Object(Vector3(0, 0, -87), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //2


	meshList[GEO_OBSTACLEBLOCKS] = MeshBuilder::GenerateOBJ("Obstacle squares", "Obj/ObstacleBlocks.obj");
	//entityContainer.push_back(new Object(Vector3(0, 15, -62), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //3


	meshList[GEO_WORLDFLOOR] = MeshBuilder::GenerateOBJ("WorldFloor", "Obj/WorldFloor.obj");
	//entityContainer.push_back(new Object(Vector3(0, -5, -60), false, false, 3.5, 3, 80, Vector3(0.0, 0.0, 0.0), 5000.0, "platform")); //4

	meshList[GEO_BLOCKFLOAT] = MeshBuilder::GenerateOBJ("floating obstacle", "Obj/FloatingBlock.obj");

	meshList[GEO_TRAPS] = MeshBuilder::GenerateOBJ("Trap", "Obj/Traps.obj");


///////////////////////////////////////////////////////////////////////////////////////

	meshList[GEO_NEW2DWORLD] = MeshBuilder::GenerateOBJ("WorldFloor", "Obj/new2dworld.obj");
	entityContainer.push_back(new Object(Vector3(0, -4.2, -265), false, false, 3.5, 3, 390, Vector3(0.0, 0.0, 0.0), 5000.0, "platform"));//1

	meshList[GEO_BLOCKS] = MeshBuilder::GenerateOBJ("Blockers", "Obj/Blocks.obj");
	entityContainer.push_back(new Object(Vector3(-10, 0, 50), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //2
	entityContainer.push_back(new Object(Vector3( 10, 0,  0), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //3
	entityContainer.push_back(new Object(Vector3(-10, 0, -50), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //4
	entityContainer.push_back(new Object(Vector3( 10, 0, -100), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //5
	entityContainer.push_back(new Object(Vector3(-10, 0, -150), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //6
	entityContainer.push_back(new Object(Vector3( 10, 0, -200), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //7
	entityContainer.push_back(new Object(Vector3( 10, 0, -250), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //8
	entityContainer.push_back(new Object(Vector3(-10, 0, -300), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //9
	entityContainer.push_back(new Object(Vector3(-10, 0, -350), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //10
	entityContainer.push_back(new Object(Vector3(-10, 0, -400), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //11
	entityContainer.push_back(new Object(Vector3( 10, 0, -450), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //12
	entityContainer.push_back(new Object(Vector3(-10, 0, -500), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //13
	entityContainer.push_back(new Object(Vector3( 10, 0, -550), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //14
	entityContainer.push_back(new Object(Vector3(-10, 0, -600), false, false, 3.5, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block")); //15

	meshList[GEO_WORLD2FLOOR] = MeshBuilder::GenerateOBJ("World2Floor", "Obj/World2_Floor.obj");
	meshList[GEO_WORLD2FLOOR]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-250, -4.2, -805), false, false, 300, 3, 150, Vector3(0.0, 0.0, 0.0), 5000.0, "platform"));//16

	meshList[GEO_MOVINGBLOCKS1] = MeshBuilder::GenerateOBJ("Blockers", "Obj/MovingBlocks.obj");
	meshList[GEO_MOVINGBLOCKS1]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-170, 0, -650), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//17
	entityContainer.push_back(new Object(Vector3(-170, 0, -720), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//18
	entityContainer.push_back(new Object(Vector3(-170, 0, -790), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//19
	entityContainer.push_back(new Object(Vector3(-170, 0, -860), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//20
	entityContainer.push_back(new Object(Vector3(-170, 0, -930), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//21

	meshList[GEO_BRIDGE] = MeshBuilder::GenerateOBJ("Bridge", "Obj/Bridge.obj");
	meshList[GEO_BRIDGE]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-240, 0, -802), false, false, 4, 4, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//22
	meshList[GEO_BRIDGELEFT] = MeshBuilder::GenerateOBJ("Bridge", "Obj/BridgeLeft.obj");
	meshList[GEO_BRIDGELEFT]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-240, 0, -673), false, false, 4, 4, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//23
	meshList[GEO_BRIDGERIGHT] = MeshBuilder::GenerateOBJ("Bridge", "Obj/BridgeRight.obj");
	meshList[GEO_BRIDGERIGHT]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-240, 0, -942), false, false, 4, 4, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//24

	meshList[GEO_UPDOWNBLOCKS] = MeshBuilder::GenerateOBJ("UpDownBlock", "Obj/UPDownBlocks.obj");
	entityContainer.push_back(new Object(Vector3(-233, 0, -710), false, false, 4, 8, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//25
	entityContainer.push_back(new Object(Vector3(-233, 0, -750), false, false, 4, 8, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//26
	entityContainer.push_back(new Object(Vector3(-233, 0, -790), false, false, 4, 8, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//27
	entityContainer.push_back(new Object(Vector3(-233, 0, -830), false, false, 4, 8, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//28
	entityContainer.push_back(new Object(Vector3(-233, 0, -870), false, false, 4, 8, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//29
	entityContainer.push_back(new Object(Vector3(-233, 0, -910), false, false, 4, 8, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//30

	meshList[GEO_LEFTMOVINGBLOCK] = MeshBuilder::GenerateOBJ("Blockers", "Obj/MovingBlocks.obj");
	meshList[GEO_LEFTMOVINGBLOCK]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-280, 0, -650), false, false, 4,5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//31
	entityContainer.push_back(new Object(Vector3(-280, 0, -720), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//32
	entityContainer.push_back(new Object(Vector3(-280, 0, -790), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//33
	entityContainer.push_back(new Object(Vector3(-280, 0, -860), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//34
	entityContainer.push_back(new Object(Vector3(-280, 0, -930), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//35

	meshList[GEO_RIGHTMOVINGBLOCK] = MeshBuilder::GenerateOBJ("Blockers", "Obj/MovingBlocks.obj");
	meshList[GEO_RIGHTMOVINGBLOCK]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-320, 0, -650), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//36
	entityContainer.push_back(new Object(Vector3(-320, 0, -720), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//37
	entityContainer.push_back(new Object(Vector3(-320, 0, -790), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//38
	entityContainer.push_back(new Object(Vector3(-320, 0, -860), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//39
	entityContainer.push_back(new Object(Vector3(-320, 0, -930), false, false, 4, 5, 10, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//40



	/*meshList[GEO_GATE] = MeshBuilder::GenerateOBJ("Gates", "Obj/Gate.obj");*/

	meshList[GEO_GIANTBLOCK] = MeshBuilder::GenerateOBJ("GiantBlock", "Obj/GiantBlock.obj");
	entityContainer.push_back(new Object(Vector3(-495, -3, -683), false, false, 13, 10, 13, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//41
	entityContainer.push_back(new Object(Vector3(-495, -3, -766), false, false, 13, 10, 13, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//42
	entityContainer.push_back(new Object(Vector3(-495, -3, -849), false, false, 13, 10, 13, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//43
	entityContainer.push_back(new Object(Vector3(-495, -3, -933), false, false, 13, 10, 13, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//44


	meshList[GEO_FLOATINGBLOCK] = MeshBuilder::GenerateOBJ("FloatingBlocks", "Obj/FloatingBlock.obj");
	entityContainer.push_back(new Object(Vector3(-555, -3, -889), false, false, 13, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "platform"));//45
	entityContainer.push_back(new Object(Vector3(-555, -3, -805), false, false, 13, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "platform"));//46
	entityContainer.push_back(new Object(Vector3(-555, -3, -721), false, false, 13, 3, 4, Vector3(0.0, 0.0, 0.0), 5000.0, "platform"));//47

	meshList[GEO_WORLD2FLOORPART2] = MeshBuilder::GenerateOBJ("stage2floor", "Obj/World2_FloorPart2.obj");
    entityContainer.push_back(new Object(Vector3(-1000, -4.2, -805), false, false, 500, 3, 150, Vector3(0.0, 0.0, 0.0), 5000.0, "platform"));//48

	//meshList[GEO_LEFTMOVINGBLOCK] = MeshBuilder::GenerateOBJ("Blockers", "Obj/MovingBlocks.obj");

	entityContainer.push_back(new Object(Vector3(-650, 0, -650), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//49
	entityContainer.push_back(new Object(Vector3(-650, 0, -720), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//50
	entityContainer.push_back(new Object(Vector3(-650, 0, -790), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//51
	entityContainer.push_back(new Object(Vector3(-650, 0, -860), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//52
	entityContainer.push_back(new Object(Vector3(-650, 0, -930), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//53
	//right
	entityContainer.push_back(new Object(Vector3(-690, 0, -660), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//54
	entityContainer.push_back(new Object(Vector3(-690, 0, -730), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//55
	entityContainer.push_back(new Object(Vector3(-690, 0, -800), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//56
	entityContainer.push_back(new Object(Vector3(-690, 0, -870), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//57
	entityContainer.push_back(new Object(Vector3(-690, 0, -940), false, false, 4, 5, 5, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//58

	meshList[GEO_LEFTCLAMP] = MeshBuilder::GenerateOBJ("LeftClamp", "Obj/LeftClamp.obj");
	entityContainer.push_back(new Object(Vector3(-1200, 30, -650), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//59
	meshList[GEO_RIGHTCLAMP] = MeshBuilder::GenerateOBJ("RightClamp", "Obj/RightClamp.obj");
	entityContainer.push_back(new Object(Vector3(-1200, 30, -960), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//60

	meshList[GEO_FALLENTRUNK] = MeshBuilder::GenerateOBJ("FallenTrunk", "Obj/FallenTrunk.obj");
	meshList[GEO_FALLENTRUNK]->textureID = LoadTGA("Image//car.tga");
	entityContainer.push_back(new Object(Vector3(-980, 0, -660), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//61
	entityContainer.push_back(new Object(Vector3(-975, 0, -700), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//62
	entityContainer.push_back(new Object(Vector3(-970, 0, -800), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//63
	entityContainer.push_back(new Object(Vector3(-990, 0, -860), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//64
	entityContainer.push_back(new Object(Vector3(-1000, 0, -920), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//65
	entityContainer.push_back(new Object(Vector3(-980, 0, -760), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//66
	entityContainer.push_back(new Object(Vector3(-1050, 0, -800), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//67
	entityContainer.push_back(new Object(Vector3(-1020, 0, -670), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//68
	entityContainer.push_back(new Object(Vector3(-1040, 0, -880), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//69
	entityContainer.push_back(new Object(Vector3(-1030, 0, -720), false, false, 5, 25, 7, Vector3(0.0, 0.0, 0.0), 5000.0, "block"));//70



	meshList[GEO_SLOWPAD] = MeshBuilder::GenerateOBJ("SlowPad", "Obj/SlowPad.obj");




	f_fps = 0;

	x = "/0";
	y = "/0";
	z = "/0";
	collisionDetected = false;
	delay = 0.0;
}

void SceneSP02::Update(double dt)
{
	this->dt = dt;
	static const float LSPEED = 10.0f;

	//if (Application::IsKeyPressed('1'))
	//{
	//	glEnable(GL_CULL_FACE);
	//}
	//if (Application::IsKeyPressed('2'))
	//{
	//	glDisable(GL_CULL_FACE);
	//}
	//if (Application::IsKeyPressed('3'))
	//{
	//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//}
	//if (Application::IsKeyPressed('4'))
	//{
	//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//}

	if (Application::IsKeyPressed('I') && delay >= 0.2) {	//interacts

		delay = 0;

	}

	//if (Application::IsKeyPressed('Q')) {	//turn on torch

	//	light[3].power = 0.2;
	//	glUniform1f(m_parameters[U_LIGHT3_POWER], light[3].power);

	//	torchLightOn = true;
	//}

	//if (Application::IsKeyPressed('E')) {	//turn off torch

	//	light[3].power = 0;
	//	glUniform1f(m_parameters[U_LIGHT3_POWER], light[3].power);

	//	torchLightOn = false;
	//}

	f_fps = 1.0f / dt;

	delay += dt;

	s_fps = std::to_string(f_fps);
	x = std::to_string(camera.position.x);
	y = std::to_string(camera.position.y);
	z = std::to_string(camera.position.z);

	//if (torchLightOn == true) {	// torch direction and position change here

	//	Vector3 view = (camera.target - camera.position).Normalized();

	//	light[3].position.Set(camera.position.x, camera.position.y, camera.position.z);	//position changes
	//	light[3].spotDirection.Set(-view.x, -view.y, -view.z);

	//}

	for (size_t i = 0; i < entityContainer.size(); i++) {

		entityContainer.at(i)->collisionDetector(collisionChecker.collisionCheck(*entityContainer.at(i), entityContainer), collisionChecker.getIsItCollidingWithFloor(), collisionChecker.getCollidiedItem());
		entityContainer.at(i)->update(dt);

	}

	collisionDetected = collisionChecker.collisionCheck(entityContainer);

	camera.Update(dt, entityContainer.at(0));

}

void SceneSP02::RenderMesh(Mesh* mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);


	if (enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if (mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}

	mesh->Render();

	if (mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}

void SceneSP02::RenderSkybox() {

	modelStack.PushMatrix();
	modelStack.Translate(0, 148, 0);
	modelStack.Rotate(90, 1, 0, 0);
	RenderMesh(meshList[GEO_TOP], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, -148, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	RenderMesh(meshList[GEO_BOTTOM], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, -298);
	RenderMesh(meshList[GEO_RIGHT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 298);
	modelStack.Rotate(180, 0, 1, 0);
	RenderMesh(meshList[GEO_LEFT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-498, 0, 0);
	modelStack.Rotate(90, 0, 1, 0);
	RenderMesh(meshList[GEO_FRONT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(498, 0, 0);
	modelStack.Rotate(-90, 0, 1, 0);
	RenderMesh(meshList[GEO_BACK], true);
	modelStack.PopMatrix();


}

void SceneSP02::RenderGamePlatformPart01() {


	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(1)->getPosX(), entityContainer.at(1)->getPosY(), entityContainer.at(1)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_NEW2DWORLD], false);
	modelStack.PopMatrix();


	/*modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLDFLOOR2], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKFLOAT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLDFLOOR3], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLDFLOOR4], true);
	modelStack.PopMatrix();
*/


}

void SceneSP02::RenderGamePlatformPart02() {


	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(16)->getPosX(), entityContainer.at(16)->getPosY(), entityContainer.at(16)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLD2FLOOR], true);
	modelStack.PopMatrix();

}

void SceneSP02::RenderPart01Objects() {

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(2)->getPosX(), entityContainer.at(2)->getPosY(), entityContainer.at(2)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(3)->getPosX(), entityContainer.at(2)->getPosY(), entityContainer.at(3)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(4)->getPosX(), entityContainer.at(4)->getPosY(), entityContainer.at(4)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(5)->getPosX(), entityContainer.at(5)->getPosY(), entityContainer.at(5)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(6)->getPosX(), entityContainer.at(6)->getPosY(), entityContainer.at(6)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(7)->getPosX(), entityContainer.at(7)->getPosY(), entityContainer.at(7)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(8)->getPosX(), entityContainer.at(8)->getPosY(), entityContainer.at(8)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(9)->getPosX(), entityContainer.at(9)->getPosY(), entityContainer.at(9)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(10)->getPosX(), entityContainer.at(10)->getPosY(), entityContainer.at(10)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(11)->getPosX(), entityContainer.at(11)->getPosY(), entityContainer.at(11)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(12)->getPosX(), entityContainer.at(12)->getPosY(), entityContainer.at(12)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(13)->getPosX(), entityContainer.at(13)->getPosY(), entityContainer.at(13)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(14)->getPosX(), entityContainer.at(14)->getPosY(), entityContainer.at(14)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(15)->getPosX(), entityContainer.at(15)->getPosY(), entityContainer.at(15)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();



	//modelStack.PushMatrix();
	//modelStack.Translate(entityContainer.at(2)->getPosX(), entityContainer.at(2)->getPosY(), entityContainer.at(2)->getPosZ());
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_BLOCKS], true);
	//modelStack.PopMatrix();

	//*modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 0);
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_BLOCKS], true);
	//modelStack.PopMatrix(); */

	//modelStack.PushMatrix();
	//modelStack.Translate(entityContainer.at(3)->getPosX(), entityContainer.at(3)->getPosY(), entityContainer.at(3)->getPosZ());
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_OBSTACLEBLOCKS], true);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(entityContainer.at(5)->getPosX(), entityContainer.at(5)->getPosY(), entityContainer.at(5)->getPosZ());
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(entityContainer.at(6)->getPosX(), entityContainer.at(6)->getPosY(), entityContainer.at(6)->getPosZ());
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(entityContainer.at(7)->getPosX(), entityContainer.at(7)->getPosY(), entityContainer.at(7)->getPosZ());
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(entityContainer.at(8)->getPosX(), entityContainer.at(8)->getPosY(), entityContainer.at(8)->getPosZ());
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 0);
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_TRAPS], true);
	//modelStack.PopMatrix();


	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 0);
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_BRIDGE], true);
	//modelStack.PopMatrix();



}

void SceneSP02::RenderPart02Objects() {


	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(17)->getPosX(), entityContainer.at(17)->getPosY(), entityContainer.at(17)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_MOVINGBLOCKS1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(18)->getPosX(), entityContainer.at(18)->getPosY(), entityContainer.at(18)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_MOVINGBLOCKS1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(19)->getPosX(), entityContainer.at(19)->getPosY(), entityContainer.at(19)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_MOVINGBLOCKS1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(20)->getPosX(), entityContainer.at(20)->getPosY(), entityContainer.at(20)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_MOVINGBLOCKS1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(21)->getPosX(), entityContainer.at(21)->getPosY(), entityContainer.at(21)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_MOVINGBLOCKS1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(22)->getPosX(), entityContainer.at(22)->getPosY(), entityContainer.at(22)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BRIDGE], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(23)->getPosX(), entityContainer.at(23)->getPosY(), entityContainer.at(23)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BRIDGELEFT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(24)->getPosX(), entityContainer.at(24)->getPosY(), entityContainer.at(24)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BRIDGERIGHT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(25)->getPosX(), entityContainer.at(25)->getPosY(), entityContainer.at(25)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(26)->getPosX(), entityContainer.at(26)->getPosY(), entityContainer.at(26)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(27)->getPosX(), entityContainer.at(27)->getPosY(), entityContainer.at(27)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(28)->getPosX(), entityContainer.at(28)->getPosY(), entityContainer.at(28)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(29)->getPosX(), entityContainer.at(29)->getPosY(), entityContainer.at(29)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(30)->getPosX(), entityContainer.at(30)->getPosY(), entityContainer.at(30)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(31)->getPosX(), entityContainer.at(31)->getPosY(), entityContainer.at(31)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(32)->getPosX(), entityContainer.at(32)->getPosY(), entityContainer.at(32)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(33)->getPosX(), entityContainer.at(33)->getPosY(), entityContainer.at(33)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(34)->getPosX(), entityContainer.at(34)->getPosY(), entityContainer.at(34)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(35)->getPosX(), entityContainer.at(35)->getPosY(), entityContainer.at(35)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(36)->getPosX(), entityContainer.at(36)->getPosY(), entityContainer.at(36)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(37)->getPosX(), entityContainer.at(37)->getPosY(), entityContainer.at(37)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(38)->getPosX(), entityContainer.at(38)->getPosY(), entityContainer.at(38)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(39)->getPosX(), entityContainer.at(39)->getPosY(), entityContainer.at(39)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(40)->getPosX(), entityContainer.at(40)->getPosY(), entityContainer.at(40)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(41)->getPosX(), entityContainer.at(41)->getPosY(), entityContainer.at(41)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_GIANTBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(42)->getPosX(), entityContainer.at(42)->getPosY(), entityContainer.at(42)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_GIANTBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(43)->getPosX(), entityContainer.at(43)->getPosY(), entityContainer.at(43)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_GIANTBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(44)->getPosX(), entityContainer.at(44)->getPosY(), entityContainer.at(44)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_GIANTBLOCK], true);
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(45)->getPosX(), entityContainer.at(45)->getPosY(), entityContainer.at(45)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(46)->getPosX(), entityContainer.at(46)->getPosY(), entityContainer.at(46)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(47)->getPosX(), entityContainer.at(47)->getPosY(), entityContainer.at(47)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(48)->getPosX(), entityContainer.at(48)->getPosY(), entityContainer.at(48)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLD2FLOORPART2], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(49)->getPosX(), entityContainer.at(49)->getPosY(), entityContainer.at(49)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(50)->getPosX(), entityContainer.at(50)->getPosY(), entityContainer.at(50)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(51)->getPosX(), entityContainer.at(51)->getPosY(), entityContainer.at(51)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(52)->getPosX(), entityContainer.at(52)->getPosY(), entityContainer.at(52)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(53)->getPosX(), entityContainer.at(53)->getPosY(), entityContainer.at(53)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(54)->getPosX(), entityContainer.at(54)->getPosY(), entityContainer.at(54)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(55)->getPosX(), entityContainer.at(55)->getPosY(), entityContainer.at(55)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(56)->getPosX(), entityContainer.at(56)->getPosY(), entityContainer.at(56)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(57)->getPosX(), entityContainer.at(57)->getPosY(), entityContainer.at(57)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(58)->getPosX(), entityContainer.at(58)->getPosY(), entityContainer.at(58)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();



	/*modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();*/

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 0);
	//modelStack.Scale(10, 10, 10);
	//RenderMesh(meshList[GEO_GATE], true);
	//modelStack.PopMatrix();



	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(59)->getPosX(), entityContainer.at(59)->getPosY(), entityContainer.at(59)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTCLAMP], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(60)->getPosX(), entityContainer.at(60)->getPosY(), entityContainer.at(60)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTCLAMP], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(61)->getPosX(), entityContainer.at(61)->getPosY(), entityContainer.at(61)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(62)->getPosX(), entityContainer.at(62)->getPosY(), entityContainer.at(62)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(63)->getPosX(), entityContainer.at(63)->getPosY(), entityContainer.at(63)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(64)->getPosX(), entityContainer.at(64)->getPosY(), entityContainer.at(64)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(65)->getPosX(), entityContainer.at(65)->getPosY(), entityContainer.at(65)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(66)->getPosX(), entityContainer.at(66)->getPosY(), entityContainer.at(66)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(67)->getPosX(), entityContainer.at(67)->getPosY(), entityContainer.at(67)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();
	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(68)->getPosX(), entityContainer.at(68)->getPosY(), entityContainer.at(68)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(69)->getPosX(), entityContainer.at(69)->getPosY(), entityContainer.at(69)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();
	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(70)->getPosX(), entityContainer.at(70)->getPosY(), entityContainer.at(70)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();



	/*modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();*/

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_SLOWPAD], true);
	modelStack.PopMatrix();




}


void SceneSP02::RenderPlayers()
{
	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(0)->getPosX(), entityContainer.at(0)->getPosY(), entityContainer.at(0)->getPosZ());
	//modelStack.Rotate(carrot, 0, 1, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_CAR], true);
	modelStack.PopMatrix();

}

void SceneSP02::RenderText(Mesh* mesh, std::string text, Color color)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() *
			characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}

void SceneSP02::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() *
			characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);

	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);

}

//void SceneAssignment02::RenderPictureOnScreen(Mesh* mesh, float x, float y)
//{
//	if (!mesh || mesh->textureID <= 0) //Proper error check
//		return;
//
//	Mtx44 ortho;
//	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
//	projectionStack.PushMatrix();
//	projectionStack.LoadMatrix(ortho);
//	viewStack.PushMatrix();
//	viewStack.LoadIdentity(); //No need camera for ortho mode
//	modelStack.PushMatrix();
//	modelStack.LoadIdentity(); //Reset modelStack
//	modelStack.Translate(x, y, 0);
//
//	Mtx44 MVP, modelView, modelView_inverse_transpose;
//
//	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
//	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//
//
//	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//
//
//	if (mesh->textureID > 0)
//	{
//		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	}
//	else
//	{
//		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
//	}
//
//	mesh->Render();
//
//
//
//	projectionStack.PopMatrix();
//	viewStack.PopMatrix();
//	modelStack.PopMatrix();
//
//	if (mesh->textureID > 0)
//	{
//		glBindTexture(GL_TEXTURE_2D, 0);
//	}
//
//}

//void SceneAssignment02::RenderLight() {
//
//
//	if (light[0].type == Light::LIGHT_POINT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//	if (light[1].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//
//	if (light[2].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[2].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//
//
//	if (light[3].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[3].position;
//		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[3].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT3_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//
//}

void SceneSP02::Render()
{
	//Clear color & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	modelStack.LoadIdentity();

	/*modelStack.PushMatrix();
	RenderLight();
	modelStack.PopMatrix();*/

	RenderMesh(meshList[GEO_AXES], false); //To be removed

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	//RenderSkybox();
	RenderPlayers();
	RenderGamePlatformPart01();
    RenderGamePlatformPart02();
	RenderPart01Objects();
	RenderPart02Objects();




	// for testing purposes
	/*modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(1)->getPosX(), entityContainer.at(1)->getPosY(), entityContainer.at(1)->getPosZ());
	modelStack.Scale(5, 5, 5);
	RenderMesh(meshList[GEO_GONG], true);
	modelStack.PopMatrix();
*/
	/*modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(2)->getPosX(), entityContainer.at(2)->getPosY(), entityContainer.at(2)->getPosZ());
	modelStack.Scale(20, 20, 20);
	RenderMesh(meshList[GEO_PLATFORM], true);
	modelStack.PopMatrix();*/

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(3)->getPosX(), entityContainer.at(3)->getPosY(), entityContainer.at(3)->getPosZ());
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_CUBE], true);
	modelStack.PopMatrix();

	if (collisionDetected == false) {
		RenderTextOnScreen(meshList[GEO_TEXT], "Collision not detected", Color(220, 20, 60), 2, 1,15);
	}
	else {
		RenderTextOnScreen(meshList[GEO_TEXT], "Collision DETECTED", Color(220, 20, 60), 2, 1, 20);
	}

	RenderTextOnScreen(meshList[GEO_TEXT], "DT: ", Color(220, 20, 60), 2, 1, 11);
	std::string delta = std::to_string(dt);
	RenderTextOnScreen(meshList[GEO_TEXT], delta, Color(220, 20, 60), 2, 5, 11);

	RenderTextOnScreen(meshList[GEO_TEXT], "X0: ", Color(220, 20, 60), 2, 1, 10);
	std::string test = std::to_string(entityContainer.at(0)->getHeighestX());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 10);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y0: ", Color(220, 20, 60), 2, 1, 9);
	test = std::to_string(entityContainer.at(0)->getHeighestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 9);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z0: ", Color(220, 20, 60), 2, 1, 8);
	test = std::to_string(entityContainer.at(0)->getHeighestZ());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 8);

	RenderTextOnScreen(meshList[GEO_TEXT], "X1: ", Color(220, 20, 60), 2, 1, 7);
	test = std::to_string(entityContainer.at(3)->getHeighestX());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 7);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y1: ", Color(220, 20, 60), 2, 1, 6);
	test = std::to_string(entityContainer.at(3)->getHeighestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 6);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z1: ", Color(220, 20, 60), 2, 1, 5);
	test = std::to_string(entityContainer.at(3)->getHeighestZ());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 5);
	//////////////////////////////////////

	//RenderTextOnScreen(meshList[GEO_TEXT], "SP: ", Color(220, 20, 60), 2, 16, 10);
	//test = std::to_string(entityContainer.at(0)->getSpeed());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 10);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y0: ", Color(220, 20, 60), 2, 16, 9);
	test = std::to_string(entityContainer.at(0)->getLowestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 9);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z0: ", Color(220, 20, 60), 2, 16, 8);
	test = std::to_string(entityContainer.at(0)->getLowestZ());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 8);

	RenderTextOnScreen(meshList[GEO_TEXT], "X1: ", Color(220, 20, 60), 2, 16, 7);
	test = std::to_string(entityContainer.at(3)->getLowestX());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 7);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y1: ", Color(220, 20, 60), 2, 16, 6);
	test = std::to_string(entityContainer.at(3)->getLowestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 6);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z1: ", Color(220, 20, 60), 2, 16, 5);
	test = std::to_string(entityContainer.at(3)->getLowestZ());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 5);


	////////////////////////////////////////
	RenderTextOnScreen(meshList[GEO_TEXT], "X:", Color(220, 20, 60), 2, 1, 4);
	RenderTextOnScreen(meshList[GEO_TEXT], x, Color(220, 20, 60), 2, 3, 4);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y:", Color(220, 20, 60), 2, 1, 3);
	RenderTextOnScreen(meshList[GEO_TEXT], y, Color(220, 20, 60), 2, 3, 3);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z:", Color(220, 20, 60), 2, 1, 2);
	RenderTextOnScreen(meshList[GEO_TEXT], z, Color(220, 20, 60), 2, 3, 2);

	RenderTextOnScreen(meshList[GEO_TEXT], s_fps, Color(0, 255, 0), 2, 5, 1);
	RenderTextOnScreen(meshList[GEO_TEXT], "FPS: ", Color(0, 255, 0), 2, 1, 1);

}

void SceneSP02::Exit()
{
	// Cleanup VBO here
	glDeleteProgram(m_programID);

}
