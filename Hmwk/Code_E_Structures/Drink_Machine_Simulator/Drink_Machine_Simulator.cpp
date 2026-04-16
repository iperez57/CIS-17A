/*
 * File:   Drink_Machine_Simulator
 * Author: Isaac Perez
 * Created: 04/16/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
struct SoftDrink
{
    string name;
    float cost;
    int numOfDrink;

};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void display(SoftDrink drinks[]);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    SoftDrink drinks[5];
    drinks[0].name = "Cola";
    drinks[0].cost = .75;
    drinks[0].numOfDrink = 20;

    drinks[1].name = "Root Beer";
    drinks[1].cost = .75;
    drinks[1].numOfDrink = 20;

    drinks[2].name = "Lemon-Lime";
    drinks[2].cost = .75;
    drinks[2].numOfDrink = 20;

    drinks[3].name = "Grape Soda";
    drinks[3].cost = .80;
    drinks[3].numOfDrink = 20;

    drinks[4].name = "Cream Soda";
    drinks[4].cost = .80;
    drinks[4].numOfDrink = 20;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    void display(SoftDrink drinks[5]);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
