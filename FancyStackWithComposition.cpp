#ifndef FancySTackWithComposition_CPP_INCLUDED
#define FancySTackWithComposition_CPP_INCLUDED

#include "FancyStackWithComposition.h"

    template <class T>
    FancyStack<T>::FancyStack(int size){
        this->array_list = new FancyArray<T>(size);
    }

    //template <class T>
    //FancyStack<T>::FancyStack(const FancyStack<T> & tt)
    //:FancyArray<T>(tt) {

    //}  // Copy Constructor

    template <class T>
    FancyStack<T> & FancyStack<T>::push(T el) {
        this->array_list->insertAtBegin(el);
        return *this;
    }
    template <class T>
    T FancyStack<T>::pop() {
        if(this->array_list->isEmpty()) throw "Stack is empty !";
        T tmp = this->array_list->getByIndex(0);
        this->array_list->remove(tmp);
        return tmp;
    }
    template <class T>
    T FancyStack<T>::top() {
        if(this->array_list->isEmpty()) throw "Stack is empty !";
        return this->array_list->getByIndex(0);
    }
        template <class T>
        bool FancyStack<T>::isEmpty() { return this->array_list->isEmpty(); }
        template <class T>
        bool FancyStack<T>::isFull() { return this->array_list->isFull(); }
        template <class T>
        FancyStack<T> & FancyStack<T>::display(){ this->array_list->print(); return *this;};
//template class FancySet<int>;
#endif
