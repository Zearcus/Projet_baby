#pragma once
#include <iostream>

using namespace std;

class biberon
{
protected:
	int QuantityLeft;
	int MaxCapacity;
	int MinCapacity;
	bool Vomit;

public:
	biberon();
	biberon(int, int);
	void AddOrDrink(int, char , bool);
	int Quantity();
	int CapacityChange(int);
};