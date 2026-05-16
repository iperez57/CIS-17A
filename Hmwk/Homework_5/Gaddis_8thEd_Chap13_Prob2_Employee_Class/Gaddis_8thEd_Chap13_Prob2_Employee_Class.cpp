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
    int getIdNumber();
    string getDepartment();
    string getPosition();

    //print
    void print();
};

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    Employee emp1;
    Employee emp2("Mark", 12345);
    Employee emp3("John", 45432, "IT", "Programmer");

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    emp1.print();
    emp2.print();
    emp3.print();
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

Employee::Employee(string na, int id, string dep, string pos)
{
    name = na;
    idNumber = id;
    department = dep;
    position = pos;
}

Employee::Employee(string na, int id)
{
    name = na;
    idNumber = id;
    department = "";
    position = "";
}

void Employee::setName(string na)
{
    name = na;
}

void Employee::setIdNumber(int id)
{
    idNumber = id;
}

void Employee::setDepartment(string dep)
{
    department = dep;
}

void Employee::setPosition(string pos)
{
    position = pos;
}

string Employee::getName()
{
    return name;
}

int Employee::getIdNumber()
{
    return idNumber;
}

string Employee::getDepartment()
{
    return department;
}

string Employee::getPosition()
{
    return position;
}

void Employee::print()
{
    cout << "Name" << endl;
    cout << getName() << endl;
    cout << "ID Number" << endl;
    cout << getIdNumber() << endl;
    cout << "Department" << endl;
    cout << getDepartment() << endl;
    cout << "Position" << endl;
    cout << getPosition() << endl;
}