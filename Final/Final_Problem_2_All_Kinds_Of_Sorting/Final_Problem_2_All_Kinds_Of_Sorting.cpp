/*
 * File:   Final_Problem_2_All_kinds_of_sorting
 * Author: Isaac Perez
 * Created: 06/8/2026
 * Purpose:  Use a class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>

using namespace std;

//User Libraries
#include "Prob2Sort.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "The start of Problem 2, the sorting problem" << endl;
    Prob2Sort<char> rc;
    bool ascending = true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);
    char* ch2 = new char[10 * 16];
    char* ch2p = ch2;
    while (infile.get(*ch2)) { cout << *ch2;ch2++; }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    int column;
    cin >> column;
    char* zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 16;j++) {
            cout << zc[i * 16 + j];
        }
    }
    delete[]zc;
    cout << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations