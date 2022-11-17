#pragma once
#include <Windows.h>

using namespace std;

class Timer
{
protected:
	int hours,
		minutes;
public:
	Timer();
	void Clock();
	int getHours();
	int getminutes();
	void TakeHours();

private:

};