#include "Stack.h"
#include "stdexcept"
#include <iostream>
using namespace std;
Stack::Stack() {
    node = NULL;
}

void Stack::push(Nodes* ast) {
    if (node == NULL) {
        node = new Node();
        node->ast = ast;
        node->next = NULL;
    } else {
        Node* ptr = node;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new Node();
        ptr->next->ast = ast;
        ptr->next->next = NULL;
    }
}
Nodes* Stack::bottom() {
    Node* ptr = node;
    if (ptr == NULL) {
        clear();
        return NULL;
        //throw std::runtime_error("Not enough operands.");
    }
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr->ast;
}
void Stack::deleteNode(Node *node) {
    node->next = NULL;
    delete node;
    node = NULL;
}
void Stack::popBack() {
    if (node->next == NULL) {
        delete node;
        node = NULL;
        return;
    }
    Node* ptr = node;
    Node* next = node->next;
    while (next->next != NULL) {
        ptr = ptr->next;
        next = next->next;
    }
    ptr->next = NULL;
    delete next;
}
void Stack::print(){
    Node* head = node;
    while (head != NULL) {
        std::cout << head->ast->value() << " ";
        head = head->next;
    }
}
void Stack::clear() {
    Node* firstNode = node;
    while (firstNode != NULL) {
        Node* nextNode = firstNode->next;
        delete firstNode->ast;
        delete firstNode;
        firstNode = nextNode;
    }
}