
#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"
#include "Audio.h"

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);
	static int SceneChoice;
	static bool changeScene;

	enum e_Scene {

			STARTMENU,
			CUSTOMIZATION,
			FREEMODE,
			NORMALMODE,
			INSTRUCTION,

		};
private:

	
	Audio audio;
	//Declare a window object
	StopWatch m_timer;
};

#endif