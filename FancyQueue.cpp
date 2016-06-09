#ifndef FancyQueue_CPP_INCLUDED
#define FancyQueue_CPP_INCLUDED

#include "FancyQueue.h"

template <class T>
FancyQueue<T>::FancyQueue(int size):FancyArray<T>(size) {}

template <class T>
FancyQueue<T>::FancyQueue(const FancyQueue<T> & tt)
:FancyArray<T>(tt) {

}  // Copy Constructor

template <class T>
FancyQueue<T> & FancyQueue<T>::enque(T el) {
    this->insertAtEnd(el);
    return *this;
}
template <class T>
T FancyQueue<T>::deque() {
    if(this->isEmpty()) throw "Queue is empty !";
    T tmp = this->getByIndex(0);
    this->remove(tmp);
    return tmp;
}

//template class FancySet<int>;
#endif // FancyStack_H_INCLUDED
