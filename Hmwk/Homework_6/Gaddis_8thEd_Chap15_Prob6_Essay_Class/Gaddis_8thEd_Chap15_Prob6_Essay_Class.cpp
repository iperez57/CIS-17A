/*
 * File:   Gaddis_8thEd_Chap15_Prob6_Essay_Class.cpp
 * Author: Isaac Perez
 * Created: 05/22/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include "Essay.h"

using namespace std;
//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    Essay student(30, 20, 20, 30);
    Essay student2(20, 20, 10, 20);
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "John: " << student.getScore() << " " << student.getLetterGrade() << endl;
    cout << "Joe: " << student2.getScore() << " " << student2.getLetterGrade() << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
