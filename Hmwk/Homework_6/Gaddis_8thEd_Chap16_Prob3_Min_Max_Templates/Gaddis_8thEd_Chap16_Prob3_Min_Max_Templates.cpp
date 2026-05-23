/*
 * File:   Gaddis_8thEd_Chap16_Prob3_Min_Max_Templates.cpp
 * Author: Isaac Perez
 * Created: 05/23/2026
 * Purpose:  use class templates
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
template <class T>
T maximum(T a, T b)
{
    if (a < b)
    {
        return b;
    }
    else return a;
}

template <class T>
T minimum(T a, T b)
{
    if (b < a)
    {
        return b;
    }
    else return a;
}
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Max of 3 and 7: " << maximum(3, 7) << endl;
    cout << "Min of 3 and 7: " << minimum(3, 7) << endl;

    cout << "Max of 4.5 and 2.1: " << maximum(4.5, 2.1) << endl;
    cout << "Min of 4.5 and 2.1: " << minimum(4.5, 2.1) << endl;

    cout << "Max of 'A' and 'Z': " << maximum('A', 'Z') << endl;
    cout << "Min of 'A' and 'Z': " << minimum('A', 'Z') << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
