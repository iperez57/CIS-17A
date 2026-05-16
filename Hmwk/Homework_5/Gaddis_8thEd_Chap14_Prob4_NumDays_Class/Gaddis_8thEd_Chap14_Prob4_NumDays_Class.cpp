/*
 * File:   Gaddis_8thEd_Chap14_Prob4_NumDays_Class
 * Author: Isaac Perez
 * Created: 05/16/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
#include <iomanip>

using namespace std;

//User Libraries
class NumDays
{
private:
    int hours;
    float days;
public:
    NumDays(int);

    void setHours(int);
    void setDays(float);
    int getHours();
    float getDays();

    void print();
    
    NumDays operator+();
    NumDays operator-();
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);
};

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int userH;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Enter hours worked" << endl;
    cin >> userH;

    NumDays dayW(userH);
    dayW.print();
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
NumDays::NumDays(int h)
{
    hours = h;
    days = h / 8.f;
}

void NumDays::setHours(int h)
{
    hours = h;
}

void NumDays::setDays(float d)
{
    days = d;
}

int NumDays::getHours()
{
    return hours;
}

float NumDays::getDays()
{
    return days;
}

void NumDays::print()
{
    cout << "Hours worked: " << getHours() << endl;
    cout << "Days worked: " << getDays() << endl;
}