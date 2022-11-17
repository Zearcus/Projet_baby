#include "ShoppingL.h"
#include <string>
#include <algorithm>
using namespace std;

shopList::shopList()
{

}

shopList::~shopList()
{

}

// Add a item and a quantity to this item, if the input name is the same as a name which is already in the database, reject the item.
void shopList::AddItem(string name, int Quant)
{
    Items* item = new Items;
    if (item->name == name)
    {
        cout << "You already have this article." << endl;
    }
    else 
    {  
        Items* item = new Items;
        item->name = name;
        item->Quantity = Quant;
        Products.push_back(item);
        cout << item->name << "had been had to your shopping list." << endl;
    }
}

// Change the quantity of a specific item and choose to add or remove.
void shopList::ChangeQuantity(string name, int quantity, char op)
{
    for (int i = 0; i < Products.size(); i++)
    {
        if (Products[i]->name == name && op == '+')
        {
            this->Products[i]->Quantity = Products[i]->Quantity + quantity;
        }
        else if (Products[i]->name == name && op == '-')
        {
            this->Products[i]->Quantity = Products[i]->Quantity - quantity;
        }
    }
}

 // Remove the item and the quantity of the item
void shopList::RemoveItem(string name)
{
    for (int i = 0; i < Products.size(); i++)
    {
        if (Products[i]->name == name)
        {
            this->Products.erase(this->Products.begin() + i);
        }
    }
}
 // Show what inside your shopping list
void shopList::ShowList()
{
    if (Products.empty())
    {
        cout << "Your shopping list is empty." << endl;
    }
    else 
    {
        for (int i = 0; i < Products.size(); i++)
        {
            cout << "Name:" << Products[i]->name << "Quantity:" << Products[i]->Quantity << endl;
        }
    }
    
}