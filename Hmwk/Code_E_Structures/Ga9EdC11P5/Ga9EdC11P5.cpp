/*
 * File:   Ga9EdC11P5
 * Author: Isaac Perez
 * Created: 04/14/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
struct MonthInfo
{
    enum months { January, February, March, April, May, June, July, August, September, October, November, December };
    float rainfall = 0;
    float hTemp = 0;
    float lTemp = 0;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    MonthInfo m[6];
    float avgRain = 0;
    float highTemp = 0;
    float lowTemp = 200;
    float avgTemp = 0;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    for (int i = 0; i < 6; i++)
    {
        cout << "Enter the total rainfall for the month:" << endl;
        cin >> m[i].rainfall;
        cout << "Enter the high temp:" << endl;
        cin >> m[i].hTemp;
        cout << "Enter the low temp:" << endl;
        cin >> m[i].lTemp;
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations