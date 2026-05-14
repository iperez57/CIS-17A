/*
 * File:   Gaddis_8thEd_Chap13_Prob1_Date.cpp
 * Author: Isaac Perez
 * Created: 05/14/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>


using namespace std;

//User Libraries
class Date
{
private:
    int month;
    int day;
    int year;
public:

    // mm/dd/yyyy
    void numericFormat(int, int, int);
    // month dd, yyyy
    void writtenFormat(int, int, int);
    // dd, month, yyyy
    void customFormat(int, int, int);

};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int m;
    int d;
    int y;
    Date date;
    
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "enter month" << endl;
    cin >> m;
    cout << "enter day" << endl;
    cin >> d;
    cout << "enter year" << endl;
    cin >> y;

    date.numericFormat(m, d, y);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void Date::numericFormat(int m, int d, int y)
{
    cout << endl;
    cout << "mm/dd/yyyy" << endl;
    cout << setfill('0') << setw(2) << m << "/" << setfill('0') << setw(2) << d << "/" << y << endl;
}