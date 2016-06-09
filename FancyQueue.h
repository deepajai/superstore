#ifndef FANCYQUEUE_H_INCLUDED
#define FANCYQUEUE_H_INCLUDED
//#define TYPE int
//#include "FancyArray.h"
#include "FancyArray.cpp"

template <class T>

class FancyQueue : public FancyArray<T> {
    public:
    FancyQueue(int size);
    FancyQueue(const FancyQueue<T> & tt);
    FancyQueue<T> & enque(T el) ;
    T deque();

};

#endif // FANCYSTACK_H_INCLUDED

