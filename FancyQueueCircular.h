#ifndef FANCYQUEUE_H_INCLUDED
#define FANCYQUEUE_H_INCLUDED
//#define TYPE int
//#include "FancyArray.h"
#include "FancyArray.cpp"

template <class T>
class FancyQueueCircular : public FancyArray<T> {
    int rear;
    int front;
    public:

    void print();
    FancyQueueCircular(int size);
    FancyQueueCircular(const FancyQueueCircular<T> & tt);
    FancyQueueCircular<T> & enque(T el) ;
    int nextIndex() ;
    int nextIndex(int) ;
    bool isFull();
    bool isEmpty(T el) ;
    bool isEmpty();
    bool isFull(T el) ;

    T deque();

};

#endif // FANCYSTACK_H_INCLUDED

