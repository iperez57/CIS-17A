/*
 * File:   Gaddis_8thEd_Chap6_Prob7_CelsiusTable
 * Author: Isaac Perez
 * Created: 03/15/2026
 * Purpose:  Convert fahrenheit to ceslius and display a table using functions
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void celsius(double);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    // 
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Fahrenheit" << setw(15) << "Celsius" << endl;
    for (int f = 0; f <= 20; f++)
    {
        celsius(f);
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations

void celsius(double f)
{
    double c = 5 / 9.0f * (f - 32);
    cout << fixed << setprecision(0) << setw(5) << f << setprecision(2) << setw(20) << c << endl;

}
