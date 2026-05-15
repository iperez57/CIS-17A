/*
 * File:   Gaddis_8thEd_Chap14_Prob1_Numbers_Class.cpp
 * Author: Isaac Perez
 * Created: 05/15/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries
class Numbers
{
private:
    int number;

    static string lessThan20[20];
    static string tens[10]; 
    static string hundred;
    static string thousand;

public:
    Numbers(int);
    void print();
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    int user;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "enter a number between 0-9999" << endl;

    do
    {
        cin >> user;
        if (user > 9999 || user < 0)
        {
            cout << "try again" << endl;
        }
    } while (user > 9999 || user < 0);

    Numbers num(user);
    num.print();
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
string Numbers::lessThan20[20] =
{
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[10] =
{
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty" , "seventy", "eighty", "ninety"
};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers(int user)
{
    number = user;
}

void Numbers::print()
{
    int n = number;
    int n1000s, n100s, n10s, n1s;
    n1000s = n / 1000;
    n100s = n % 1000 / 100;
    n10s = n % 100 / 10;
    n1s = n % 10;
    int lastTwo = n % 100;

    if (n1000s > 0)
    {
        cout << lessThan20[n1000s] << " " << thousand << " ";
    }
    if (n100s > 0)
    {
        cout << lessThan20[n100s] << " " << hundred << " ";
    }
    if (lastTwo < 20 && lastTwo > 0)
    {
        cout << lessThan20[lastTwo];
    }
    else
    {
        if (n10s > 0)
        {
            cout << tens[n10s] << " ";
        }
        if (n1s > 0)
        {
            cout << lessThan20[n1s];
        }
    }

}