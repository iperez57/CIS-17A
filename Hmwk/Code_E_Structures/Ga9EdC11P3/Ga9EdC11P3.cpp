/*
 * File:   Ga9EdC11P3
 * Author: Isaac Perez
 * Created: 04/14/2026
 * Purpose:  Use structures 
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
struct CompanyDiv
{
    enum Division { North, East, South, West };
    string name;
    float q1;
    float q2;
    float q3;
    float q4;
    float annSales;
    float avgQSales;
};
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    CompanyDiv div[4];
    string names[4] = { "North", "East", "South", "West" };
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    for (int i = 0; i < 4; i++)
    {
        div[i].name = names[i];
        cout << div[i].name << endl;
        cout << "Enter first quarter sales: ";
        cin >> div[i].q1;
        cout << "Enter second quarter sales: ";
        cin >> div[i].q2;
        cout << "Enter third quarter sales: ";
        cin >> div[i].q3;
        cout << "Enter fourth quarter sales: ";
        cin >> div[i].q4;
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations