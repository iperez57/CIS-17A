/*
 * File:   Gaddis_8thEd_Chap8_Prob7_SearchBenchmarks
 * Author: Isaac Perez
 * Created: 03/15/2026
 * Purpose:   search an array using linear search and binary search
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void linearSearch(int[], int, int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    int numbers[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int size = 20;
    int value = rand() % 20;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    linearSearch(numbers, size, value);



    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void linearSearch(int numbers[], int size, int value)
{
    int counter = 0;
    cout << "Linear search for value: " << value << endl;
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == value)
        {
            cout << "It took " << counter << " comparisons to find the value " << value << endl;
            break;
        }
        counter++;
    }
}