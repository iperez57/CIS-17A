/*
 * File:   Gaddis_8thEd_Chap16_Prob2_Time_Format_Exceptions.cpp
 * Author: Isaac Perez
 * Created: 05/23/2026
 * Purpose:  use class exceptions
 */

 //System Libraries
#include <iostream>  //I/O Library
#include "MilTime.h"
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int h;
    int s;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Enter a time in military format" << endl;
    do
    {
        cout << "Enter hour: ";
        cin >> h;
    } while (h < 0 || h > 2359);
    do
    {
        cout << "Enter seconds: ";
        cin >> s;
    } while (s < 0 || s > 59);

    MilTime mil(h, s);

    cout << "Military time: " << mil.getMilHour() << " " << mil.getSec() << endl;
    cout << "Standard time: " << mil.getStandHr() << " " << mil.getMin() << " " << mil.getSec() << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
