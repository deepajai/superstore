#ifndef FANCYSTACK_H_INCLUDED
#define FANCYSTACK_H_INCLUDED
//#define TYPE int
//#include "FancyArray.h"
#include "FancyArray.cpp"

template <class T>
class FancyStack {
    FancyArray<T> * array_list;
    public:
        FancyStack(int size);
        FancyStack (const FancyStack &); // Copy Constructor
        FancyStack<T> & push(T el);
        T pop();
        T top();
        bool isEmpty();
        bool isFull();
        FancyStack & display();


};

#endif // FANCYSTACK_H_INCLUDED

