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
    sort(ary, arySize);
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

int* sort(const int* ary, int arySize)
{
    int* sortAry = new int[arySize];
    //copy array into sortAry
    for (int i = 0; i < arySize; i++)
    {
        sortAry[i] = ary[i];
    }

    //sort array
    for (int i = 0; i < arySize - 1; i++)
    {
        for (int j = i + 1; j < arySize; j++)
        {
            if (sortAry[i] > sortAry[j])
            {
                int temp = sortAry[j];
                sortAry[j] = sortAry[i];
                sortAry[i] = temp;
            }
        }
    }
    return sortAry;
}