#ifndef SALEPERSON_CPP_INCLUDED
#define SALEPERSON_CPP_INCLUDED

#include "saleperson.h"
#include "FancyArray.cpp"
#include "Customer.h"

SalePerson::SalePerson() : customers(5)
{
    //ctor
}

SalePerson::~SalePerson()
{
    //dtor
}
#endif // SALEPERSON_CPP_INCLUDED
