#pragma once
#include <iostream>

using namespace std;

//const for arraysize

template<typename A>
class stack
{
private:
    

public:
    int arraySize;
    A* stackArr;
    int top;
    stack();
    int push(A);
    int topElem();
    A pop();
    int size();
    bool isEmpty();
    bool isFull();
    void toString();
};

//--------------------stack--------------------

template<typename A>
stack<A>::stack()
{
    arraySize = 100;
    stackArr = new A[arraySize];
    top = -1;
}

template<typename A>
bool stack<A>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template<typename A>
bool stack<A>::isFull()
{
    if (top == (arraySize - 1))
        return 1;
    else
        return 0;
}

template<typename A>
int stack<A>::push(A n)
{
    if (isFull()) {
        return 0;
    }
    top++;
    stackArr[top] = n;
    return n;
}

template<typename A>
int stack<A>::topElem()
{
    if (isEmpty())
        return 0;
    else
        return stackArr[top];
}

template<typename A>
A stack<A>::pop()
{
    int temp;
    if (isEmpty())
        return 0;
    temp = stackArr[top];
    top--;
    return temp;

}

template<typename A>
int stack<A>::size()
{
    if (isEmpty())
        return 0;
    else
        return top + 1;
}

template<typename A>
void stack<A>::toString()
{

    cout << "stack is: ";
    for (int i = (top); i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << endl;
}