//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>

#include "Application.h"
#include "SceneSP02.h"
#include "GameMenu.h"
#include "FreeGameMode.h"
#include "CustomizationMenu.h"
#include "InstructionMenu.h"

GLFWwindow* m_window;
const unsigned char FPS = 60; // FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame 
int Application::SceneChoice = 0;
bool Application::changeScene = false;



double CRUSOR_X_POS;
double CRUSOR_Y_POS;
double x2Offset;
double y2Offset;


static void cursorPotionCallback(GLFWwindow *window, double xPos, double yPos) {
	
	
	// make the mouse , camera and object follow the same thing 


	CRUSOR_X_POS = xPos - 200;
	CRUSOR_Y_POS = yPos - 100;

	std::cout << "Xpos : " << CRUSOR_X_POS << std::endl;
	std::cout << "Ypos : " << CRUSOR_Y_POS << std::endl;



};

void curosrEnterCallBack(GLFWwindow *window, int entered) {

	if (entered)
	{
		std::cout << "Entered Window" << std::endl;
	}
	else
	{
		std::cout << "Left Window" << std::endl;
	}

};
void mouseButtonCallBack(GLFWwindow *window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right Button pressed" << std::endl;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		std::cout << "Right Button pressed" << std::endl;
	}
};
void scrollCallBack(GLFWwindow *window, double xOffset, double yOffset) {
	//std::cout << "xoff" << xOffset << "      " << "yoffset : " << yOffset << endl;

	x2Offset = xOffset;
	y2Offset = yOffset;
}



//Define an error callback
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Define the key input callback
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

bool Application::IsKeyPressed(unsigned short key)
{
    return ((GetAsyncKeyState(key) & 0x8001) != 0);
}

Application::Application()
{
}

Application::~Application()
{
}

void resize_callback(GLFWwindow* window, int w, int h) 
{
	glViewport(0, 0, w, h); //update opendgl the new window size
}

void Application::Init()
{
	//register
	glfwSetWindowSizeCallback(m_window, resize_callback);

	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional
	glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 


	//Create a window and create its OpenGL context
	m_window = glfwCreateWindow(1920, 1000, "Test Window", NULL, NULL);


	glfwSetCursorPosCallback(m_window, cursorPotionCallback);
	glfwSetCursorEnterCallback(m_window, curosrEnterCallBack);
	glfwSetMouseButtonCallback(m_window, mouseButtonCallBack);
	glfwSetScrollCallback(m_window, scrollCallBack);

	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	//If the window couldn't be created
	if (!m_window)
	{
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(m_window);

	//Sets the key callback
	//glfwSetKeyCallback(m_window, key_callback);

	glewExperimental = true; // Needed for core profile
	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK) 
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		//return -1;
	}
}

void Application::Run()
{
	//Main Loop

	Scene *GameMenu = new SceneGameMenu();
	GameMenu->Init();

	Scene *CustomizationMenu = new SceneCustomizationMenu();
	CustomizationMenu->Init();

	Scene *FreeGameMode = new SceneFreeGameMode();
	FreeGameMode->Init();
	
	Scene *MainGame = new SceneSP02();
	MainGame->Init();

	Scene *InstructionMenu = new SceneInstructionMenu();
	InstructionMenu->Init();

	//Scene *scene = GameMenu;

	Scene *scene = FreeGameMode;

	m_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
	while (!glfwWindowShouldClose(m_window) && !IsKeyPressed(VK_ESCAPE))
	{

		if (Application::changeScene == true) {

			switch (Application::SceneChoice) {
			case STARTMENU:
				scene = GameMenu;
				Application::changeScene = false;
				break;
			case CUSTOMIZATION:
				scene = CustomizationMenu;
				Application::changeScene = false;
				break;
			case FREEMODE: {

				delete FreeGameMode;
				Scene *FreeGameMode = new SceneFreeGameMode();
				scene = FreeGameMode;
				scene->Init();
				Application::changeScene = false;
			}
						   break;

			case NORMALMODE: {
				delete MainGame;
				Scene *MainGame = new SceneSP02();
				scene = MainGame;
				scene->Init();
				Application::changeScene = false;
			}
				break;
			
			case INSTRUCTION: {
				scene = InstructionMenu;
				Application::changeScene = false;
			}
				break;
			}

		}

		scene->Update(m_timer.getElapsedTime());
		scene->Render();
		
		//glScissor(0, 400, 2000, 700);
		//scene->Render();

		/*glScissor(0, 0, 2000, 400);
		scene->Render(2);

		glScissor(0, 250, 500, 500);
		scene->Render(3);
*/


		//Swap buffers
		glfwSwapBuffers(m_window);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...
		glfwPollEvents();
        m_timer.waitUntil(frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.   

	} //Check if the ESC key had been pressed or if the window had been closed
	scene->Exit();
	delete scene;
}

void Application::Exit()
{
	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(m_window);
	//Finalize and clean up GLFW
	glfwTerminate();
}
