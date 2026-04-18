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
void displaySpeakers(Speaker speaksersBureau[], int& counter);
void editSpeaker(Speaker speakersBureau[], int& counter);
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
            cout << "Edit speaker:" << endl;
            editSpeaker(speakersBureau, counter);
            break;
        case 3:
            cout << "List of speakers" << endl;
            displaySpeakers(speakersBureau,counter);
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

void displaySpeakers(Speaker speaksersBureau[], int& counter)
{
    if (counter == 0)
    {
        cout << "No speakers entered" << endl;
    }
    
    for (int i = 0; i < counter; i++)
    {
        cout << i + 1 << endl;
        cout << "Speaker Name: " << speaksersBureau[i].name << endl;
        cout << "Phone Number: " << speaksersBureau[i].phoneNumber << endl;
        cout << "Speaking Topic: " << speaksersBureau[i].speakingTopic << endl;
        cout << "Fee: " << speaksersBureau[i].fee << endl;

    }
}

void editSpeaker(Speaker speakersBureau[], int& counter)
{
    int spkEdit;
    int choice;

    if (counter == 0)
    {
        cout << "No speakers to edit" << endl;
        return;
    }

    displaySpeakers(speakersBureau, counter);

    cout << "What speaker would you like to edit: ";
    cin >> spkEdit;
    
    spkEdit--;

    if (spkEdit < 0 || spkEdit >= counter)
    {
        cout << "Invalid selection" << endl;
        return;
    }

    cout << "What would you like to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Phone Number" << endl;
    cout << "3. Speaking Topic" << endl;
    cout << "4. Fee" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter new name: ";
        getline(cin >> ws, speakersBureau[spkEdit].name);
        break;
    case 2:
        cout << "Enter new phone number: ";
        getline(cin >> ws, speakersBureau[spkEdit].phoneNumber);
        break;
    case 3:
        cout << "Enter new speaking topic: ";
        getline(cin >> ws, speakersBureau[spkEdit].speakingTopic);
        break;
    case 4:
        cout << "Enter new fee: ";
        cin >> speakersBureau[spkEdit].fee;
        break;
    default:
        cout << "Invalid choice." << endl;
    }
}