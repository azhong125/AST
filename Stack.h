#ifndef STACK_H
#define STACK_H
#include "Nodes.h"
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
struct Node {
    Nodes* ast;
    Node* next;
};
class Stack {
public:
    Node* node;
    Stack();
    void push(Nodes* ast);
    void print();
    void deleteNode(Node* node);
    void clear();
    void popBack();
    Nodes* bottom();
};

#endif
