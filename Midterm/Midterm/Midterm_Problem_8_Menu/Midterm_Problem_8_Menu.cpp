/*
 * File:   Midterm_Problem_8_Menu
 * Author: Isaac Perez
 * Created: 04/27/2026
 * Purpose:  Menu selection
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void displayMenu();
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int menuSelect;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    displayMenu();
    cin >> menuSelect;
    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void displayMenu()
{
    cout << "1. Problem 1 Financial Tracker" << endl;
    cout << "2. Problem 2 Employee Checks" << endl;
    cout << "3. Problem 3 Mean Median Mode" << endl;
    cout << "4. Problem 4 Data Encryption" << endl;
    cout << "5. Problem 5 Exploration of Data Types" << endl;
    cout << "6. Problem 6 NASA conversion" << endl;
    cout << "7. Problem 7 Prime Numbers" << endl;

}
