/*
 * File:   Gaddis_8thEd_Chap14_Prob2_Day_of_Year.cpp
 * Author: Isaac Perez
 * Created: 05/15/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries

class DayOfYear
{
private:
    int day;
    static string months[12];
public:
    DayOfYear(int);
    void print();
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int user;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "enter a day of the year (1-365)" << endl;
    do
    {
        cin >> user;
        if (user < 1 || user > 365)
        {
            cout << "Try again" << endl;
        }
    } while (user < 1 || user > 365);
    
    DayOfYear doy(user);
    doy.print();
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
string DayOfYear::months[12] =
{
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

DayOfYear::DayOfYear(int user)
{
    day = user;
}

void DayOfYear::print()
{
    int month;
    if (day <= 31)
    {
        month = 0;
    }
    else if (day <= 59)
    {
        month = 1;
    }
    else if (day <= 90)
    {
        month = 2;
    }
    else if (day <= 120)
    {
        month = 3;
    }
    else if (day <= 151)
    {
        month = 4;
    }
    else if (day <= 181)
    {
        month = 5;
    }
    else if (day <= 212)
    {
        month = 6;
    }
    else if (day <= 243)
    {
        month = 7;
    }
    else if (day <= 273)
    {
        month = 8;
    }
    else if (day <= 304)
    {
        month = 9;
    }
    else if (day <= 334)
    {
        month = 10;
    }
    else
    {
        month = 11;
    }


    cout << "Day " << day << " would be " << months[month] << " " << day;
}