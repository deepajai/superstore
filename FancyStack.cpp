#ifndef FancyStack_H_INCLUDED
#define FancyStack_H_INCLUDED

#include "FancyStack.h"

    template <class T>
    FancyStack<T>::FancyStack(int size):FancyArray<T>(size) {}

    template <class T>
    FancyStack<T>::FancyStack(const FancyStack<T> & tt)
    :FancyArray<T>(tt) {

    }  // Copy Constructor

    template <class T>
    FancyStack<T> & FancyStack<T>::push(T el) {
        this->insertAtBegin(el);
        return *this;
    }
    template <class T>
    T FancyStack<T>::pop() {
        if(this->isEmpty()) throw "Stack is empty !";
        T tmp = this->getByIndex(0);
        this->remove(tmp);
        return tmp;
    }
    template <class T>
    T FancyStack<T>::top() {
        if(this->isEmpty()) throw "Stack is empty !";
        return this->getByIndex(0);
    }
        template <class T>
        bool FancyStack<T>::isEmpty() { return FancyArray<T>::isEmpty(); }
        template <class T>
        bool FancyStack<T>::isFull() { return FancyArray<T>::isFull(); }
        template <class T>
        FancyStack<T> & FancyStack<T>::display(){ this->print(); return *this;};
template class FancyStack<int>;
#endif // FancyStack_H_INCLUDED
