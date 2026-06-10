/*
 * File:   Final_Problem_7_Menu
 * Author: Isaac Perez
 * Created: 06/10/2026
 * Purpose:  conversions
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

//User Libraries
#include "Prob1.h"
#include "Prob2.h"
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void runProblem1();
void runProblem2();
void runProblem3();
void runProblem4();
void runProblem5();
void runProblem6();

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    int choice;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    do 
    {
        cout << "1. Problem 1 - Random Sequence" << endl;
        cout << "2. Problem 2 - Sorting" << endl;
        cout << "3. Problem 3 - Spreadsheet table" << endl;
        cout << "4. Problem 4 - Savings Account" << endl;
        cout << "5. Problem 5 - Employee Class" << endl;
        cout << "6. Problem 6 - Conversion" << endl;
        cout << "0. Exit" << endl;
        cout << " Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            runProblem1();
            break;

        case 2:
            runProblem2();
            break;

        case 3:
            runProblem3();
            break;

        case 4:
            runProblem4();
            break;
        case 5:
            runProblem5();
            break;
        case 6:
            runProblem6();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void runProblem1()
{
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    char n = 5;
    char rndseq[] = { 19,34,57,79,126 };
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    for (int i = 1;i <= ntimes;i++)
    {
        a.randFromSet();
    }
    int* x = a.getFreq();
    char* y = a.getSet();
    for (int i = 0;i < n;i++) {
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
}

void runProblem2()
{
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
}
void runProblem6()
{
    cout << " 5.75" << endl;
    cout << "1. Binary: 101.11     Octal: 5.6      Hex: 5.C" << endl;
    cout << "2. NASA: 0. 1011 1000 0000 0000 0000 0000 0000 0011" << endl;
    cout << "B8000003" << endl;
    cout << "3. 1466" << endl;
    cout << "4. 40.243" << endl;
    cout << "5. 0.100 0000 1011 1000 0000 0000 0000 0000" << endl;
    cout << " 40B80000" << endl;
    cout << endl;

    cout << "0.9" << endl;
    cout << "1. Binary: 0.11100110011...       Octal: 0.71463... Hex: 0.E666..." << endl;
    cout << "2. NASA: 0. 1110 0110 0110 0110 0110 0110 0000 0000" << endl;
    cout << "E6666600" << endl;
    cout << "3. 58981" << endl;
    cout << "4. 6.3000076" << endl;
    cout << "5. 0.011 1111 0110 0110 0110 0110 0110 0110" << endl;
    cout << "6. 3F666666" << endl;
    cout << endl;

    cout << "99.7" << endl;
    cout << "1. Binary: 1100011.10110011...        Octal: 143.546314...      Hex: 63.b333..." << endl;
    cout << "2. NASA: 0. 1100 0111 0110 0110 0110 0110 0000 0111" << endl;
    cout << "C7666607" << endl;
    cout << "3. 1672687555" << endl;
    cout << "4. 697.9" << endl;
    cout << "5. 0100 0010 1100 0111 0110 0110 0110 0110" << endl;
    cout << "42C76666" << endl;

}