#ifndef FANCYEXPRESSION_CPP_INCLUDED
#define FANCYEXPRESSION_CPP_INCLUDED

#include "FancyExpression.h"
#include <typeinfo>
#include <iostream>
#include <string>


float FancyExpression::evalPostFix(string){

}

string FancyExpression::toPostFix(string exp){
    int i = 0;
    FancyStack<char> fs(5);
    string new_exp = "";

    while (i < exp.length()) {
        char current = exp[i];
        cout << "Char is " << current << endl;
        if(isOperator(current)) {
            cout << "Current is operator !" << endl;
            while ( !fs.isEmpty() && this->precedence(fs.top(),current) ) {
                cout << "Precedence Check passed  !" << endl;
                if( fs.top() == ')' or fs.top() == '(')
                    fs.pop();
                else
                    new_exp += fs.pop();
            }
            fs.push(current);
        } else {
            new_exp += current;
        }
        cout << " NOW NEW EXPRESSION BECOMES = " << new_exp << endl ;;

        i++;
    }
    //fs.print();
    while(!fs.isEmpty()) {
        if( fs.top() == ')' or fs.top() == '(')
            fs.pop();
        else
            new_exp += fs.pop();
    }
    return new_exp;
}


bool FancyExpression::isOperator(char o1){
    if (
        o1 == '+' or
        o1 == '-' or
        o1 == '*' or
        o1 == '/' or
        o1 == '%' or
        o1 == '(' or
        o1 == ')'
        )
            return true;
        return false;

}

bool FancyExpression::precedence(char o1, char o2 ){
    cout << "Operand 1 is " << o1 << " and operand 2 is " << o2  << endl;
    if (o1 == '+' or o1 == '-' ) {
        if (o2 == '*' or o2 == '/' or o2 == '%')
            return false;
        return true;
    }

    if (o1 == '*' or o1 == '/' or o1 == '%') {
        if (o2 == '+' or o2 == '-' )
            return true;
        return false;
    }

    if (o2 == '(' ) {
        return false;
    }

    if (o2 == ')' ) {
        return true;
    }

    return false;
}
#endif
