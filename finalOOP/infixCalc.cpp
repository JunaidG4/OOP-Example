#include "infixCalc.h"

// start function the infix to postfix and prefix calculator

void infixCalculator::start()
{
    stack<char> stk;    //create object of stack class
    infixCalculator calc;   //create object of infixcalc class

    char infix[100];    //char data type for the infix input
    string prefix, postfix;     //string data types for the eventual prefix and postfix
    int result;

    cout << "Infix Expression :" << endl;   //prompt to enter an infix expression
    cin.getline(infix, 100);    //getline fixes a whitespace issue so lets you input with spaces    

    prefix = calc.infixToPrefix(stk, infix);   //does the prefix method
    postfix = calc.infixToPostfix(stk, infix);     //does the postfix method
    result = calc.result(stk, infix);

    // prints the prefix, postfix and result
    cout << "PREFIX: " << prefix << endl
        << "POSTFIX: " << postfix << endl
        << "RESULT: ";
    if (result == -1)
    {
        cout << "ERROR" << endl;
    }
    else
        cout << result << endl;
            
}


//--------------------precedence & operator--------------------

/*
function below checks if the character passed is an operator, if so it returns true
if not it returns false
*/

bool infixCalculator::operatorCheck(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}

/*
function below checks if the character passed is an operand, if so it returns true
if not it returns false
*/

bool infixCalculator::operandCheck(char c)
{
    return 
    {
        (c >= '0' && c <= '9')
    };
}

/*
function below checks the precedence of the infix characters which is a mathematical
functions to decide importance of the mathematical operations that are to be done
*/

int infixCalculator::checkPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}



//--------------------infix to prefix--------------------


// the first character passed must be an operand
int infixCalculator::value(char c)
{
    return (c - '0');
}


/*
this function returns the raw value of the input expression if single numeric values are entered
for this to work we would need to find a number first, or an operand in mathematical terms.
then we have to scan through the remainin characters in pairs to find an operator. if none
are found negative one is returned. if one is then the running result is updated and the operations
are performed on it. once done the final value stored in result is returned
*/
int infixCalculator::result(stack<char> stk, char *infix)
{
    
    if (*infix == '\0')
    {
        return -1;
    }
        
    int result = value(infix[0]);

    for (int i = 1; infix[i]; i += 2)
    {
        char operat = infix[i], operand = infix[i + 1];

        if (!operandCheck(operand))
        {
            return -1;
        }
        if (operat == '+')
        {
            result += value(operand);
        }
        else if (operat == '-')
        {
            result -= value(operand);
        }
        else if (operat == '*')
        {
            result *= value(operand);
        }
        else if (operat == '/')
        {
            result /= value(operand);
        }
        else                  
            return -1;
    }
    return result;
}


/*
for infix to prefix we must first reverse the infix expresion and explicitly swap the bracket types
then it scans the expression from left to right looking for mathematical operations or operands
if an operator has an elevated precedence than the top of the stack then it is pushed onto the stack
if it has equal precedence and is conisdered a power operand then it is popped and prints the top of the stack
if the precedence is lower then it is popped and the top of the stack is printed
then all the operators in the stack are ti be popped and printed and at the end the expression is once again reversed
*/

string infixCalculator::infixToPrefix(stack<char> stk, string infix)
{
    infixCalculator infixC;
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= '0' && infix[i] <= '9'))
        {
            prefix += infix[i];
        }
        else if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((stk.topElem() != '(') && (!stk.isEmpty())) {
                prefix += stk.topElem();
                stk.pop();
            }

            if (stk.topElem() == '(') {
                stk.pop();
            }
        }
        else if (infixC.operatorCheck(infix[i])) {
            if (stk.isEmpty()) {
                stk.push(infix[i]);
            }
            else {
                if (infixC.checkPrecedence(infix[i]) > infixC.checkPrecedence(stk.topElem())) {
                    stk.push(infix[i]);
                }
                else if ((infixC.checkPrecedence(infix[i]) == infixC.checkPrecedence(stk.topElem())) && (infix[i] == '^')) {
                    while ((infixC.checkPrecedence(infix[i]) == infixC.checkPrecedence(stk.topElem()))
                        && (infix[i] == '^')) {
                        prefix += stk.topElem();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
                else if (infixC.checkPrecedence(infix[i]) == infixC.checkPrecedence(stk.topElem())) {
                    stk.push(infix[i]);
                }
                else {
                    while ((!stk.isEmpty()) && (infixC.checkPrecedence(infix[i]) < infixC.checkPrecedence(stk.topElem()))) {
                        prefix += stk.topElem();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
            }
        }
    }

    while (!stk.isEmpty()) {
        prefix += stk.topElem();
        stk.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

//--------------------infix to postfix--------------------

/*
this is the infix to postfix conversion function
if the infix character is considered a mathematical operation then the postfix
is added to or equal the infix character given
if it is not a mathematical operation then it is pushed over to the stack if it an open bracket
if it is a close bracket then it is popped from the stack and printed until the stack is either empty or
an open bracket is found and then that is popped
if the infix is an operator then it will go through the operator check
when comparing infix characters and the top of the stack if the precedence is greater then the that character
is pushed onto the stack. if the precedence is the same or is a power to then it is also pushed to the stack
*/

string infixCalculator::infixToPostfix(stack<char> stk, string infix)
{
    infixCalculator infixC;
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= '0' && infix[i] <= '9'))
        { 
            postfix += infix[i];
        }
        else if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((stk.topElem() != '(') && (!stk.isEmpty()))
            {
                char temp = stk.topElem();
                postfix += temp;
                stk.pop();
            }
            if (stk.topElem() == '(')
            {
                stk.pop();
            }
        }
        else if (infixC.operatorCheck(infix[i]))
        {
            if (stk.isEmpty())
            {
                stk.push(infix[i]);
            }
            else
            {
                if (infixC.checkPrecedence(infix[i]) > infixC.checkPrecedence(stk.topElem()))
                {
                    stk.push(infix[i]);
                }
                else if ((infixC.checkPrecedence(infix[i]) == infixC.checkPrecedence(stk.topElem())) && (infix[i] == '^'))
                {
                    stk.push(infix[i]);
                }
                else
                {
                    while ((!stk.isEmpty()) && (infixC.checkPrecedence(infix[i]) <= infixC.checkPrecedence(stk.topElem())))
                    {
                        postfix += stk.topElem();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
            }
        }
    }
    while (!stk.isEmpty())
    {
        postfix += stk.topElem();
        stk.pop();
    }

    return postfix;
}