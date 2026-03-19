/*
 * File:   Reverse_Dynamic_Memory_Allocation
 * Author: Isaac Perez
 * Created: 03/19/2026
 * Purpose:  Reverse the array
 */

 //System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int* getData(int&);
int* sort(const int*, int);
int* reverse(const int*, int);
void prntData(const int*, int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int arySize;
    int* ary;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> arySize;
    ary = getData(arySize);
    //Clean up the code, close files, deallocate memory, etc....

    //Exit stage right
    return 0;
}

//Function Implementations
int* getData(int& arySize)
{
    int* array = new int[arySize];

    for (int i = 0; i < arySize; i++)
    {
        cin >> array[i];
    }
    return array;
}
