/*
 * File:    Gaddis_8thEd_Chap12_Prob11_Corporate_Sales_Data_Input.cpp
 * Author: Isaac Perez
 * Created: 04/18/2026
 * Purpose:  structure to binary file
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

//User Libraries
struct CompanyDiv
{
    char name[10];
    float q1;
    float q2;
    float q3;
    float q4;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getSales(CompanyDiv div[], string names[], int size);
void writeFile(CompanyDiv div[], int size);
void readFile(CompanyDiv div[], int size);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    CompanyDiv div[4];
    string names[4] = { "North", "West", "East", "South" };
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    getSales(div, names, 4);
    writeFile(div, 4);
    readFile(div, 4);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void getSales(CompanyDiv div[], string names[], int size)
{
    for (int i = 0; i < size; i++)
    {
        strcpy_s(div[i].name, names[i].c_str());

        cout << div[i].name << endl;

        cout << "Enter first-quarter sales: ";
        cin >> div[i].q1;
        while (div[i].q1 < 0)
        {
            cout << "Invalid enter again: ";
            cin >> div[i].q1;
        }

        cout << "Enter second-quarter sales: ";
        cin >> div[i].q2;
        while (div[i].q2 < 0)
        {
            cout << "Invalid enter again: ";
            cin >> div[i].q2;
        }

        cout << "Enter third-quarter sales: ";
        cin >> div[i].q3;
        while (div[i].q3 < 0)
        {
            cout << "Invalid enter again: ";
            cin >> div[i].q3;
        }

        cout << "Enter fourth-quarter sales: ";
        cin >> div[i].q4;
        while (div[i].q4 < 0)
        {
            cout << "Invalid enter again: ";
            cin >> div[i].q4;
        }


        if (i < size - 1)
            cout << endl;
    }
}

void writeFile(CompanyDiv div[], int size)
{
    ofstream out("sales.bin", ios::binary);

    if (!out)
    {
        cout << "Error opening file\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        out.write(reinterpret_cast<char*>(&div[i]), sizeof(CompanyDiv));
    }

    out.close();
}
void readFile(CompanyDiv div[], int size)
{
    ifstream in("sales.bin", ios::binary);

    if (!in)
    {
        cout << "Error opening file" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        in.read(reinterpret_cast<char*>(&div[i]), sizeof(CompanyDiv));
    }
    in.close();
}
