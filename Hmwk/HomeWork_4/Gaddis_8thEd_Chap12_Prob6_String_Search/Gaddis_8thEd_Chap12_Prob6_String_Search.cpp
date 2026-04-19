/*
 * File:   Gaddis_8thEd_Chap12_Prob6_String_Search
 * Author: Isaac Perez
 * Created: 04/19/2026
 * Purpose:  read files
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>

using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void openFile(string);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    string fileName = "text.txt";
    //Open text and binary files
    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    openFile(fileName);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void openFile(string fileName)
{
    ifstream inFile(fileName);
    
    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
}