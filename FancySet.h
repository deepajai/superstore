#ifndef FANCYSET_H_INCLUDED
#define FANCYSET_H_INCLUDED
//#define TYPE int
//#include "FancyArray.h"
#include "FancyArray.cpp"

template <class T>
class FancySet : public FancyArray<T> {
    public:
        FancySet(int size);
        FancySet (const FancySet &); // Copy Constructor
        bool elementExists(T el);

        FancySet  intersectSets(FancySet &);
        FancySet  unionSets(FancySet &);
        FancySet  diffSets(FancySet &);

        FancySet<T> & insertAfterByIndex(T el, int index);
        FancySet<T> & insertAfter(T el, T after);

        FancySet<T> & insertAtBegin(T el);
        FancySet<T> & insertAtEnd(T el);

};

#endif // FANCYSET_H_INCLUDED

