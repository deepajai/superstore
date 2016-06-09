#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;
class Customer
{
    public:
        Customer();
        virtual ~Customer();
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getcontact() { return contact; }
        void Setcontact(string val) { contact = val; }

    protected:
    private:
        string name;
        string contact;
};

#endif // CUSTOMER_H
