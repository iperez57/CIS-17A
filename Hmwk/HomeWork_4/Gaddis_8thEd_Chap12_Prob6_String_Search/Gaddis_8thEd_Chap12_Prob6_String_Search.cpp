/*
 * File:   Gaddis_8thEd_Chap12_Prob6_String_Search
 * Author: Isaac Perez
 * Created: 04/19/2026
 * Purpose:  read files
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <string>

using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void openFile(string);
void searchFile(string&);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    string fileName = "text.txt";
    //Open text and binary files
    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    searchFile(fileName);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void searchFile(string& fileName)
{
    string searchStr;
    string line;
    int counter = 0;
    int lineNumber = 0;
    bool match;
    bool foundInLine;

    ifstream inFile(fileName);

    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }


    cout << "Enter a word to search for: ";
    cin >> searchStr;

    while (getline(inFile, line))
    {
        lineNumber++;
        foundInLine = false;

        if (line.length() >= searchStr.length())
        {
            for (int i = 0; i <= line.length() - searchStr.length(); i++)
            {
                match = true;

                for (int j = 0; j < searchStr.length(); j++)
                {
                    if (line[i + j] != searchStr[j])
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                {
                    counter++;
                    foundInLine = true;
                }
            }
        }
        if (foundInLine)
        {
            cout << "Found in line " << lineNumber << ": " << line << endl;
        }
    }
    cout << "Total occurences: " << counter << endl;
    inFile.close();
}