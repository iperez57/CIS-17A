/*
 * File:   Gaddis_8thEd_Chap14_Prob1_Numbers_Class.cpp
 * Author: Isaac Perez
 * Created: 05/15/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries
class Numbers
{
private:
    int number;

    static string lessThan20[20];
    static string tens[8]; 
    static string hundred;
    static string thousand;

public:
    Numbers(int);
    void print();
};
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
   
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
string Numbers::lessThan20[20] =
{
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[8] =
{
    "twenty", "thirty", "forty", "fifty",
    "sixty" , "seventy", "eighty", "ninety"
};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";