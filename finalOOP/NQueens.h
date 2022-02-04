#include "myStack.h"

class solveNQ
{
private: 
    void printResult(stack<int>(&stk), int);
    void nQueens(stack<int> stk, int, int);
    void nQueens(int);
    void runAgain();
    bool legalCheck(stack<int> stk);
    int itrReset();
    int solReset();

public:
    void calculate();
    
};

