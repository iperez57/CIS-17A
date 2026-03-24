/*
 * File:   1D_Augment_Dynamic_Memory_Allocation
 * Author: Isaac Perez
 * Created: 03/22/2026
 * Purpose: Augment a 1D array
 */

 //System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int* getData(int&);
int* augment(const int*, int);
void prntAry(const int*, int);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int arySize;
    int* ary;
    int* augArry;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> arySize;
    ary = getData(arySize);

    prntAry(ary, arySize);
    cout << endl;
    augArry = augment(ary, arySize);
    prntAry(augArry, arySize + 1);


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

int* augment(const int* ary, int arySize)
{
    int index = 1;
    int* augAry = new int[arySize + 1];
    augAry[0] = 0;
    for (int i = 0; i < arySize; i++)
    {
        augAry[index] = ary[i];
        index++;
    }
    return augAry;
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