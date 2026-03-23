/*
 * File:   Sum_Dynamic_Memory_Allocation
 * Author: Isaac Perez
 * Created: 03/22/2026
 * Purpose:  Sum of an array
 */

 //System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int* getData(int&);
int* sumAry(const int*, int);
void prntAry(const int*, int);


//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int arySize;
    int* ary;
    int* sumArry;

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> arySize;
    ary = getData(arySize);
    sumArry = sumAry(ary, arySize);
    prntAry(sumArry, arySize);
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

int* sumAry(const int* ary, int arySize)
{
    int* sumAr = new int[arySize];
    int sum = 0;

    for (int i = 0; i < arySize; i++)
    {
        sum += ary[i];
        sumAr[i] = sum;
    }
    return sumAr;
}

void prntAry(const int* ary, int arySize)
{
    for (int i = 0; i < arySize; i++)
    {
        cout << *(ary + i);
        if (i != arySize - 1)
            cout << " ";
    }
}