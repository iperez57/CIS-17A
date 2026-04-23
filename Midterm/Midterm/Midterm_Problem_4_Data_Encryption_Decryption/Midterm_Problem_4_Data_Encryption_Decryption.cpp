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
void encrypt();
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
            encrypt();
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
void encrypt()
{
    int num;
    const int size = 4;
    int digit[size];
    cout << "Enter a 4-digit number to encrypt (only use numbers 0-7): ";
    cin >> num;

    digit[0] = num / 1000;
    digit[1] = (num / 100) % 10;
    digit[2] = (num / 10) % 10;
    digit[3] = num % 10;

    for (int i = 0; i < size; i++)
    {
        if (digit[i] > 7)
        {
            cout << "digits must be 0-7 only" << endl;
            return;
        }
    }

    for (int i = 0; i < size; i++)
    {
        digit[i] = (digit[i] + 3) % 8;
    }

    swap(digit[0], digit[2]);
    swap(digit[1], digit[3]);

    cout << "Encrypted: ";
    for (int i = 0; i < size; i++)
    {
        cout << digit[i];
    }
    cout << endl;
}