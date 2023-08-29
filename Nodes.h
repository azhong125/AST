#ifndef NODES_H
#define NODES_H
#include "AST.h"
// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.
class Nodes : public AST {
public:
    // Member functions for output:
    std::string prefix() const = 0;
    std::string postfix() const = 0;
    double virtual value() const  = 0;
};

class Number:public Nodes{
public:
    Number();
    virtual ~Number();
    double num;
    double virtual value() const;
    std::string prefix() const;
    std::string postfix() const;
};

class Operation:public Nodes {
public:
    Operation();
    virtual ~Operation();
    Nodes* num1;
    Nodes* num2;
};

class Add:public Operation {
public:
    std::string prefix() const;
    std::string postfix() const;
    double virtual value() const;
};
class Subtract:public Operation{
public:
    std::string prefix() const;
    std::string postfix() const;
    double virtual value() const;
};
class Multiply:public Operation {
public:
    std::string prefix() const;
    std::string postfix() const;
    double virtual value() const;
};
class Divide:public Operation {
public:
    std::string prefix() const;
    std::string postfix() const;
    double virtual value() const;
};
class Mod:public Operation{
public:
    std::string prefix() const;
    std::string postfix() const;
    double virtual value() const;
};
class Negate:public Operation{
public:
    std::string prefix() const;
    std::string postfix() const;
    double virtual value() const;
};



#endif