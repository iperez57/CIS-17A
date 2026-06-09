/*
 * File:   Final_Problem_4_Saving_Account_Class
 * Author: Isaac Perez
 * Created: 06/9/2026
 * Purpose:  Use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

#include "SavingsAccount.h"

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
    SavingsAccount mine(-300);
    for (int i = 1;i <= 10;i++) {
        mine.Transaction((float)(rand() % 500) * (rand() % 3 - 1));
    }
    mine.toString();
    cout << "Balance after 7 years given 10% interest = "
        << mine.Total((float)(0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
        << mine.TotalRecursive((float)(0.10), 7)
        << " Recursive Calculation " << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations