#include "Start.h"


Start::Start() {
	this->mainWindow = new Window();
	this->time = new Timer();
}

Start::~Start() {
	delete this->time;
	SDL_DestroyRenderer(this->mainWindow->getRenderer());
	delete this->mainWindow;
	//Quit SDL subsystems
	SDL_Quit();
}

void Start::startInit(){


	this->mainWindow->WindowInit("Project Baby !", 700, 500);
}

//loop of the application
void Start::loop() {

	//Hack to get window to stay up
	bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			//show part
			showTimer(this->time->getHours(), this->time->getminutes());

			//refresh the renderer
			SDL_RenderPresent(this->mainWindow->getRenderer());

			returnMouseClick();//

			switch (event.type) {

				case SDL_MOUSEBUTTONDOWN:
				//test click button coords 
				returnMouseClick();

				//test is a button
				ButtonOrNo();

				//left button click
				UseButton(event.button);
				break;

				case SDL_QUIT:
					//Quit SDL subsystems
					SDL_Quit();

				default:
					break;
			}
		}
	}
}

//button part

void Start::showButton(int buttonX, int buttonY, int buttonH, int buttonW, int buttonR, int buttonG, int buttonB) {

	rectangle.x = buttonX;
	rectangle.y = buttonY;
	rectangle.h = buttonH;
	rectangle.w = buttonW;
 
 		//define color for the renderer
	if (SDL_SetRenderDrawColor(this->mainWindow->getRenderer(), buttonR, buttonG, buttonB, SDL_ALPHA_OPAQUE) != 0) {
		this->mainWindow->SDL_ExitWithError("impossible de dessiner une couleur");
	}

	if (SDL_RenderFillRect(this->mainWindow->getRenderer(), &rectangle) != 0) {
		this->mainWindow->SDL_ExitWithError("impossible de dessiner un rectangle");
	}
	//SDL_RenderPresent(this->mainWindow->getRenderer());
}

//Timer part

void Start::showTimer(int hours, int minutes) {

	this->time->TakeHours();
	SDL_SetRenderDrawColor(this->mainWindow->getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
	this->mainWindow->SDL_CleanRenderer();

	showButton(250, 0, 700, 250, 128, 128, 128);



	//------------------------------------------------------------------------------------------//
	//initialise une font pour mon ecriture 
	this->test = TTF_OpenFont("font/leadcoat.ttf", 24);

	//crée la couleur bleu en rgb
	SDL_Color bleu = { 0, 255, 255 };

	string timer = to_string(hours) + "h " + to_string(minutes) + "m ";

	//crée un texte sur une surface puis inser la font, texte, couleur
	this->surfacemessage = TTF_RenderText_Solid(this->test, timer.c_str(), bleu);

	//conversion de la surface en texture 
	this->Message = SDL_CreateTextureFromSurface(this->mainWindow->getRenderer(), this->surfacemessage);

	Message_rect.x = 0; // le message afficher sera en haut a gauche
	Message_rect.y = 0;
	Message_rect.h = this->surfacemessage->h;
	Message_rect.w = this->surfacemessage->w;


	SDL_RenderCopy(this->mainWindow->getRenderer(), this->Message, NULL, &Message_rect);

	SDL_FreeSurface(this->surfacemessage);
	SDL_DestroyTexture(this->Message);

	//afficher le texte
	//SDL_RenderPresent(this->mainWindow->getRenderer());
	

}

//Mouse

void Start::returnMouseClick() {
	int buttons;
	SDL_PumpEvents();
	buttons = SDL_GetMouseState(&mouseX, &mouseY);
	SDL_Log("message %d, %d", mouseX, mouseY);
	if ((buttons & SDL_BUTTON_LMASK) != 0) {
		SDL_Log("mouse button 1 is pressed");
	}
}


void Start::ButtonOrNo() {
	int x = mouseX;
	int y = mouseY;
}

int Start::UseButton(SDL_MouseButtonEvent& b) {
	if (b.button == SDL_BUTTON_LEFT) {
		//click gauche
	}
	return 0;
}

