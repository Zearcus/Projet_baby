#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Items
{
    string name;
    int Quantity;
};

class shopList
{
private:

    vector<Items*> Products;

public:

    shopList();
    ~shopList();
    void ChangeQuantity(string name, int quantity, char op);
    void AddItem(string, int);
    void RemoveItem(string);
    void ShowList();
};

