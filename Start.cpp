#include "Window.h"
#include "Start.h"

Start::Start() {

	rectangle.x = 300;
	rectangle.y = 300;
	rectangle.h = 300;
	rectangle.w = 300;



}

Start::~Start() {
	delete this->time;
	SDL_DestroyRenderer(this->mainWindow->getRenderer());
	delete this->mainWindow;
	//Quit SDL subsystems
	SDL_Quit();
}

void Start::startInit(){

	this->mainWindow = new Window();
	this->time = new Timer();
	this->mainWindow->WindowInit("Project Baby !", 800, 1000);
}

void Start::loop() {

	//Hack to get window to stay up
	bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			//show part
			
			
			showTimer(this->time->getHours(), this->time->getminutes());
			//showButtonStart();
			SDL_RenderPresent(this->mainWindow->getRenderer());

			switch (event.type) {

				case SDL_QUIT:
					quit = true;

				default:
					break;
			}
		}
	}
}

void Start::showButton() {
 
 		//define color for the renderer
	if (SDL_SetRenderDrawColor(this->mainWindow->getRenderer(), 0, 255, 255, SDL_ALPHA_OPAQUE) != 0) {
		this->mainWindow->SDL_ExitWithError("impossible de dessiner une couleur");
	}

	if (SDL_RenderFillRect(this->mainWindow->getRenderer(), &rectangle) != 0) {
		this->mainWindow->SDL_ExitWithError("impossible de dessiner un rectangle");
	}
	//SDL_RenderPresent(this->mainWindow->getRenderer());
}

void Start::showTimer(int hours, int minutes) {

	this->time->TakeHours();
	SDL_SetRenderDrawColor(this->mainWindow->getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
	this->mainWindow->SDL_CleanRenderer();

	showButton();



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


