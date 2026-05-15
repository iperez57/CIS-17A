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
    day = d;
    month = m;
}

void DayOfYear::print()
{
    cout << month << " " << day << " is day ";
}