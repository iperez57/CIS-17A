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
void prntData(int*, int);    //Print the integer array
float* median(int*, int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float*);     //Print the median Array

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int arySize;
    int* ary;
    float* medAry;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> arySize;
    ary = getData(arySize);
    prntData(ary, arySize);
    medAry = median(ary, arySize);
    //Clean up the code, close files, deallocate memory, etc....
    delete[]ary;
    delete[]medAry;
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

void prntData(int* ary, int arySize)
{
    for (int i = 0; i < arySize; i++)
    {
        cout << *(ary + i);
        if (i != arySize - 1)
            cout << " ";
    }
    cout << endl;

}

float* median(int* ary, int size)
{
    float med;
    float* medAry = new float[size + 2];
    int medSize = size;
    int firstNum;
    int secNum;
    if ((medSize % 2) == 0)
    {
        firstNum = (medSize / 2) - 1;
        secNum = (medSize / 2);
        med = (ary[firstNum] + ary[secNum]) / 2.0f;
    }
    else
        med = ary[medSize / 2];
    medAry[0] = medSize + 2;
    medAry[1] = med;

    int index = 2;
    for (int i = 0; i < medSize; i++)
    {
        medAry[index] = ary[i];
        index++;
    }
    return medAry;
    
}