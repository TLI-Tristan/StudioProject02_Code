#include "FreeGameMode.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "Mtx44.h"
#include "Application.h"
#include "Utility.h"
#include "LoadTGA.h"

SceneFreeGameMode::SceneFreeGameMode()
{
}

SceneFreeGameMode::~SceneFreeGameMode()
{
}

void SceneFreeGameMode::Init()
{

	remove("Position.txt");

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	glEnable(GL_CULL_FACE);

	camera.Init(Vector3(500, 0, 0), Vector3(0, 10, 0), Vector3(0, 1, 0), "player01", true);

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

	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");

	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");

	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");


	glUseProgram(m_programID);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	light[0].type = Light::LIGHT_SPOT; // position changes for car 1
	light[0].position.Set(0, 0, 0);
	light[0].color.Set(255, 255, 255);
	light[0].power = 0.01;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(25));
	light[0].cosInner = cos(Math::DegreeToRadian(20));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, 0.f, 2.f);

	light[1].type = Light::LIGHT_SPOT; // position changes
	light[1].position.Set(0, 0, 0);
	light[1].color.Set(255, 255, 255);
	light[1].power = 0.01;
	light[1].kC = 1.f;
	light[1].kL = 0.01f;
	light[1].kQ = 0.001f;
	light[1].cosCutoff = cos(Math::DegreeToRadian(25));
	light[1].cosInner = cos(Math::DegreeToRadian(20));
	light[1].exponent = 1.f;
	light[1].spotDirection.Set(0.f, 0.f, 2.f);


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

	glUniform1i(m_parameters[U_NUMLIGHTS], 2);

	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID,
		"textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID,
		"textColor");

	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);

	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(255, 255, 255), 1000.f, 600.f, true);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//grass.tga", true);

	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(255, 255, 255), 1000.f, 600.f, false);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//sky2.tga", false);

	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(255, 255, 255), 600.f, 300.f, false);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//sky2.tga");

	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(255, 255, 255), 600.f, 300.f, false);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//sky2.tga");

	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(255, 255, 255), 1000.f, 300.f, false);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//sky2.tga", false);

	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(255, 255, 255), 1000.f, 300.f, false);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//sky2.tga", false);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");



	// for the track
	meshList[GEO_STRAIGHT] = MeshBuilder::GenerateOBJ("Floor", "Obj/Cube.obj");
	meshList[GEO_TURNLEFT] = MeshBuilder::GenerateOBJ("turnLeft", "Obj/TurnLeft.obj");
	meshList[GEO_TURNLEFT2] = MeshBuilder::GenerateOBJ("Gong", "Obj/TurnLeft2.obj");
	meshList[GEO_TURNRIGHT] = MeshBuilder::GenerateOBJ("Gong", "Obj/TurnRight.obj");

	meshList[GEO_TURNRIGHT2] = MeshBuilder::GenerateOBJ("Gong", "Obj/TurnRight2.obj");


	meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("car", "Obj/SP_CarObj.obj");
	meshList[GEO_CAR]->textureID = LoadTGA("Image//cartexture.tga");

	entityContainer.push_back(new Player(Vector3(109, -70, 192), Vector3(0, 0, 0), 5, 5, 6, 500, "player01", true));//0

	meshList[GEO_PLATFORM] = MeshBuilder::GenerateOBJ("platform", "Obj/platform.obj");

	entityContainer.push_back(new Object(Vector3(109, -80, 192), false, false, 18, 1, 18, Vector3(0.0, 0.0, 0.0), 5000.0, Vector3(0.0, 0.0, 0.0), "platform")); //15
	//audio.PlayAudio();

	meshList[GEO_TEST] = MeshBuilder::GenerateOBJ("platform", "Obj/platform.obj");

	f_fps = 0;

	x = "/0";
	y = "/0";
	z = "/0";
	delay = 0.0;

	choice = 0;
	arrowY = 14;

	paused = false;
}

void SceneFreeGameMode::Update(double dt)
{
	this->dt = dt;
	static const float LSPEED = 10.0f;

	if (dt > 0.1) {
		dt = 0.1;
	}

	//if (Application::IsKeyPressed(VK_UP) && delay >= 0.2) {

	//	if (choice == 0) {

	//		choice = 1;
	//		arrowY = 16;

	//	}
	//	else {
	//		choice -= 1;
	//		arrowY += 2;
	//	}

	//	delay = 0.0;


	//}
	//if (Application::IsKeyPressed(VK_DOWN) && delay >= 0.2) {

	//	if (choice == 1) {

	//		choice = 0;
	//		arrowY = 18;
	//	}
	//	else {
	//		choice += 1;
	//		arrowY -= 2;
	//	}

	//	delay = 0.0;

	//}

	//if (Application::IsKeyPressed(VK_RETURN) && delay >= 0.2) {

	//	delay = 0.0;

	//	if (choice == 0) {


	//	}
	//	else if (choice == 1) {

	//		Application::changeScene = true;
	//		Application::SceneChoice = Application::STARTMENU;
	//	}


	//}


	if (paused == false) {

		for (size_t i = 0; i < entityContainer.size(); i++) {

			entityContainer.at(i)->collisionDetector(collisionChecker.collisionCheck(*entityContainer.at(i), entityContainer), collisionChecker.checkCollisionWithTheFloor(*entityContainer.at(i), entityContainer), collisionChecker.getCollidiedItem());
			entityContainer.at(i)->update(dt);

		}

	}
	else {

		if (Application::IsKeyPressed(VK_UP) && delay >= 0.2 && paused == true) {

			if (choice == 0) {

				choice = 1;
				arrowY = 12;

			}
			else {
				choice -= 1;
				arrowY += 2;
			}

			delay = 0.0;

		}
		if (Application::IsKeyPressed(VK_DOWN) && delay >= 0.2 && paused == true) {

			if (choice == 1) {

				choice = 0;
				arrowY = 14;
			}
			else {
				choice += 1;
				arrowY -= 2;
			}

			delay = 0.0;

		}
	}

	if (Application::IsKeyPressed(VK_RETURN) && delay >= 0.2 && paused == true) {

		if (choice == 0) {



			Application::SceneChoice = Application::NORMALMODE;
			Application::changeScene = true;

			for (size_t i = 0; i < entityContainer.size(); i++) {
				delete entityContainer.at(i);
			}
			Exit();
		}
		else if (choice == 1) {

			Application::SceneChoice = Application::STARTMENU;
			Application::changeScene = true;

		}


	}

	if (Application::IsKeyPressed('B') && delay >= 0.2) {

		camera.lockCamera = true;

		delay = 0.0;
	}

	if (Application::IsKeyPressed('V') && delay >= 0.2) {

		camera.lockCamera = false;

		delay = 0.0;
	}

	if (Application::IsKeyPressed('P') && delay >= 0.2) {

		if (paused == false) {

			paused = true;
		}
		else {
			paused = false;
		}

		delay = 0.0;
	}


	f_fps = 1.0f / dt;

	delay += dt;

	s_fps = std::to_string(f_fps);
	x = std::to_string(camera.position.x);
	y = std::to_string(camera.position.y);
	z = std::to_string(camera.position.z);
	ChoseMapParts();

	camera.Update(dt, entityContainer.at(0));


}

void SceneFreeGameMode::RenderMesh(Mesh* mesh, bool enableLight)
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
void SceneFreeGameMode::RenderSkybox() {

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

	/*modelStack.PushMatrix();
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
	modelStack.PopMatrix();*/


}
void SceneFreeGameMode::RenderText(Mesh* mesh, std::string text, Color color)
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
void SceneFreeGameMode::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
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


void SceneFreeGameMode::RenderLight() {


	if (light[0].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}

	if (light[1].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}


}

void SceneFreeGameMode::Render()
{
	//Clear color & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	parts = 0;
	/*for (int i = 0; i < 3; i++)
	{
		ALLCamera(i);
	}
*/
	if (objPOINTER[0] == true)
	{
		parts = CreateOBJ(9);
	}
	if (objPOINTER[1] == true)
	{
		parts = CreateOBJ(10);
	}
	if (objPOINTER[2] == true)
	{
		parts = CreateOBJ(11);
	}
	if (objPOINTER[3] == true)
	{
		parts = CreateOBJ(12);
	}
	if (objPOINTER[4] == true)
	{
		parts = CreateOBJ(13);
	}

	ps4Controller(parts);
	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	modelStack.LoadIdentity();
	/*modelStack.PushMatrix();
	RenderLight();
	modelStack.PopMatrix();*/
	RenderMesh(meshList[GEO_AXES], false); //To be removed

	/*viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();*/

	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(1)->getPosX(), entityContainer.at(1)->getPosY(), entityContainer.at(1)->getPosZ());
	modelStack.Scale(15, 25, 15);
	RenderMesh(meshList[GEO_PLATFORM], true);
	modelStack.PopMatrix();



	modelStack.PushMatrix();
	modelStack.Translate(entityContainer.at(0)->getPosX(), entityContainer.at(0)->getPosY(), entityContainer.at(0)->getPosZ());
	modelStack.Scale(5, 5, 5);
	RenderMesh(meshList[GEO_CAR], true);
	modelStack.PopMatrix();


	RenderSkybox();

	if (paused == true) {

		RenderTextOnScreen(meshList[GEO_TEXT], "GAME IS PAUSEDDDD", Color(0, 255, 0), 2, 12, 25);
		RenderTextOnScreen(meshList[GEO_TEXT], "Press 'P' to resume", Color(0, 255, 0), 2, 14, 18);
		RenderTextOnScreen(meshList[GEO_TEXT], ">", Color(0, 255, 0), 2, 14, arrowY);
		RenderTextOnScreen(meshList[GEO_TEXT], "Reset", Color(0, 255, 0), 2, 16, 14);
		RenderTextOnScreen(meshList[GEO_TEXT], "Return to Menu", Color(0, 255, 0), 2, 16, 12);
	}

	string txt;
	txt = std::to_string(camera.position.x);
	RenderTextOnScreen(meshList[GEO_TEXT], txt, Color(0, 255, 0), 2, 5, 5);
	RenderTextOnScreen(meshList[GEO_TEXT], "XC: ", Color(0, 255, 0), 2, 1, 5);

	txt = std::to_string(camera.position.y);
	RenderTextOnScreen(meshList[GEO_TEXT], txt, Color(0, 255, 0), 2, 5, 7);
	RenderTextOnScreen(meshList[GEO_TEXT], "YC: ", Color(0, 255, 0), 2, 1, 7);

	txt = std::to_string(camera.position.z);
	RenderTextOnScreen(meshList[GEO_TEXT], txt, Color(0, 255, 0), 2, 5, 9);
	RenderTextOnScreen(meshList[GEO_TEXT], "ZC: ", Color(0, 255, 0), 2, 1, 9);

	/*RenderTextOnScreen(meshList[GEO_TEXT], s_fps, Color(0, 255, 0), 2, 5, 1);
	RenderTextOnScreen(meshList[GEO_TEXT], "FPS: ", Color(0, 255, 0), 2, 1, 1);*/


	// spawn the model 



}

void SceneFreeGameMode::Exit()
{
	// Cleanup VBO here
	remove("Position.txt");
	glDeleteProgram(m_programID);

}

// for other game mode 

//void SceneFreeGameMode::ALLCamera(int angle) {
//	if (angle == 1)
//	{
//		viewStack.LoadIdentity();
//		viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
//		modelStack.LoadIdentity();
//	}
//	else if (angle == 2) {
//		viewStack.LoadIdentity();
//		viewStack.LookAt(camera2.position.x, camera2.position.y, camera2.position.z, camera2.target.x, camera2.target.y, camera2.target.z, camera2.up.x, camera2.up.y, camera2.up.z);
//		modelStack.LoadIdentity();
//	}
//	else if (angle == 3)
//	{
//		viewStack.LoadIdentity();
//		viewStack.LookAt(camera3.position.x, camera3.position.y, camera3.position.z, camera3.target.x, camera3.target.y, camera3.target.z, camera3.up.x, camera3.up.y, camera3.up.z);
//		modelStack.LoadIdentity();
//	}
//}

void SceneFreeGameMode::ps4Controller(int x)
{
	/*
	PS4 Controller Code
	button[0] = "sqaure"
	button [1] = x
	button [2] = o
	button [3] = triangle

	button [4] = "L1"
	button [5] = "R1"

	button[6] = "L2"
	button[7] = "R2"

	button[8] = "Share button"
	button[9] = "Options button"
	*/

	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

	int axesCount;
	const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);


	if (1 == present)
	{
		int buttonCount;
		const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);



		if (GLFW_PRESS == buttons[0] || mouse_pressed == true)
		{
			can_spawn = true;
			if (x == 9)
			{
				entityContainer.push_back(new Object(Vector3(CRUSOR_Y_POS, -90, -CRUSOR_X_POS), false, false, 4, 1, 10, Vector3(0.0, 0.0, 0.0), 5000.0, Vector3(0.0, 0.0, 0.0), "platform"));//0
				allSpawningOBJ.push_back(9);
			}
			else if (x == 10)
			{
				entityContainer.push_back(new Object(Vector3(CRUSOR_Y_POS, -90, -CRUSOR_X_POS), false, false, 4, 1, 10, Vector3(0.0, 0.0, 0.0), 5000.0, Vector3(0.0, 0.0, 0.0), "platform"));//1
				allSpawningOBJ.push_back(10);
			}
			else if (x == 11)
			{
				entityContainer.push_back(new Object(Vector3(CRUSOR_Y_POS, -90, -CRUSOR_X_POS), false, false, 4, 1, 10, Vector3(0.0, 0.0, 0.0), 5000.0, Vector3(0.0, 0.0, 0.0), "platform"));//2
				allSpawningOBJ.push_back(11);
			}
			else if (x == 12)
			{
				entityContainer.push_back(new Object(Vector3(CRUSOR_Y_POS, -90, -CRUSOR_X_POS), false, false, 4, 1, 10, Vector3(0.0, 0.0, 0.0), 5000.0, Vector3(0.0, 0.0, 0.0), "platform"));//3
				allSpawningOBJ.push_back(12);
			}
			else if (x == 13)
			{
				entityContainer.push_back(new Object(Vector3(CRUSOR_Y_POS, -90, -CRUSOR_X_POS), false, false, 4, 1, 10, Vector3(0.0, 0.0, 0.0), 5000.0, Vector3(0.0, 0.0, 0.0), "platform"));//4
				allSpawningOBJ.push_back(13);
			}

			mouse_pressed = false;

		}

		if (can_spawn)
		{
			if (GLFW_RELEASE == buttons[1] || GLFW_PRESS == buttons[1])
			{


				for (size_t i = 2; i < entityContainer.size(); i++)
				{
					modelStack.PushMatrix();
					modelStack.Translate(entityContainer.at(i)->getPosX(), entityContainer.at(i)->getPosY(), entityContainer.at(i)->getPosZ());
					modelStack.Scale(2, 2, 2);
					RenderMesh(meshList[allSpawningOBJ.at(i - 2)], true);
					modelStack.PopMatrix();
				}

			}
		}
		else
		{
			cout << "No Map to load" << endl;
		}

	}
}

int SceneFreeGameMode::CreateOBJ(int x) {


	modelStack.PushMatrix();
	modelStack.Translate(CRUSOR_Y_POS, -90, -CRUSOR_X_POS);
	modelStack.Scale(2, 2, 2);
	RenderMesh(meshList[x], true);
	modelStack.PopMatrix();

	return x;
}

void SceneFreeGameMode::LoadMap(vector<string> b) {
	for (int i = 0; i < b.size();)
	{
		modelStack.PushMatrix();
		modelStack.Translate(stoi(b[1 + i]), -90, stoi(b[2 + i]));
		modelStack.Scale(2, 2, 2);
		RenderMesh(meshList[stoi(b[0 + i])], true);
		modelStack.PopMatrix();
		i += 3;
	}
}

void SceneFreeGameMode::ChoseMapParts() {

	if (Application::IsKeyPressed('1'))
	{
		for (int i = 0; i < 10; i++)
		{
			objPOINTER[i] = false;
		}
		cout << "it is spawn" << endl;
		objPOINTER[0] = true;
	}

	if (Application::IsKeyPressed('2'))
	{
		for (int i = 0; i < 10; i++)
		{
			objPOINTER[i] = false;
		}
		objPOINTER[1] = true;
	}
	if (Application::IsKeyPressed('3'))
	{
		for (int i = 0; i < 10; i++)
		{
			objPOINTER[i] = false;
		}
		objPOINTER[2] = true;
	}

	if (Application::IsKeyPressed('4'))
	{
		for (int i = 0; i < 10; i++)
		{
			objPOINTER[i] = false;
		}
		objPOINTER[3] = true;
	}

	if (Application::IsKeyPressed('5'))
	{
		for (int i = 0; i < 10; i++)
		{
			objPOINTER[i] = false;
		}
		objPOINTER[4] = true;
	}


}


//void SceneFreeGameMode::RenderPlayers(int x, int z, int y)
//{
//	modelStack.PushMatrix();
//	modelStack.Translate(20 + x, 10 + z, 0 + y + forwards);
//	modelStack.Rotate(90 + turnRight, 0, 1, 0);
//	modelStack.Scale(10, 10, 10);
//	RenderMesh(meshList[GEO_CAR], true);
//	modelStack.PopMatrix();
//}
