#ifndef FANCYEXPRESSION_H_INCLUDED
#define FANCYEXPRESSION_H_INCLUDED
//#define TYPE int
//#include "FancyArray.h"
#include "FancyStack.cpp"
using namespace std;

class FancyExpression  {
    public:
        float evalPostFix(string);
        string toPostFix(string);
        bool precedence(char o1, char o2 );
        bool isOperator(char o1 );

};

#endif // FANCYSTACK_H_INCLUDED

