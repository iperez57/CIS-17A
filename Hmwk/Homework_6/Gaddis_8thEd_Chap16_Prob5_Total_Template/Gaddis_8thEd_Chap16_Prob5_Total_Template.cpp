/*
 * File:   Gaddis_8thEd_Chap16_Prob5_Total_Template.cpp
 * Author: Isaac Perez
 * Created: 05/23/2026
 * Purpose:  use class templates
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
template<class T>
T total(int n)
{
    T sum = 0;
    T value;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        sum += value;
    }

    return sum;
}
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int n;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "How many integers ?" << endl;
    cin >> n;

    cout << "enter values: " << endl;
    cout << "Total = " << total<int>(n) << endl;

    cout << "How many doubles ?" << endl;
    cin >> n;

    cout << "enter values: " << endl;
    cout << "Total = " << total<double>(n) << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
