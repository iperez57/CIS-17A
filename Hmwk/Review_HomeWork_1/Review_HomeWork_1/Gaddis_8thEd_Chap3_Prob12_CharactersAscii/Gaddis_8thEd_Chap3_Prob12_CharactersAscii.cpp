/*
* File Name: Gaddis_8thEd_Chap3_Prob12_CharactersAscii
* Author: Isaac Perez
* Created: 03/14/2026
* Purpose: Display characters Ascii
*/

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    char letter;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Enter a letter: ";
    cin >> letter;

    cout << "The ASCII character for " << letter << " is " << int(letter);
   
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations