/*
 * File:   Gaddis_8thEd_Chap5_Prob11_PredictPopulation
 * Author: Isaac Perez
 * Created: 03/15/2026
 * Purpose:  Predict the size of an organisms population.
 */

 //System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
double orgPopulation(int, double, int);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int stOrg;
    double incOrg;
    int days;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "What is the starting number of organisms (n>2): ";
    cin >> stOrg;
    while (stOrg < 2)
    {
        cout << "Starting organism less than 2";
        return 0;
    }
    
    cout << "What is the average daily population increase(percentage): %";
    cin >> incOrg;
    while (incOrg < 0)
    {
        cout << "Daily population increase less than 0";
        return 0;
    }
    cout << "How many days will they multiply: ";
    cin >> days;
    while (days < 1)
    {
        cout << "Days not greater than 1";
        return 0;
    }
    orgPopulation(stOrg, incOrg, days);


    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
double orgPopulation(int stOrg, double incOrg, int days)
{

}