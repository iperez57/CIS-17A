/*
 * File:   Gaddis_8thEd_Chap11_Prob9_Speakers_Bureau
 * Author: Isaac Perez
 * Created: 04/17/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>


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
void displayMenu();
void addSpeaker(Speaker speakersBureau[], int& counter, int arySize);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    const int arySize = 10;
    Speaker speakersBureau[arySize];
    int user;
    int counter = 0;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    while (true)
    {
        displayMenu();
        cin >> user;

        switch (user)
        {
        case 1:
            
            addSpeaker(speakersBureau, counter, arySize);
            break;
        case 2:
            cout << "Edit Speaker" << endl;
            break;
        case 3:
            cout << "Display All" << endl;
            break;
        case 4:
            return 0;
        default:
             cout << "Invalid choice" << endl;
        }
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void displayMenu()
{
    cout << "1. Add Speaker" << endl;
    cout << "2. Edit Speaker" << endl;
    cout << "3. Display All" << endl;
    cout << "4. Exit" << endl;
}

void addSpeaker(Speaker speakersBureau[], int& counter, int arySize)
{
    if (counter >= arySize)
    {
        cout << "Speaker list is full" << endl;
        return;
    }

    cout << "Enter name:" << endl;
    getline(cin >> ws, speakersBureau[counter].name);

    cout << "Enter phone number:" << endl;
    getline(cin >> ws, speakersBureau[counter].phoneNumber);

    cout << "Enter speaking topic:" << endl;
    getline(cin >> ws, speakersBureau[counter].speakingTopic);

    cout << "Enter fee required:" << endl;
    cin >> speakersBureau[counter].fee;

    counter++;
}