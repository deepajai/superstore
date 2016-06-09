#ifndef FancyNode_CPP_INCLUDED
#define FancyNode_CPP_INCLUDED

#include "FancyNode.h"

#include <iostream>
    FancyNode::FancyNode(int id, FancyNode * t) {
        this->data = id;
        this->next = t;
    }

    FancyNode::FancyNode(FancyNode & t) {
        this->data = t.data;
        this->next = t.next;
    }

    int FancyNode::getData() { return this->data ; }
    void FancyNode::setData(int data) { this->data = data; }
    bool FancyNode::equals(FancyNode t) {
        return this->data == t.data;
    }
    void FancyNode::print() {
        std::cout  << data << ", ";
    }

#endif // FancyStack_H_INCLUDED
