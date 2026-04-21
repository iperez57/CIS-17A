/*
 * File:   Midterm_Problem2_Employee_Checks
 * Author: Isaac Perez
 * Created: 04/21/2026
 * Purpose:  use a structure
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries
struct Employee
{
    string name;
    float hrsWorked;
    float payRate;
    float grossPay;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getData(Employee*, const int);
void calculatePay(Employee*, const int);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int numOfEmp;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "How many employees? ";
    cin >> numOfEmp;

    Employee* e = new Employee[numOfEmp];

    getData(e, numOfEmp);
    calculatePay(e, numOfEmp);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    delete[] e;
    return 0;
}

//Function Implementations
void getData(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {
        cout << endl;
        cout << "Employee #" << i + 1 << endl;
        cout << "Name: ";
        getline(cin >> ws, e[i].name);
        cout << "Hours worked: ";
        cin >> e[i].hrsWorked;
        cout << "Pay rate: $";
        cin >> e[i].payRate;

    }
}

void calculatePay(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {
        if (e[i].hrsWorked <= 40)
        {
            e[i].grossPay = e[i].hrsWorked * e[i].payRate;
        }
        else if (e[i].hrsWorked > 40 && e[i].hrsWorked <= 50)
        {
            e[i].grossPay = (40 * e[i].payRate) + (e[i].hrsWorked - 40) * (e[i].payRate * 2);
        }
        else
        {
            e[i].grossPay = (40 * e[i].payRate) +
                (10 * e[i].payRate * 2) +
                (e[i].hrsWorked - 50) * (e[i].payRate * 3);
        }
    }
}