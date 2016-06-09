#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;
class Item
{
    public:
        Item();
        virtual ~Item();
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        double Getprice() { return price; }
        void Setprice(double val) { price = val; }
        bool operator==(Item & i) { return i.Getname() == this->Getname(); }
    protected:
    private:
        string name;
        double price;
};

#endif // ITEM_H
