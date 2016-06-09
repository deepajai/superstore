#ifndef FANCYLINKLIST_H_INCLUDED
#define FANCYLINKLIST_H_INCLUDED

template <class T>
class FancyLinkList {
    T * head;
    T * iterator_ptr;
public:
    FancyLinkList();
    FancyLinkList<T> & insertAtBegin(T);
    FancyLinkList<T> & insertAtEnd(T);
    FancyLinkList<T> & insertAfter(T, T);

    FancyLinkList<T> & deleteFromBegin();
    FancyLinkList<T> & deleteFromEnd();
    FancyLinkList<T> & deleteAfter(T);

    T * findNode(T);



    T * begin();
    T * end();

    T * next();
    T * current();
    //T * prev();
    FancyLinkList<T> & reset();
    void print();




    bool isEmpty();
    bool isFull();
    bool contains();

};

#endif // FANCYSTACK_H_INCLUDED

