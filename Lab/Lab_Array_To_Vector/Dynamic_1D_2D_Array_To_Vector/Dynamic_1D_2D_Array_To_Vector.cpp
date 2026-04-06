/*
 * File:   Dynamic_1D_2D_Array_To_Vector
 * Author: Isaac Perez
 * Created: 04/06/2026
 * Purpose:  Convert 1 and 2 Dimensional Dynamic Arrays to use Vectors
 */

 //System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntVctr(vector<int>& ,int);
void prntAry(int**, int, int);
void fillVctr(vector<int>&, int, int, int);
int** fillAry(int, int);
void fillAry(int**, vector<int>& , int, int);
void destroy(int**, int);
void swap(int&, int&);
void smlLst(vector<int>&, int);
void mrkSort(vector<int>&);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int rowsize = 4;//Row size for both 1 and 2 D arrays
    int colsize = 3;//The column size for a 2 dimensional Array
    vector<int>avec(rowsize);
    vector<int>bvec(rowsize);
    vector<int>cvec(rowsize);
    int** table;
    int lowRng = 100, highRng = 999;
    int perLine = 4;

    //Fill each parallel array
    fillVctr(avec, rowsize, highRng, lowRng);
    fillVctr(bvec, rowsize, highRng, lowRng);
    fillVctr(cvec, rowsize, highRng, lowRng);

    //Sort the array the for all positions
    mrkSort(avec);
    mrkSort(bvec);
    mrkSort(cvec);

    //Fill the 2-D array
    table = fillAry(rowsize, colsize);
    fillAry(table, avec, rowsize, 0);
    fillAry(table, bvec, rowsize, 1);
    fillAry(table, cvec, rowsize, 2);

    //Print the values in the array
    prntVctr(avec, perLine);
    prntVctr(bvec, perLine);
    prntVctr(cvec, perLine);
    prntAry(table, rowsize, colsize);

    //Cleanup
    delete[]array;
    delete[]brray;
    delete[]crray;
    destroy(table, rowsize);

    //Exit
    return 0;
}

void destroy(int** a, int rows) {
    for (int row = 0;row < rows;row++) {
        delete[]a[row];
    }
    delete[]a;
}

void fillAry(int** a, vector<int>& c, int rowSize, int wchCol) 
{
    for (int row = 0;row < rowSize;row++) 
    {
        a[row][wchCol] = c[row];
    }
}

void fillVctr(vector<int>& a,int n, int hr, int lr) {
    for (int indx = 0;indx < a.size();indx++) {
        a[indx] = rand() % (hr - lr + 1) + lr;
    }
}

int** fillAry(int rows, int cols) {
    //Allocate Memory for 2-D Array
    rows = rows < 2 ? 2 : rows;
    cols = cols < 2 ? 2 : cols;
    int** a = new int* [rows];
    for (int row = 0;row < rows;row++) {
        a[row] = new int[cols];
    }
    //Fill it with 0's
    for (int row = 0;row < rows;row++) {
        for (int col = 0;col < cols;col++) {
            a[row][col] = 0;
        }
    }
    return a;
}

void prntAry(int** a, int rowsize, int colsize) {
    cout << endl << "The Array Values" << endl;
    for (int row = 0;row < rowsize;row++) {
        for (int col = 0;col < colsize;col++) {
            cout << setw(4) << a[row][col];
        }
        cout << endl;
    }
}

void prntVctr(vector<int>& a, int perLine) 
{
    //Print the values in the array
    cout << endl << "The Vector Values" << endl;
    for (int indx = 0;indx < a.size();indx++) 
    {
        cout << a[indx] << " ";
        if (indx % perLine == (perLine - 1))cout << endl;
    }
    cout << endl;
}

void mrkSort(vector<int>& a) 
{
    for (int pos = 0;pos < a.size() - 1;pos++)
    {
        smlLst(a, pos);
    }
}

void smlLst(vector<int>& a, int pos) {
    for (int i = pos + 1;i < a.size();i++) {
        if (a[pos] > a[i]) {
            swap(a[pos], a[i]);
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}