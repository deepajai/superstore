#ifndef SALEPERSON_H
#define SALEPERSON_H


#include "FancyArray.h"
#include "Customer.h"

#include <iostream>
using namespace std;

class SalePerson
{
    public:
        SalePerson();
        virtual ~SalePerson();
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        FancyArray<Customer> & Getcustomers() { return customers; }
        void Setcustomers(FancyArray<Customer> val) { customers = val; }
    protected:
    private:
        string name;
        FancyArray<Customer> customers;
};

#endif // SALEPERSON_H
