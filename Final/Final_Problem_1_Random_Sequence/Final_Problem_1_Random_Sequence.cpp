/*
 * File:   Final_Problem_1_Random_Sequence
 * Author: Isaac Perez
 * Created: 06/7/2026
 * Purpose:  Use a class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries
#include "Prob1Random.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    char n = 5;
    char rndseq[] = { 19,34,57,79,126 };
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    for (int i = 1;i <= ntimes;i++) 
    {
            a.randFromSet();
    }
    int* x = a.getFreq();
    char* y = a.getSet();
    for (int i = 0;i < n;i++) {
        cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations