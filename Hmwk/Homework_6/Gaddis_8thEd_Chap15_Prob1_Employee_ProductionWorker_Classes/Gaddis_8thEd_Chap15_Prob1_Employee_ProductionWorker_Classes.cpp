/*
 * File:   Gaddis_8thEd_Chap15_Prob1_Employee_ProductionWorker_Classes.cpp
 * Author: Isaac Perez
 * Created: 05/11/2026
 * Purpose:  use class inheritance
 */

 //System Libraries
#include <iostream>  //I/O Library
#include "ProductionWorker.h"

using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    ProductionWorker prod("John Doe", "Jan 04 04", 12345, 1, 13.50);
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << " Name: " << prod.getName() << endl;
    cout << " Hire date: " << prod.getDate() << endl;
    cout << " Employee ID: " << prod.getNumber() << endl;
    cout << " Shift: " << prod.getShift() << endl;
    cout << " Pay rate: " << prod.getPayRate() << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
