// finalOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "myStack.h"
#include "infixCalc.h"
#include "NQueens.h"
//G20811316

#include <iostream>
using namespace std;


int main()
{
    infixCalculator infcalc;
    infcalc.start();

    solveNQ NQcalc;
    NQcalc.calculate();

    //int choice; // int value for the choice in the menu
  
    //do
    //{
    //    //menu system
    //    cout << endl;
    //    cout << "0 - Exit" << endl;
    //    cout << "1 - Infix to Postfix & Prefix" << endl;
    //    cout << "2 - NQueens" << endl;

    //    cout << "Enter Option: ";
    //    cin >> choice;

    //    switch (choice)
    //    {
    //    case 0: break;

    //    case 1:
    //        infcalc.start();
    //        break;

    //    case 2:
    //        NQcalc.calculate();
    //        break;

    //    default:
    //        cout << "error" << endl;
    //    }
    //} while (choice != 0);


    //return 0;

    //return 0;
    _CrtDumpMemoryLeaks();
}
