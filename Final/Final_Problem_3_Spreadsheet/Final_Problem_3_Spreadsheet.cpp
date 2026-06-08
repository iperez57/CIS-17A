/*
 * File:   Final_Problem_3_Spreadsheet
 * Author: Isaac Perez
 * Created: 06/8/2026
 * Purpose:  Use template class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>

using namespace std;

//User Libraries
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Entering problem number 3" << endl;
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int* naugT = tab.getTable();
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int* augT = tab.getAugTable();
    for (int i = 0;i <= rows;i++) {
        for (int j = 0;j <= cols;j++) {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations