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
    float tempCount = 0;
    float rainCount = 0;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    for (int i = 0; i < 6; i++)
    {
        cout << "Enter the total rainfall for the month:" << endl;
        cin >> m[i].rainfall;
        rainCount++;
        cout << "Enter the high temp:" << endl;
        cin >> m[i].hTemp;
        tempCount++;
        cout << "Enter the low temp:" << endl;
        cin >> m[i].lTemp;
        tempCount++;
        avgRain += m[i].rainfall;
        if (m[i].hTemp > highTemp)
            highTemp = m[i].hTemp;
        if (m[i].lTemp < lowTemp)
            lowTemp = m[i].lTemp;
        avgTemp += m[i].hTemp + m[i].lTemp;
    }
    cout << "Average monthly rainfall:" << avgRain / rainCount << endl;
    cout << "High Temp:" << highTemp << endl;
    cout << "Low Temp:" << lowTemp << endl;
    cout << "Average Temp:" << avgTemp / tempCount;
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations