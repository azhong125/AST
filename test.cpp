#include "AST.h"
#include <iostream>
using namespace std;


int main() {
    string test = "1 +";
    //string test = "12 3 + 5 4 + 2 / *";
    AST* ast;
    ast = ast->parse(test);
    cout << ast->value() << endl;
    ast->~AST();
    //ast->postfix();

}
