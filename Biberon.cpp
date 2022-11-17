#include <iostream>
#include <string>
#include "Biberon.h"

biberon::biberon()
{
    MaxCapacity = 200;
    QuantityLeft = 0;
    IsFull = false;
}

void biberon::MilkDrank(int AmountDrank)
{
    if (QuantityLeft < 0)
    {
        cout << "The bottle is empty." << endl;
    }
    QuantityLeft -= AmountDrank;
}

int biberon::Quantity()
{
    return QuantityLeft;
}

void biberon::Full()
{
    if (QuantityLeft == MaxCapacity)
    {
        IsFull = true;
        cout << "The feeding bottle is full" << endl;
    }
    else
    {
        IsFull = false;
        cout << "The feeding bottle is not full" << endl;
    }
}

void biberon::FillUp(int AmountAdd)
{
    if ((QuantityLeft + AmountAdd) > MaxCapacity)
    {
        cout << "Past the max capacity." << endl;
    }
    QuantityLeft += AmountAdd;
}

int biberon::CapacityChange(int NewCapacity)
{
    return MaxCapacity = NewCapacity;
}

bool biberon::Regurgiter(bool Valregurgiter, int milkLost) {
      // blabla bla demander si il a vomi
    if (ValRegurgiter = true) {

         //afficher QuantityLeft;   
        //donner la quantiter restante
    }
    else{
        ValRegurgiter = false;
    }

    if (MinCapacity > QuantityLeft){
        //afficher ajouter du lait svp !
    }
}