#include <sstream>
#include "AST.h"
#include "Nodes.h"
using namespace std;
#include "Stack.h"
#include "stdexcept"
#include <iostream>

bool isNumber(string s) {
    int decCount = 0;
    if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-' && s[0] != '.') {
        return false;
    }
    for (int i = 1; i < (int) s.length(); ++i) {
        if (s[i] == '.') decCount++;
        if (!isdigit(s[i]) && s[i] != '.') {
            return false;
        }
    }
    if (decCount > 1) return false;
    return true;
}

AST* AST::parse(const std::string& expression) {
    Stack stack;
    string str = expression;
    istringstream ss(str);
    string digit;
    while (ss >> digit) {
        if (digit == "+" || digit == "-" || digit == "*" || digit == "/" || digit == "%") {
            Operation* newNode;
            if (digit == "+") {
                newNode = new Add();
            } else if (digit == "-") {
            newNode = new Subtract();
            } else if (digit == "*") {
                newNode = new Multiply();
            } else if (digit == "/") {
                newNode = new Divide();
            } else {
                newNode = new Mod();
            }
            newNode->num2 = stack.bottom();
            if (newNode->num2 == NULL) {
                delete newNode;
                throw runtime_error("Not enough operands.");
            }
            stack.popBack();
            newNode->num1 = stack.bottom();
            if (newNode->num1 == NULL) {
                delete newNode;
                throw runtime_error("Not enough operands.");
            }
            stack.popBack();
            stack.push(newNode);
        } else if (digit == "~") {
            Negate *newNode = new Negate();
            newNode->num1 = stack.bottom();
            if (newNode->num1 == NULL) {
                delete newNode;
                throw runtime_error("Not enough operands.");
            }
            stack.popBack();
            stack.push(newNode);
        }else if (isNumber(digit)) {
            Number* newNode = new Number();
            newNode->num = stod(digit);
            stack.push(newNode);
        } else {
            stack.clear();
            throw runtime_error("Invalid token: " + digit);
        }
    }

    if (stack.node == NULL || stack.node->ast == NULL) {
        throw runtime_error("No input.");
    } else if (stack.node->next != NULL) {
        stack.clear();
        throw runtime_error("Too many operands.");
    }

    Nodes* ast = (stack.node->ast);
    stack.deleteNode(stack.node);
    return ast;
}