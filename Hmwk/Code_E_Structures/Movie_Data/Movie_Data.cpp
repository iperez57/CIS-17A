/*
 * File:   Movie_Data
 * Author: Isaac Perez
 * Created: 04/17/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries
struct MovieData
{
    string Title;
    string Director;
    int yrReleased;
    int rnTime;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
MovieData* getData(int arySize);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int arySize;
    MovieData* movies;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cin >> arySize;
    movies = getData(arySize);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    delete[] movies;
    return 0;
}

//Function Implementations
MovieData* getData(int arySize)
{
    MovieData* aryMovie = new MovieData[arySize];
    for (int i = 0; i < arySize; i++)
    {

        getline(cin >> ws, aryMovie[i].Title);
        getline(cin >> ws, aryMovie[i].Director);
        cin >> aryMovie[i].yrReleased;
        cin >> aryMovie[i].rnTime;
    }

    return aryMovie;
}