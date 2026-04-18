/*
 * File:   Gaddis_8thEd_Chap11_Prob9_Speakers_Bureau
 * Author: Isaac Perez
 * Created: 04/17/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
struct Speaker
{
    string name;
    string phoneNumber;
    string speakingTopic;
    float fee;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void displayMenu(Speaker speakersBureau[], int arySize);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    const int arySize = 10;
    Speaker speakersBureau[arySize];
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    displayMenu(speakersBureau, arySize);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void displayMenu(Speaker speakersBureau[], int arySize)
{
    cout << "1. Add Speaker" << endl;
    cout << "2. Edit Speaker" << endl;
    cout << "3. Display All" << endl;
    cout << "4. Exit" << endl;
}