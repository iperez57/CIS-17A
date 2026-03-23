/*
 * File:   2D_Sum_Dynamic_Memory_Allocation
 * Author: Isaac Perez
 * Created: 03/22/2026
 * Purpose:  2D sum of an array
 */

 //System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int** getData(int&, int&);
void prntData(const int* const*, int, int);
void destroy(int**, int, int);
int sum(const int* const*, int, int);


//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int row;
    int col; 
    int** ary2D;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> row;
    cin >> col;
    ary2D = getData(row, col);
    //Clean up the code, close files, deallocate memory, etc....

    //Exit stage right
    return 0;
}

//Function Implementations
int** getData(int& rows, int& cols)
{
    int** array = new int*[rows];

    for (int i = 0;i < rows;i++) 
    {
        array[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }
    return array;
}