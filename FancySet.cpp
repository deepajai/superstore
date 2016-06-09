#include "FancySet.h"

    template <class T>
    FancySet<T>::FancySet(int size):FancyArray<T>(size) {}

    template <class T>
    FancySet<T>::FancySet(const FancySet<T> & tt)
    :FancyArray<T>(tt) {

    }  // Copy Constructor

    template <class TYPE>
    FancySet<TYPE> & FancySet<TYPE>::insertAtBegin(TYPE el){
        if(this->isFull()) {
            this->upsizeArray();
        }
        if(this->elementExists(el)) throw  "Element already in list.";
        this->shiftRight(0);
        this->list_ptr[0] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancySet<TYPE> & FancySet<TYPE>::insertAtEnd(TYPE el) {
        if(this->isFull()) {
            this->upsizeArray();
        }
        if(this->elementExists(el)) throw  "Element already in list.";
        this->list_ptr[this->index] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancySet<TYPE> & FancySet<TYPE>::insertAfter(TYPE el, TYPE after) {
        if(this->isFull()) {
            this->upsizeArray();
        }
        if(this->elementExists(el)) throw  "Element already in list.";
        int index = this->findByValue(after);
        if(this->indexOutOfBound(index))
            throw "Element not found";

        this->shiftRight(index+1);
        this->list_ptr[index+1] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancySet<TYPE>& FancySet<TYPE>::insertAfterByIndex(TYPE el, int index) {
        if(this->isFull()) {
            this->upsizeArray();
        }
        if(this->elementExists(el)) throw  "Element already in list.";
        this->shiftRight(index+1);
        this->list_ptr[index+1] = el;
        ++this->index;
        return *this;
    }


    template <class T>
    FancySet<T> FancySet<T>::intersectSets(FancySet<T> & t){
        FancySet<T> newFt(5) ;
        for(int i = 0 ; i < t.index; i++)
        {
            int find_index = this->findByValue(t.getByIndex(i));
            if(find_index > -1) newFt.insertAtBegin(t.getByIndex(i));
        }
        return newFt;

    }
    template <class T>
    FancySet<T> FancySet<T>::diffSets(FancySet<T> & t){
        FancySet<T> newFt = *this ;
        for(int i = 0 ; i < t.index; i++)
        {
            newFt.del(t.list_ptr[i]);
        }
        return newFt;
    }
    template <class T>
    FancySet<T> FancySet<T>::unionSets(FancySet & t){
        FancySet<T> newFt = t ;
        for(int i = 0 ; i < this->index; i++)
        {
            if(this->elementExists(this->list_ptr[i])) continue;
            t.insertAtEnd(this->list_ptr[i]);
        }
        return newFt;

    }
    template <class T>
    bool FancySet<T>::elementExists(T el) {return (-1 < this->findByValue(el));}

//template class FancySet<int>;
//template class FancySet<float>;
//template class FancySet<string>;
