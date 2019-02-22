
#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);

private:

	enum e_MENU {

		STARTMENU,
		CUSTOMIZATION,
		FREEMODE,
		NORMALMODE,
		PAUSEMENU,
		VICTORY,
		GAMEOVER,

	};

	//Declare a window object
	StopWatch m_timer;
};

#endif