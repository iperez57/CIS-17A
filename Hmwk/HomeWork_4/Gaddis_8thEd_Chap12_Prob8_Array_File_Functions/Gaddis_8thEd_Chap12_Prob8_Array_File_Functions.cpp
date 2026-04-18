/*
 * File:   Gaddis_8thEd_Chap12_Prob8_Array_File_Functions
 * Author: Isaac Perez
 * Created: 04/18/2026
 * Purpose:  read and write binary files
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <cctype>

using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void arrayToFile(string, int* , int);
void fileToArray(string, int* , int);
int* fillAry(const int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    string name;
    const int arySize = 5;
    int* ary;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    ary = fillAry(arySize);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    delete[] ary;
    return 0;
}

//Function Implementations
void arrayToFile(string fileName, int* ary, int arySize)
{

}

void fileToArray(string fileName, int* ary, int arySize)
{

}

int* fillAry(const int arySize)
{
    int* array = new int[arySize];
    for (int i = 0; i < arySize; i++)
    {
        array[i] = i;
    }
    return array;
}