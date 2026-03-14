/*
* File: Gaddis_8thEd_Chap3_Prob12_DivSalesDisplay
* Author: Isaac Perez
* Created: 03/14/2025
* Purpose: using iomanip to display output in specific format
*/

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    double divSales = 25.4;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << fixed << showpoint<< setw(8) << setprecision(2) <<  divSales;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations