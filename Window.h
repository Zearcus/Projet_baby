#pragma once
#include "general.h"


using namespace std;

class Window{

public:

	Window();
	~Window();
	int WindowInit(const char* name, int heigh, int width);
	void SDL_ExitWithError(const char* message);
	void SDL_CleanRenderer();
	SDL_Renderer* getRenderer();
	
	

protected:

	//int click;
	//bool isRunning;
	
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
	
	
};	