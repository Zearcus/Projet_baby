#pragma once
#include <Windows.h>

using namespace std;

class Timer
{
protected:
	int hours,
		minutes;
	/*int hoursminuteur = 0;
	int minutesminuteur = 0;
	int    secondsminuteur = 60;*/

public:
	Timer();
	void Clock();
	int getHours();
	int getminutes();
	void TakeHours();

	


	/*int getHoursMinuteur();
		int getminutesMinuteur();
		int getSecondsMinuteur();*/


		/*void showMinuteur();*/


private:

};