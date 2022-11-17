#pragma once
#include "Window.h"
#include "Timer.h"
//#include "Biberon.h"
//#include "ShoppingL.h"

class Start{

public:

	Start();
	~Start();

	//main part
	void startInit();
	void loop();

	//in the loop
	void showButton(int buttonX, int buttonY, int buttonH, int buttonW, int buttonR, int buttonG, int buttonB);
	void showTimer(int, int);
	//void timerBib(int);
	//Mouse part
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
	
	//SDL_Rect Messagee_rect;
	//SDL_Surface* surfacemessagee;
};