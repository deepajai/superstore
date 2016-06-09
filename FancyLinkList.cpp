#ifndef FancyLinkList_CPP_INCLUDED
#define FancyLinkList_CPP_INCLUDED

#include "FancyLinkList.h"
#include "FancyNode.h"
#include <iostream>

    template <class T>
    FancyLinkList<T>::FancyLinkList() {this->head = nullptr;}
    template <class T>
    FancyLinkList<T> & FancyLinkList<T>::insertAtBegin(T n) {
        if( this->isEmpty())
            this->head       = new T(n.getData(), nullptr);
        else
            this->head       = new T(n.getData(), this->head);
        return *this;
    }


    template <class T> FancyLinkList<T> & FancyLinkList<T>::deleteAfter(T n) {
        T * t = this->findNode(n);
        if(t) {
            T * temp = t->next;
            t->next = t->next->next;
            delete temp;
        }
        return *this;
    }

    template <class T> FancyLinkList<T> & FancyLinkList<T>::insertAfter(T n, T m){
        T * t = this->findNode(n);
        if(t) {
            T * temp = t->next;
            t->next = new T(m.getData());
            t->next->next = temp;
        }
    }


    template <class T>
    FancyLinkList<T> & FancyLinkList<T>::insertAtEnd(T n) {
        if(isEmpty())
            head = new T(n.getData());
        else
            this->end()->next = new T(n.getData());
        return *this;
    }




    template <class T>
    FancyLinkList<T> & FancyLinkList<T>::deleteFromBegin() {
        T * t = this->head;
        this->head = this->head->next;
        delete t;
        return *this;
    }

    template <class T>
    FancyLinkList<T> & FancyLinkList<T>::deleteFromEnd() {
        this->reset();

        if(this->current() == nullptr)
        {
             throw "List is empty";
             return *this;
        }

        if(this->current()->next == nullptr){
            this->head = nullptr;
            this->reset();
            return *this;
        }

        while(this->current()->next->next){
            this->next();
        }

        delete this->current()->next;
        this->current()->next = nullptr;

        return *this;
    }

    template <class T>
    T * FancyLinkList<T>::findNode(T data) {
        this->reset();
        while(this->current()) {
            if(this->current()->equals(data))
            {
                return this->current();
            }
            this->next();
        }
    }


    template <class T>
    T * FancyLinkList<T>::begin() { return this->head;}
    template <class T>
    T * FancyLinkList<T>::end() {
        this->reset();
        T * t ;
        while(this->current()) {
         t = this->current();
         this->next();
        }

        this->reset();
        return t;
    }

    template <class T>
    T  *FancyLinkList<T>::next() {
        if(this->iterator_ptr == nullptr) return nullptr;
        this->iterator_ptr = this->iterator_ptr->next;
        return this->iterator_ptr;
    }
    template <class T>
    T * FancyLinkList<T>::current() { return this->iterator_ptr; }
    //template <class T>
    //T * FancyLinkList<T>::prev(){  }
    template <class T>
    FancyLinkList<T> & FancyLinkList<T>::reset(){ this->iterator_ptr = this->head; return *this; }

    template <class T>
    bool FancyLinkList<T>::isEmpty() {return this->head == nullptr;}
    //template <class T>
    //bool FancyLinkList<T>::isFull() { }
    template <class T>
    bool FancyLinkList<T>::contains(){}

    template <class T>
    void FancyLinkList<T>::print(){
        this->reset();
        while(this->current())
        {
            this->current()->print();
            this->next();
        }
        this->reset();
    }


#endif // FancyStack_H_INCLUDED
