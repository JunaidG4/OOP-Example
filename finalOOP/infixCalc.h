#include "myStack.h"

class infixCalculator
{
private:
    bool operatorCheck(char);
    bool operandCheck(char);
    int checkPrecedence(char);
    int result(stack<char>, char* infix);
    int value(char);
    string infixToPostfix(stack<char>, string);
    string infixToPrefix(stack<char>, string);

public:

    void start();

};

