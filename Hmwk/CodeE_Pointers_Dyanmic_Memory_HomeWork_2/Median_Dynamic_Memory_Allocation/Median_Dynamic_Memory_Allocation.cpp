/*
 * File:   Median_Dynamic_Memory_Allocation
 * Author: Isaac Perez
 * Created: 03/18/2026
 * Purpose:  Find the median 
 */

 //System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int* getData(int&);         //Return the array size and the array
void prntDat(int*, int);    //Print the integer array
float* median(int*, int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float*);     //Print the median Array

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
    delete[]ary;
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