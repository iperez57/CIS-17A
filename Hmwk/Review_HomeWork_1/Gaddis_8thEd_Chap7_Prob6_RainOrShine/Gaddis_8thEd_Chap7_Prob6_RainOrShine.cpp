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
void prntMonthWeather(int, int, int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    // 
    //Initialize all known variables
    const int MONTHS = 3;
    const int DAYS = 30;
    char weather[MONTHS][DAYS];
    int rDays = 0;
    int cDays = 0;
    int sDays = 0;
    int maxRain = 0;
    int maxMonth = -1;
    string month[3] = { "June", "July", "August" };
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
        cout << month[i] << endl;
        for (int j = 0; j < DAYS; j++)
        {
            inputFile >> weather[i][j];
            if (weather[i][j] == 'R')
                rDays++;
            if (weather[i][j] == 'S')
                sDays++;
            if (weather[i][j] == 'C')
                cDays++;
        }
        prntMonthWeather(rDays, cDays, sDays);

        if (rDays > maxRain)
        {
            maxRain = rDays;
            maxMonth = i;
        }
        rDays = 0;
        cDays = 0;
        sDays = 0;
        cout << endl;

    }
    cout << endl;
    cout << "The month with the most rainy days is " << month[maxMonth] << " with " << maxRain << " days." << endl;


    inputFile.close();
    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void prntMonthWeather(int rDays, int cDays, int sDays)      // print number of days that are rainy, cloudy, or sunny
{
    cout << "# of Rainy days: " << rDays << endl;
    cout << "# of Cloudy days: " << cDays << endl;
    cout << "# of Sunny days: " << sDays << endl;

}

