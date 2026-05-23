/*
 * File:   Gaddis_8thEd_Chap16_Prob4_Absolute_Value_Template.cpp
 * Author: Isaac Perez
 * Created: 05/23/2026
 * Purpose:  use class templates
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
template<class T>
T absolute(T a)
{
    if (a < 0)
    {
        a = a * -1;
        return a;
    }
    else return a;
}
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
    cout << "Absolute of -5: " << absolute(-5) << endl;
    cout << "Absolute of 10: " << absolute(10) << endl;

    cout << "Absolute of -3.7: " << absolute(-3.7) << endl;
    cout << "Absolute of 2.5: " << absolute(2.5) << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
