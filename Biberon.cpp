#include "Biberon.h"

biberon::biberon(int QuantLeft, int MaxCap)
{
	this->QuantityLeft = QuantLeft;
	this->MaxCapacity = MaxCap;
	this->MinCapacity = 0;
}

biberon::biberon()
{

}

void biberon::AddOrDrink(int Amount, char Op, bool Vomit)
{
	if (Op == '+')
	{
		if (QuantityLeft > MaxCapacity)
		{
			cout << "The bottle can't contain more." << endl;
		}
		else if (QuantityLeft <= MaxCapacity)
		{
			this->QuantityLeft = QuantityLeft += Amount;
			Quantity();
		}
	}
	else if (Op == '-')
	{
		if (QuantityLeft <= MinCapacity)
		{
			cout << "There is no more milk" << endl;
		}
		else if (Vomit == true && QuantityLeft >= MinCapacity)
		{
			this->QuantityLeft = QuantityLeft -= Amount;
			cout << "Your baby vomitted the milk" << endl;
			Quantity();
		}

		else if (QuantityLeft >= MinCapacity)
		{
			this->QuantityLeft = QuantityLeft -= Amount;
			Quantity();
		}
	}
}

int biberon::Quantity()
{
	cout << QuantityLeft << endl;
	return QuantityLeft;
}

int biberon::CapacityChange(int NewCapacity)
{
	if (NewCapacity != this->MaxCapacity)
	{
		this->MaxCapacity = NewCapacity;
	}
	return NewCapacity;
}
