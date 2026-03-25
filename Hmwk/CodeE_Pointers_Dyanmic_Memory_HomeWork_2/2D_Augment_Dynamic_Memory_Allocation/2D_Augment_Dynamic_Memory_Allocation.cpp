/*
 * File:   2D_Augment_Dynamic_Memory_Allocation
 * Author: Isaac Perez
 * Created: 03/22/2026
 * Purpose: Augment a 2D array
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
int** augment(const int* const*, int, int);
void destroy(int**, int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int** ary;
    int** augAry;
    int row;
    int col;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> row;
    cin >> col;
    ary = getData(row, col);
    prntData(ary, row, col);
    cout << endl;
    augAry = augment(ary, row, col);
    prntData(augAry, row + 1, col + 1);
    destroy(augAry, row + 1);
    destroy(ary, row);
    //Clean up the code, close files, deallocate memory, etc....

    //Exit stage right
    return 0;
}

//Function Implementations

int** getData(int& rows, int& cols)
{
    int** array = new int* [rows];

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

void prntData(const int* const* ary2D, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ary2D[i][j];
            if (j != cols - 1)
                cout << " ";
        }
        cout << endl;
    }
}

int** augment(const int* const* ary, int row, int col)
{
    int** augArry = new int* [row + 1];
    int iIndx = 0;
    int jIndx = 1;

    
    for (int i = 0; i < row; i++)
    {
        augArry[i] = new int[col + 1];
        for (int j = 0; j < col; j++)
        {
            augArry[iIndx][jIndx] = ary[i][j];
            jIndx++;
        }
        jIndx = 1;
        iIndx++;
    }
    augArry[0][0] = 0;
    augArry[1][0] = 0;
    
    return augArry;
}

void destroy(int** ary, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[]ary[i];
    }
    delete[]ary;
}