/*
 * File:   Gaddis_8thEd_Chap7_Prob6_RainOrShine
 * Author: Isaac Perez
 * Created: 03/15/2026
 * Purpose:     reading txt file to display values.
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
// 
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    char cast;
    //Initialize all known variables
    const int MONTHS = 3;
    const int DAYS = 30;
    char weather[MONTHS][DAYS];
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Read external file
    ifstream inputFile("RainOrShine.txt");

    if (!inputFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < MONTHS; i++)
    {
        switch (i)
        {
        case 0:
            cout << "June" << endl;
            break;
        case 1:
            cout << "July" << endl;
            break;
        case 2: cout << "August" << endl;
            break;
        }
        for (int j = 0; j < DAYS; j++)
        {
            inputFile >> weather[MONTHS][DAYS];
            cout << weather[MONTHS][DAYS] << " ";
        }
        cout << endl;
    }

    inputFile.close();
    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations

