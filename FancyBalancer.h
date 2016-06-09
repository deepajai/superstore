#ifndef FANCYBALANCER_H_INCLUDED
#define FANCYBALANCER_H_INCLUDED
//#define TYPE int
//#include "FancyArray.h"
#include "FancyStack.cpp"
using namespace std;

class FancyBalancer  {
    public:
        FancyBalancer();
        bool parseString(string);
        bool isValidHTML(string);
};

#endif // FANCYSTACK_H_INCLUDED

