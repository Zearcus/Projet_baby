#pragma once
#include <iostream>

using namespace std;

class biberon
{
protected:
    int QuantityLeft;
    int MaxCapacity;
    int regurgiter;
    int MinCapacity;
    bool ValRegurgiter;
    bool IsFull;

public:
    biberon();
    void Full();
    void FillUp(int AmountAdd);
    void MilkDrank(int AmountDrank);
    int Quantity();
    int CapacityChange(int NewCapacity);
    bool Regurgiter(bool ValRegurgiter, int milkLost );
};