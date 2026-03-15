/*
 * File:   Gaddis_8thEd_Chap3_Prob13_CurrencyConversion
 * Author: Isaac Perez
 * Created: 03/15/2026
 * Purpose:  Convert USD into japanese yen and euros
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
    int dol;
    const double yen_per_dollar = 159.74;
    const double euros_per_dollar = 0.87;
    //Initialize all known variables
    // 
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Enter an amount in USD: ";
    cin >> dol;
    cout << "That is " << fixed << showpoint << setprecision(2) << dol * yen_per_dollar << " in yen" << endl;
    cout << "That is " << fixed << showpoint << setprecision(2) << dol * euros_per_dollar << " in euros" << endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations