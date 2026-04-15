/*
 * File:   Ga9EdC11P11
 * Author: Isaac Perez
 * Created: 04/15/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
struct MonthlyBudget
{
    float housing = 500.00;
    float utilities = 150.00;
    float householdExpenses = 65.00;
    float transportation = 50.00;
    float food = 250.00;
    float medical = 30.00;
    float insurance = 100.00;
    float entertainment = 150.00;
    float clothing = 75.00;
    float miscellaneious = 50.00;

};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void input(MonthlyBudget m);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    MonthlyBudget m;

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    input(m);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void input(MonthlyBudget m)
{
    cout << "Enter housing cost for the month:$" << endl;
    cin >> m.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> m.utilities;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> m.householdExpenses;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> m.transportation;
    cout << "Enter food cost for the month:$" << endl;
    cin >> m.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> m.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> m.insurance;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> m.entertainment;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> m.clothing;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> m.miscellaneious;
}