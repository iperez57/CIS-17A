/*
 * File:   Gaddis_8thEd_Chap13_Prob4_Personal_Information.cpp
 * Author: Isaac Perez
 * Created: 05/14/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
class PersonalData
{
private:
    string name;
    string address;
    int age;
    int phoneNumber;
public:
    string getName();
    void setName(string);

    string getAddress();
    void setAddress(string);

    int getAge();
    void setAge(int);

    int getPhoneNumber();
    void setPhoneNumber(int);
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    PersonalData self;
    PersonalData buddy;
    PersonalData brother;

    //Initialize all known variables
    self.setName("Frank");
    cout << self.getName() << endl;
    self.setAddress("123 cool way");
    cout << self.getAddress() << endl;
    self.setAge(21);
    cout << self.getAge() << endl;
    self.setPhoneNumber(9889991100);
    cout << self.getPhoneNumber() << endl;

    buddy.setName("Joe");
    cout << buddy.getName() << endl;
    buddy.setAddress("12332 cool way");
    cout << buddy.getAddress() << endl;
    buddy.setAge(28);
    cout << buddy.getAge() << endl;
    buddy.setPhoneNumber(1118889999);
    cout << buddy.getPhoneNumber() << endl;

    brother.setName("Jeff");
    cout << brother.getName() << endl;
    brother.setAddress("123 cool way");
    cout << brother.getAddress() << endl;
    brother.setAge(17);
    cout << brother.getAge() << endl;
    brother.setPhoneNumber(1111111111);
    cout << brother.getPhoneNumber() << endl;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
string PersonalData::getName()
{
    return name;
}
void PersonalData::setName(string n)
{
    name = n;
}

string PersonalData::getAddress()
{
    return address;
}
void PersonalData::setAddress(string a)
{
    address = a;
}

int PersonalData::getAge()
{
    return age;
}

void PersonalData::setAge(int i)
{
    age = i;
}

int PersonalData::getPhoneNumber()
{
    return phoneNumber;
}

void PersonalData::setPhoneNumber(int i)
{
    phoneNumber = i;
}