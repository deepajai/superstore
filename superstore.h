#ifndef SUPERSTORE_H
#define SUPERSTORE_H

#include "FancyArray.h"
#include "Customer.h"
#include "Item.h"
#include "SalePerson.h"
class SuperStore
{
    public:
        SuperStore();
        virtual ~SuperStore();
        FancyArray<Item> & Getitems() { return items; }
        void Setitems(FancyArray<Item> val) { items = val; }
        FancyArray<Customer> & Getcustomers() { return customers; }
        void Setcustomers(FancyArray<Customer> val) { customers = val; }
        FancyArray<SalePerson> & GetSalePersons() { return salePersons; }
        void SetSalePersons(FancyArray<SalePerson> val) { salePersons = val; }
    protected:
    private:
        FancyArray<Item> items;
        FancyArray<Customer> customers;
        FancyArray<SalePerson> salePersons;
};

#endif // SUPERSTORE_H
