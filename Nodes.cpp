#include "Nodes.h"
#include "stdexcept"
#include <cmath>
#include <sstream>
using namespace std;
#include <iostream>

Number::Number() {
    num = 0;
}
Number::~Number() {
}
double Number::value() const{
    return num;
}
std::string Number::prefix() const{
    std::ostringstream stream;
    stream << num;
    return stream.str();
}
std::string Number::postfix() const{
    std::ostringstream stream;
    stream << num;
    return stream.str();
}

Operation::Operation() {
    num1 = NULL;
    num2 = NULL;
}
Operation::~Operation() {
    delete num1;
    delete num2;
}

double Add::value() const {
    return num1->value() + num2->value();
}
std::string Add::prefix() const{
    return "+ " + num1->prefix() + " " + num2->prefix();
}
std::string Add::postfix() const{
    return num1->postfix() + " " + num2->postfix() + " +";
}
double Subtract::value() const {
    return num1->value() - num2->value();
}
std::string Subtract::prefix() const{
    return "- " + num1->prefix() + " " + num2->prefix();
}
std::string Subtract::postfix() const{
    return num1->postfix() + " " + num2->postfix() + " -";
}
double Multiply::value() const {
    return num1->value() * num2->value();
}
std::string Multiply::prefix() const{
    return "* " + num1->prefix() + " " + num2->prefix();
}
std::string Multiply::postfix() const{
    return num1->postfix() + " " + num2->postfix() + " *";
}
double Divide::value() const {
    if (num2->value() == 0 ) throw std::runtime_error("Division by zero.");
    return num1->value() / num2->value();
}
std::string Divide::prefix() const{
    return "/ " + num1->prefix() + " " + num2->prefix();
}
std::string Divide::postfix() const{
    return num1->postfix() + " " + num2->postfix() + " /";
}
double Mod::value() const {
    if (num2->value() == 0 ) throw std::runtime_error("Division by zero.");
    return std::fmod(num1->value(), num2->value());
}
std::string Mod::prefix() const{
    return "% " + num1->prefix() + " " + num2->prefix();
}
std::string Mod::postfix() const{
    return num1->postfix() + " " + num2->postfix() + " %";
}
double Negate::value() const {
    return num1->value() * -1;
}
std::string Negate::prefix() const{
    return "~ " + num1->prefix();
}
std::string Negate::postfix() const{
    return num1->postfix() + " ~";
}