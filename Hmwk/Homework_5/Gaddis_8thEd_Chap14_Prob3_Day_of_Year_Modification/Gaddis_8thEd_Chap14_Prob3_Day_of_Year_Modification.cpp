/*
 * File:   Gaddis_8thEd_Chap14_Prob3_Day_of_Year_Modification.cpp
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
    int dayM;
    string month;
    static string months[12];
public:
    DayOfYear(int);
    DayOfYear(string, int);
    void print();
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int userD;
    string userM;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Enter a month" << endl;
    cin >> userM;

    cout << "Enter a day in that month (number)" << endl; 
    cin >> userD;

    DayOfYear doy(userM, userD);
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

DayOfYear::DayOfYear(string m, int d)
{
    month = m;
    dayM = d;

    if (month == "January")
    {
        day = d;
    }
    else if (month == "February")
    {
        day = 31 + d;
    }
    else if (month == "March")
    {
        day = 59 + d;
    }
    else if (month == "April")
    {
        day = 90 + d;
    }
    else if (month == "May")
    {
        day = 120 + d;
    }
    else if (month == "June")
    {
        day = 151 + d;
    }
    else if (month == "July")
    {
        day = 181 + d;
    }
    else if (month == "August")
    {
        day = 212 + d;
    }
    else if (month == "September")
    {
        day = 243 + d;
    }
    else if (month == "October")
    {
        day = 273 + d;
    }
    else if (month == "November")
    {
        day = 304 + d;
    }
    else if (month == "December")
    {
        day = 334 + d;
    }
}

void DayOfYear::print()
{
    cout << month << " " << dayM << " is day " << day;
}