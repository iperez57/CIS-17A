/*
 * File:   Midterm_Problem_4_Data_Encryption_Decryption
 * Author: Isaac Perez
 * Created: 04/23/2026
 * Purpose:  swap array
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void menu();
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int option;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    do
    {
        menu();
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Encrypt";
            break;
        case 2:
            cout << "Decrypt";
            break;
        default:
            cout << "Invalid option. Try again" << endl;

        }
    } while (option != 0);
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void menu()
{
    cout << "Menu" << endl;
    cout << "1. Encrypt Data" << endl;
    cout << "2. Decrypt Data" << endl;
}
