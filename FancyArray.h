#ifndef FANCYARRAY_H_INCLUDED
#define FANCYARRAY_H_INCLUDED
//#define TYPE int
#define UPSIZE_FACTOR 2
#include <iostream>
#include <math.h>
using namespace std;

template <class TYPE>
class FancyArray {
protected:
    TYPE * list_ptr;
    int size;
    int index;
public:

    FancyArray(int size);
    FancyArray(const FancyArray &); // Copy Constructor

    FancyArray * newDeepCopy(FancyArray & o, int new_size);
    FancyArray & insertAtBegin(TYPE el);
    FancyArray & insertAtEnd(TYPE el);
    FancyArray & insertAfterByIndex(TYPE el, int index);
    FancyArray & insertAfter(TYPE , TYPE );

    FancyArray & deleteFromBegin();
    FancyArray & deleteFromEnd();
    FancyArray & deleteFromIndex(int index);
    FancyArray & del(TYPE el);

    FancyArray & print();

    FancyArray & shiftLeft(int);
    FancyArray & shiftRight(int);

    int findByValue(TYPE el);



    int getSize() ;
    bool add(TYPE el);
    bool addall(TYPE el_list[], int size);
    int lastIndexOf(TYPE el);
    int firstIndexOf(TYPE el);
    bool contains(TYPE el);
    TYPE & getByIndex(int index);
    bool remove(TYPE val);
    void clear();
    ~FancyArray();
    bool isEmpty();
    int length();
    int inArray(TYPE el) ;

    void sort(int order = FancyArray::A, int algorith = FancyArray::INSERTION_SORT);





// UTILITY FUNCTIONS

protected:
    bool indexOutOfBound(int i);
    bool isFull();
   FancyArray & upsizeArray();
    bool downSizeArray(int i);

};

#endif // FANCYARRAY_H_INCLUDED
