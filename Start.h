#pragma once
#include "Window.h"
#include "Timer.h"

class Start{

public:

	Start();
	~Start();

	void startInit();
	void loop();
	void showButton();
	void showTimer(int, int);

	void returnMouseClick();
	void ButtonOrNo();
	int UseButton(SDL_MouseButtonEvent& b);

protected:

	bool quit;
	int mouseX = 0, mouseY = 0;

	//instances
	Window* mainWindow;
	Timer* time;

	SDL_Event event;
	SDL_Rect rectangle;
	SDL_Rect Message_rect;

	//text part
	SDL_Surface* surfacemessage;
	SDL_Texture* Message;
	TTF_Font* test;
	

};