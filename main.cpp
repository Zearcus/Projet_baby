#include "Window.h"
#include "Start.h"
#include "Timer.h"
//#include "Biberon.h"
//#include "ShoppingL.h"


int main(int argc, char* argv[]) {

	Start start;

	start.startInit();
	start.loop();
	SDL_Delay(20);
	

	return 0;
}
