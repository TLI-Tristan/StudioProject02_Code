#include "SceneSP02.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "Mtx44.h"
#include "Application.h"
#include "Utility.h"
#include "LoadTGA.h"
#include "Entity.h"
#include "Object.h"
#include "Player.h"
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
	carrot = 0;

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

	meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("car", "Obj/SP_CarObj.obj");
	meshList[GEO_CAR]->textureID = LoadTGA("Image//car.tga");

	entityContainer.push_back(new Player(Vector3(0, 0, 10), Vector3(0, 0, -1), 5, 5, 6, true, 1000.0, "player01"));


	meshList[GEO_OBSTACLEFALL] = MeshBuilder::GenerateOBJ("falling obstacle", "Obj/ObstacleFall.obj");

	meshList[GEO_OBSTACLEBLOCKS] = MeshBuilder::GenerateOBJ("Obstacle squares", "Obj/ObstacleBlocks.obj");

	meshList[GEO_WORLDFLOOR] = MeshBuilder::GenerateOBJ("WorldFloor", "Obj/WorldFloor.obj");

	meshList[GEO_WORLDFLOOR2] = MeshBuilder::GenerateOBJ("WorldFloor", "Obj/WorldFloorPart2.obj");
	meshList[GEO_WORLDFLOOR3] = MeshBuilder::GenerateOBJ("WorldFloor", "Obj/WorldFloorPart3.obj");
	meshList[GEO_WORLDFLOOR4] = MeshBuilder::GenerateOBJ("WorldFloor", "Obj/WorldFloorPart4.obj");


	meshList[GEO_TRAPS] = MeshBuilder::GenerateOBJ("Trap", "Obj/Traps.obj");

	meshList[GEO_BRIDGE] = MeshBuilder::GenerateOBJ("Bridge", "Obj/Bridge.obj");

	meshList[GEO_BLOCKS] = MeshBuilder::GenerateOBJ("Blockers", "Obj/Blocks.obj");

	meshList[GEO_MOVINGBLOCKS] = MeshBuilder::GenerateOBJ("Blockers", "Obj/MovingBlocks.obj");

	meshList[GEO_WORLD2FLOOR] = MeshBuilder::GenerateOBJ("World2Floor", "Obj/World2_Floor.obj");
	//////////////////////////////////////////////////////////////////////////////////////

	meshList[GEO_FALLENTRUNK] = MeshBuilder::GenerateOBJ("FallenTrunk", "Obj/FallenTrunk.obj");

	meshList[GEO_GATE] = MeshBuilder::GenerateOBJ("Gates", "Obj/Gate.obj");

	meshList[GEO_GIANTBLOCK] = MeshBuilder::GenerateOBJ("GiantBlock", "Obj/GiantBlock.obj");


	meshList[GEO_LEFTCLAMP] = MeshBuilder::GenerateOBJ("LeftClamp", "Obj/LeftClamp.obj");

	meshList[GEO_RIGHTCLAMP] = MeshBuilder::GenerateOBJ("RightClamp", "Obj/RIghtClamp.obj");
	meshList[GEO_LEFTMOVINGBLOCK] = MeshBuilder::GenerateOBJ("LeftMovingBlock", "Obj/LeftMovingBlock.obj");

	meshList[GEO_RIGHTMOVINGBLOCK] = MeshBuilder::GenerateOBJ("RightMovingBlock", "Obj/RightMovingBlock.obj");

	meshList[GEO_SLOWPAD] = MeshBuilder::GenerateOBJ("SlowPad", "Obj/SlowPad.obj");

	meshList[GEO_UPDOWNBLOCKS] = MeshBuilder::GenerateOBJ("UpDownBlock", "Obj/UPDownBlocks.obj");

	meshList[GEO_FLOATINGBLOCK] = MeshBuilder::GenerateOBJ("FloatingBlocks", "Obj/FloatingBlock.obj");

	


	/*meshList[GEO_GONG] = MeshBuilder::GenerateOBJ("Gong", "Obj/gong.obj");*/
	//meshList[GEO_GONG]->textureID = LoadTGA("Image//gong.tga",false);

	entityContainer.push_back(new Object(Vector3(0, 0, -15), false, false, 3.5, 17, 12, true, 0.0, 5000.0, "gong"));

	f_fps = 0;

	x = "/0";
	y = "/0";
	z = "/0";
	translateX = 0.0;
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

	//camera.position.y = carposy + 20;
	//camera.position.z = carposz +20;
	//camera.position.x = carposx + 70;

	/*camera.target.y = carposy;
	camera.target.z = carposz;
	camera.target.x = carposx;*/

	camera.position.y = entityContainer.at(0)->getPosY() + 20;
	camera.position.z = entityContainer.at(0)->getPosZ() + 20;
	camera.position.x = entityContainer.at(0)->getPosX() + 70;

	camera.target.y = entityContainer.at(0)->getPosY();
	camera.target.z = entityContainer.at(0)->getPosZ();
	camera.target.x = entityContainer.at(0)->getPosX();

	/*entityContainer.at(0)->getPosX(), entityContainer.at(0)->getPosY(), entityContainer.at(0)->getPosZ()*/

	carspeed = 1.f;
	jumpheight = 2;
	carjumptime = 2;


	for (size_t i = 0; i < entityContainer.size(); i++) {
		//entityContainer.at(i)->
		entityContainer.at(i)->update(dt);
	}

	collisionDetected = collisionChecker.collisionCheck(entityContainer);


	//if ((Application::IsKeyPressed('Q')) && stage2 == false )
	//{
	//	carposz -= carspeed;
	//}

	//if ((Application::IsKeyPressed('E')) && stage2 == false)
	//{
	//	carposz += carspeed;
	//}

	if ((Application::IsKeyPressed('W')) && stage2 == false)
	{
		carposy += jumpheight;
	/*
		if (jumpheight + carposy >4)
			carposy = -carposy;
		jumpheight += (float)(carposy * 0.1 * dt);*/
		if (jumpheight > 4)
			carposy = -carposy;

	}
	if ((Application::IsKeyPressed('W')) && stage2 == true)
	{
		carposx -= carspeed;
	}
	if ((Application::IsKeyPressed('D')) && stage2 == true)
	{
		carposz -= carspeed;
	}
	if ((Application::IsKeyPressed('A')) && stage2 == true)
	{
		carposz += carspeed;
	}


	if (entityContainer.at(0)->getPosZ() < -640)
	{
		/*carposx -= 10;
		if (carposx < -25)
			carposx = -25;*/
		stage2 = true;
		if (stage2 = true)
		{
			carrot += (float)rotatespeed *dt* 100;

			if (carrot >= 90)
				carrot = 90;

			camera.position.y = entityContainer.at(0)->getPosY() + 40;
			camera.position.z = entityContainer.at(0)->getPosZ() ;
			camera.position.x = entityContainer.at(0)->getPosX() +70;

		}
	}



	camera.Update(dt);

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

void SceneSP02::RenderGameScene()
{
	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_OBSTACLEFALL], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_OBSTACLEBLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLDFLOOR], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLDFLOOR2], true);
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




	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_TRAPS], true);
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BRIDGE], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_BLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_WORLD2FLOOR], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_MOVINGBLOCKS], true);
	modelStack.PopMatrix();
	//////////////////////////////////////////
	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FALLENTRUNK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_GATE], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_GIANTBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTCLAMP], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTCLAMP], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_LEFTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_RIGHTMOVINGBLOCK], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_SLOWPAD], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_UPDOWNBLOCKS], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_FLOATINGBLOCK], true);
	modelStack.PopMatrix();

}

void SceneSP02::RenderPlayers()
{
	modelStack.PushMatrix();
	//modelStack.Translate(carposx, carposy, carposz);
	modelStack.Translate(entityContainer.at(0)->getPosX(), entityContainer.at(0)->getPosY(), entityContainer.at(0)->getPosZ());
	modelStack.Rotate(carrot, 0, 1, 0);
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

	RenderSkybox();
	RenderPlayers();
	RenderGameScene();

	// for testing purposes
	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(1)->getPosX(), entityContainer.at(1)->getPosY(), entityContainer.at(1)->getPosZ());
	//modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(5, 5, 5);
	//RenderMesh(meshList[GEO_GONG], true);
	modelStack.PopMatrix();


	if (collisionDetected == false) {
		RenderTextOnScreen(meshList[GEO_TEXT], "Collision not detected", Color(220, 20, 60), 2, 1,15);
	}
	else {
		RenderTextOnScreen(meshList[GEO_TEXT], "Collision DETECTED", Color(220, 20, 60), 2, 1, 20);
	}

	//RenderTextOnScreen(meshList[GEO_TEXT], "X0: ", Color(220, 20, 60), 2, 1, 10);
	//std::string test = std::to_string(entityContainer.at(0)->getLowestX());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 10);

	//RenderTextOnScreen(meshList[GEO_TEXT], "Y0: ", Color(220, 20, 60), 2, 1, 9);
	//test = std::to_string(entityContainer.at(0)->getLowestY());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 9);

	//RenderTextOnScreen(meshList[GEO_TEXT], "Z0: ", Color(220, 20, 60), 2, 1, 8);
	//test = std::to_string(entityContainer.at(0)->getLowestZ());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 8);

	//RenderTextOnScreen(meshList[GEO_TEXT], "X1: ", Color(220, 20, 60), 2, 1, 7);
	//test = std::to_string(entityContainer.at(1)->getLowestX());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 7);

	//RenderTextOnScreen(meshList[GEO_TEXT], "Y1: ", Color(220, 20, 60), 2, 1, 6);
	//test = std::to_string(entityContainer.at(1)->getLowestY());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 6);

	//RenderTextOnScreen(meshList[GEO_TEXT], "Z1: ", Color(220, 20, 60), 2, 1, 5);
	//test = std::to_string(entityContainer.at(1)->getLowestZ());
	//RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 5);

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
	test = std::to_string(entityContainer.at(1)->getHeighestX());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 7);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y1: ", Color(220, 20, 60), 2, 1, 6);
	test = std::to_string(entityContainer.at(1)->getHeighestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 6);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z1: ", Color(220, 20, 60), 2, 1, 5);
	test = std::to_string(entityContainer.at(1)->getHeighestZ());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 5, 5);
	//////////////////////////////////////

	RenderTextOnScreen(meshList[GEO_TEXT], "SP: ", Color(220, 20, 60), 2, 16, 10);
	test = std::to_string(entityContainer.at(0)->getSpeed());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 10);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y0: ", Color(220, 20, 60), 2, 16, 9);
	test = std::to_string(entityContainer.at(0)->getLowestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 9);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z0: ", Color(220, 20, 60), 2, 16, 8);
	test = std::to_string(entityContainer.at(0)->getLowestZ());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 8);

	RenderTextOnScreen(meshList[GEO_TEXT], "X1: ", Color(220, 20, 60), 2, 16, 7);
	test = std::to_string(entityContainer.at(1)->getLowestX());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 7);

	RenderTextOnScreen(meshList[GEO_TEXT], "Y1: ", Color(220, 20, 60), 2, 16, 6);
	test = std::to_string(entityContainer.at(1)->getLowestY());
	RenderTextOnScreen(meshList[GEO_TEXT], test, Color(220, 20, 60), 2, 19, 6);

	RenderTextOnScreen(meshList[GEO_TEXT], "Z1: ", Color(220, 20, 60), 2, 16, 5);
	test = std::to_string(entityContainer.at(1)->getLowestZ());
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
