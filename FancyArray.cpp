#ifndef FANCYARRAY_CPP_INCLUDED
#define FANCYARRAY_CPP_INCLUDED
#include "FancyArray.h"
#include <typeinfo>

    template <class TYPE>
    FancyArray<TYPE>::FancyArray(int size){

        if(size < 0) {
            throw "List size must be posative.";
        }
        this->list_ptr = new TYPE[size];
        this->size     = size;
        this->index    = 0;
    }

    template <class TYPE>
    FancyArray<TYPE>::FancyArray(const FancyArray & dup){
        this->size = dup.size;
        this->index = dup.index;
        this->list_ptr = dup.list_ptr;
    }

    template <class TYPE>
    FancyArray<TYPE> * FancyArray<TYPE>::newDeepCopy(FancyArray & o, int new_size) {
        if(new_size < 0) {
            throw "List size must be positive, copy failed.";
        }
        FancyArray * n = new FancyArray(new_size);

        for(int i = 0; i < o.index; i++){
            n->list_ptr[i] = o.list_ptr[i];
        }
        n->index = o.index;
        return n;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::print() {
        int i = -1 ;
        while (++i < this->index) { cout << this->list_ptr[i] << ", "; }
        return *this;
    }


    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::insertAtBegin(TYPE el){
        if(this->isFull()) {
            this->upsizeArray();
        }
        this->shiftRight(0);
        this->list_ptr[0] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::insertAtEnd(TYPE el) {
        if(this->isFull()) {
            this->upsizeArray();
        }
        this->list_ptr[this->index] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::insertAfter(TYPE el, TYPE after) {
        if(this->isFull()) {
            this->upsizeArray();
        }
        int index = this->findByValue(after);
        if(indexOutOfBound(index))
            throw "Element not found";

        this->shiftRight(index+1);
        this->list_ptr[index+1] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::insertAfterByIndex(TYPE el, int index) {
        if(this->isFull()) {
            this->upsizeArray();
        }
        this->shiftRight(index+1);
        this->list_ptr[index+1] = el;
        ++this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::deleteFromBegin() {
        this->shiftLeft(0);
        --this->index;
        return *this;
    }

    template <class TYPE>
    int FancyArray<TYPE>::findByValue(TYPE el){
        for(int i = 0 ; i < this->index; i++){
            if( this->list_ptr[i] == el ) return i;
        }
        return -1;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::deleteFromEnd(){
        this->shiftLeft(this->index);
        --this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::del(TYPE el){
        if(this->isEmpty()) {
            throw "Array is already empty, can not delete";
        }
        int index = this->findByValue(el);
        if(this->indexOutOfBound(index))
            throw "Element not found";

        this->shiftLeft(index);
        --this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::deleteFromIndex(int index){
        if(this->indexOutOfBound(index))
            throw "Element not found";

        this->shiftLeft(index);
        --this->index;
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::shiftLeft(int from){
        for(int i = from; i < this->index ; i++) {
            this->list_ptr[i] = this->list_ptr[i+1];
        }
        return *this;
    }

    template <class TYPE>
    FancyArray<TYPE> & FancyArray<TYPE>::shiftRight(int from){
        for(int i = this->index; i > from ; i--) {
            this->list_ptr[i] = this->list_ptr[i-1];
        }
        return *this;
    }



    template <class TYPE>
    bool FancyArray<TYPE>::indexOutOfBound(int i) {
        return ((i < 0) || i > (this->index-1));
    }

    template <class TYPE>
    bool FancyArray<TYPE>::isFull(){ return this->index == this->size;}
    template <class TYPE>
    bool FancyArray<TYPE>::isEmpty() {return this->index == 0;};

    template <class TYPE>
    FancyArray<TYPE> &  FancyArray<TYPE>::upsizeArray(){

        FancyArray * newArray = newDeepCopy(*this, ceil(this->size * UPSIZE_FACTOR));

        delete this;
        *this = *newArray;
        return *this;
    }

    template <class TYPE>
    int FancyArray<TYPE>::getSize() {return this->size;}
    template <class TYPE>
    bool FancyArray<TYPE>::add(TYPE el) { this->insertAtEnd(el); return true;};
    template <class TYPE>
    bool FancyArray<TYPE>::addall(TYPE el_list[], int size) {
        for(int i = 0 ; i < size; i++) this->insertAtEnd(el_list[i]);
        return 1;
    }
    template <class TYPE>
    int FancyArray<TYPE>::lastIndexOf(TYPE el) {
        for(int i = this->index ; i > 0 ; i-- ) {
            if( this->list_ptr[i] == el ) return i;
        }
        return -1;
    }
    template <class TYPE>
    int FancyArray<TYPE>::firstIndexOf(TYPE el) { return this->findByValue(el); }
    template <class TYPE>
    bool FancyArray<TYPE>::contains(TYPE el) { return this->findByValue(el) > -1 ? true : false; }
    template <class TYPE>
    TYPE & FancyArray<TYPE>::getByIndex(int index) { if(this->indexOutOfBound(index)) throw "Index out of bound !" ; return this->list_ptr[index]; }
    template <class TYPE>
    bool FancyArray<TYPE>::remove(TYPE val) { this->del(val); return 1;}
    template <class TYPE>
    void FancyArray<TYPE>::clear() { this->index = 0; }
    template <class TYPE>
    FancyArray<TYPE>::~FancyArray() {
        delete this->list_ptr ;
    }


    template <class TYPE>
    int FancyArray<TYPE>::length() {
        return this->index ;
    }

    template <class TYPE>
    int FancyArray<TYPE>::inArray(TYPE el) {
            return this->contains(el);
    }







    template <class TYPE>
    bool downSizeArray(int i);









//template class FancyArray<int>;
#endif // FANCYARRAY_CPP_INCLUDED
