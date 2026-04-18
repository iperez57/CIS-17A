/*
 * File:   Movie_Data
 * Author: Isaac Perez
 * Created: 04/17/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
#include <iomanip>

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
void displayMovieData(const MovieData* movies, int arySize);
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
    displayMovieData(movies, arySize);
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

void displayMovieData(const MovieData* movies, int arySize)
{
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl << endl;

    for (int i = 0; i < arySize; i++)
    {
        cout << left;
        cout << setw(11) << "Title:" << movies[i].Title << endl;
        cout << setw(11) << "Director:" << movies[i].Director << endl;
        cout << setw(11) << "Year:" << movies[i].yrReleased << endl;
        cout << setw(11) << "Length:" << movies[i].rnTime << endl;

        if (i != arySize - 1)
        {
            cout << endl;
        }
    }

}