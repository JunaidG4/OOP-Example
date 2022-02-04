//G20811316

#include "NQueens.h"
#include <iomanip>

//keep track of the program (NQueens)
int iterations = 0;
int solutions = 0;

//------------------------------nqueens------------------------------

//functions to reset the iteratios and solutions values otherwise they stack when run again
int solveNQ::itrReset()
{
    return iterations = 0;
}

int solveNQ::solReset()
{
    return solutions = 0;
}

/*
calculate function is where number of queens the user wants to calculate
an int is declared (qSize) and is passed into the nQueens function as the queens to add to the board
at the end the number of solutions is printed along with how many validity checks took place
after this the runAgain function is called in case the user wants to do another value
*/
void solveNQ::calculate()
{
    int qSize;

    solveNQ slv;

    slv.itrReset(); // both this and solReset are to avoid a bug where the values stack if run again
    slv.solReset();
    cout << "Enter the number of Queens to Solve For: ";
    cin >> qSize;

    if (qSize != 0)
    {
        nQueens(qSize);
    }
    else
    {
        cout << "FALSE" << endl;
        calculate();
    }

    

    cout << "number of solutions: " << solutions << endl;
    cout << "valid checks: " << iterations << endl;
    runAgain();

}

/*
runAgain function simply asks the user if they want to use the program again
it takes in a user input and stores it in a string variable
if they answer yes the program calls the calculate function
if no then the programs exits with code 0 for a successful run
if an invalid input is entered then error is shown
*/

void solveNQ::runAgain()
{
    string userEntry;
    cout << "Run Again? (Y/N): " << endl;
    cin >> userEntry;

    if (userEntry == "y" || userEntry == "Y")
    {
        calculate();
    }
    else if (userEntry == "n" || userEntry == "N")
    {
        exit(0);
    }
    else
        cout << "ERROR" << endl;
    runAgain();
}

/*
printing the outputs through the use of a loop which iterates
through the stack array but is limited by the size of the board
setW(3) is used to make the output neater
*/
void solveNQ::printResult(stack<int>(&stk), int sizeOf)
{

    /* for (int i : stk.stackArr)
     {
        cout << setw(3) << i << sizeOf;
     }
     cout << endl;*/ //original output method

    int sizeOfQ = sizeOf - 1;

    for (int i = 0; i <= sizeOfQ; i++)
    {
        cout << setw(3) << stk.stackArr[i];
    }
    cout << endl;
}


/*
testing for conflicts in both the horizontal and diagonal directions
the vertical direction does not need to be tested as we already know
if a queen has been placed in a column and given the rules of chess
another queen cannot be placed in said column
*/
bool solveNQ::legalCheck(stack<int> stk)
{
    iterations++; // adds one to iterations to show how many times solutions were tried at the end

    int value = stk.topElem(); // the value to be tested is the top element in the stack

    //Horizontal Tests
    for (int i = 0; i < stk.size() - 1; i++)
    {
        if (stk.stackArr[i] == value) // if the stack value equals the top element it is deemed false and a queen cannot be placed
        {
            return false;
        }
    }

    // Diagonal Tests
    int offset = 1; //initial offset of 1

    for (int i = stk.size() - 2; i >= 0; i--) //for loop which tests stack value vs top element plus an offset for diagonal axis
    {
        //up
        if (value == stk.stackArr[i] + offset)
        {
            return false;
        }

        //down
        if (value == stk.stackArr[i] - offset)
        {
            return false;
        }
        //offset the value by one
        offset++;
    }

    //if there is no conflict return true
    return true;
}

// need to include the number of queens left to add and also the number of queens TO add
void solveNQ::nQueens(stack<int> stk, int leftToAdd, int totalToAdd)
{
    solveNQ nq;
    // when no queens are left to add iterate solutions and print the vector
    if (leftToAdd == 0)
    {
        solutions++; // adds one to solutions to show number of valid solutions
        nq.printResult(stk, totalToAdd); // passes through the stack and also the number of queens to place to facilitate the 'limiter'
        return;
    }

    stk.push(0); // pushes a 0 onto the stack 

    for (int i = 0; i < totalToAdd; i++)
    {
        //return the reference, add in so it only moves on if there is no collisions***
        stk.stackArr[stk.top] = i; // the top element of the stack is set to i

        if (nq.legalCheck(stk))
        {
            nQueens(stk, leftToAdd - 1, totalToAdd); // passes through the stack and both queen quantity vals
        }

    }
    stk.pop(); // pops the topmost element from the stack
}

// function for the total number of queens to be added to board

void solveNQ::nQueens(int n)
{
    stack<int> stk;
    nQueens(stk, n, n);
}