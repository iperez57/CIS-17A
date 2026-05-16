/*
 * File:   Gaddis_8thEd_Chap13_Prob2_Employee_Class.cpp
 * Author: Isaac Perez
 * Created: 05/14/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include <string>


using namespace std;

//User Libraries
class Employee
{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    //constructors
    Employee();
    Employee(string, int, string, string);
    Employee(string, int);

    //setters
    void setName(string);
    void setIdNumber(int);
    void setDepartment(string);
    void setPosition(string);

    //getters
    string getName();
    int setIdNumber();
    string setDepartment();
    string setPosition();
};

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
