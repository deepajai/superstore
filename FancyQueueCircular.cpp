#ifndef FancyQueue_CPP_INCLUDED
#define FancyQueue_CPP_INCLUDED

#include "FancyQueueCircular.h"

template <class T>
FancyQueueCircular<T>::FancyQueueCircular(int size):FancyArray<T>(size) {
    rear = front = -1;
}

template <class T>
FancyQueueCircular<T>::FancyQueueCircular(const FancyQueueCircular<T> & tt)
:FancyArray<T>(tt) {

}  // Copy Constructor

template <class T>
FancyQueueCircular<T> & FancyQueueCircular<T>::enque(T el) {

    cout << " front = " << front << " end = " << rear << endl;
    if( this->isFull() )
        throw "Queue is Full !";
        // this->upsizeArray();
    cout << "Next index = " << this->nextIndex() << endl;
    if ( this->isEmpty() ) front ++;
    this->list_ptr[this->nextIndex()] = el;
    rear++;
    return *this;
}

template <class T>
void FancyQueueCircular<T>::print() {

    int i = front+1 ;
    int next_index = this->nextIndex(i);

    while(next_index > front) {
        next_index = this->nextIndex(i--);
        cout << this->list_ptr[next_index] << ", ";
    }
}


template <class T>
T FancyQueueCircular<T>::deque() {
    cout << " front = " << front << " end = " << rear << endl;
    if( this->isEmpty() )
        throw "Queue is Empty!";
        // this->upsizeArray();
    T tmp = this->list_ptr[front];
    front = this->nextIndex(front);
    return tmp;
}

template <class T>
bool FancyQueueCircular<T>::isEmpty() {
    return (this->front == -1) ? true : false;
}

template <class T>
bool FancyQueueCircular<T>::isFull() {
    return nextIndex() == front  ? true : false;
}

template <class T>
int FancyQueueCircular<T>::nextIndex() {
    return (this->rear+1)%this->getSize();
}

template <class T>
int FancyQueueCircular<T>::nextIndex(int current) {
    return  (current+1)%this->getSize();
}


//template class FancySet<int>;
#endif // FancyStack_H_INCLUDED
