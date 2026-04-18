/*
 * File:   Gaddis_8thEd_Chap12_Prob7_Sentence_Filter
 * Author: Isaac Perez
 * Created: 04/18/2026
 * Purpose:  read and write to files
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <cctype>

using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getFileName(string& , string&);
void editFile(ifstream& , ofstream&);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Open text and binary files
    //Declare all variables for this function

    //Initialize all known variables
    string inFileName;
    string outFileName;
    char ch;
    bool newSentence = true;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    getFileName(inFileName, outFileName);

    ifstream inputFile(inFileName);
    ofstream outputFile(outFileName);

    if (!inputFile || !outputFile)
    {
        cout << "Error opening file" << endl;
        return 0;
    }

    editFile(inputFile, outputFile);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void getFileName(string& inFileName, string& outFileName)
{
    cout << "Enter input file name: ";
    cin >> inFileName;

    cout << "Enter output file name: ";
    cin >> outFileName;
}

void editFile(ifstream& inputFile, ofstream& outputFile)
{
    char ch;
    bool newSentence = true;

    while (inputFile.get(ch))
    {
        ch = tolower(ch);

        if (newSentence && isalpha(ch))
        {
            ch = toupper(ch);
            newSentence = false;
        }

        outputFile.put(ch);

        if (ch == '.')
        {
            newSentence = true;
        }
    }
}