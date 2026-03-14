/*
 * File:   Fill_Even_Odd_vectors_to_2D_array.cpp
 * Author: Isaac Perez
 * Created: 03/09/2026
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

 //System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int>&, vector<int>&);
void copy(vector<int>, vector<int>, int[][COLMAX]);
void prntVec(vector<int>, vector<int>, int);//int n is the format setw(n)
void prntAry(const int[][COLMAX], int, int, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0), odd(0); //Declare even,odd vectors

    //Input data and place even in one vector odd in the other
    read(even, odd);

    //Now output the content of the vectors
    //          setw(10)
    prntVec(even, odd, 10);//Input even, odd vectors with setw(10);

    //Copy the vectors into the 2 dimensional array
    copy(even, odd, array);

    //Now output the content of the array
    //                              setw(10)
    prntAry(array, even.size(), odd.size(), 10);//Same format as even/odd vectors

    //Exit
    return 0;
}

void read(vector<int> &even , vector<int> &odd)
{
    int amountInt;
    int valueInt;
    cout << "Input the number of integers to input." << endl;
	cin >> amountInt;
    cout << "Input each number." << endl;
    for (int i = 0; i < amountInt; i++)
    {
		cin >> valueInt;
        if (valueInt % 2 == 0)
        {
			even.push_back(valueInt);
        }
        else
        {
		    odd.push_back(valueInt);
        }
    }

}
void copy(vector<int> even, vector<int> odd, int array[][COLMAX])
{
    int maxSize = even.size() > odd.size() ? even.size() : odd.size();
    
    for (int i = 0; i < maxSize; i++)
    {
        if (i < even.size())
            array[i][0] = even[i];
        else array[i][0] = 0;

        if (i < odd.size())
            array[i][1] = odd[i];
        else array[i][1] = 0;
    }
}

void prntVec(vector<int> even, vector<int> odd, int n)
{
    cout << "    Vector      Even       Odd" << endl;
    for (int i = 0; i < even.size() || i < odd.size(); i++)
    {
        
        if (i < even.size())
        {
            cout << setw(n*2) << even[i];
        }
        else
        {
            cout << setw(n*2) << " ";
        }
        if (i < odd.size())
        {
            cout << setw(n) << odd[i];
        }
        else
        {
            cout << setw(n) << " ";
        }
        cout << endl;
	}
}

void prntAry(const int array[][COLMAX], int evenSize, int oddSize, int n)
{
    cout << "     Array      Even       Odd" << endl;

    int maxSize = evenSize > oddSize ? evenSize : oddSize;

    for (int i = 0; i < maxSize; i++)
    {
        if (i < evenSize)
            cout << setw(n * 2) << array[i][0];
        else
            cout << setw(n * 2) << " ";

        if (i < oddSize)
            cout << setw(n) << array[i][1];
        else
            cout << setw(n) << " ";
        cout << endl;
    }
}