#ifndef FANCYNode_H_INCLUDED
#define FANCYNode_H_INCLUDED

class FancyNode {
    int data;
public:
    FancyNode * next;
    FancyNode(int id, FancyNode * =nullptr);
    FancyNode(FancyNode &);
    int getData();
    void setData(int);
    bool equals(FancyNode t);
    void print();
};

#endif // FANCYSTACK_H_INCLUDED

