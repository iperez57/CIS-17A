/*
 * File:   Validate_and_Reverse
 * Author: Isaac Perez
 * Created: 03/11/2026
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

 //System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

bool  inRange(const char[], unsigned short&);//Output true,unsigned or false
bool  reverse(unsigned short, signed short&);//Output true,short or false
short subtrct(signed short, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short

    //Input or initialize values Here
    cout << "Reverse a number and subtract if possible." << endl;
    cout << "Input a number in the range of an unsigned short" << endl;
    cin >> digits;

    //Test if it is in the Range of an unsigned short
    if (!inRange(digits, unShort)) {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    //Reverse and see if it falls in the range of an signed short
    if (!reverse(unShort, snShort)) {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    //Now subtract if the result is not negative else don't subtract
    snShort = subtrct(snShort, 999);

    //Output the result
    cout << snShort << endl;

    //Exit
    return 0;
}

bool inRange(const char digits[], unsigned short& unShort)
{
    for (int i = 0; digits[i] != '\0'; i++)
    {
        if (digits[i] < '0' || digits[i] > '9')
        {
            return false;
        }
    }
    int value = atoi(digits);
    if (value > 0 && value < 65535)
    {
        unShort = value;
        return true;
    }
    else
        return false;
}
bool reverse(unsigned short unShort, signed short& snShort)
{
    snShort = 0;

    while (unShort > 0)
    {
        short digit = unShort % 10;
        snShort = snShort * 10 + digit;
        unShort = unShort / 10;
    }

    if (snShort > -32768 && snShort < 32767)
    {
        return true;
    }
    else
    {
        return false;
    }

}

short subtrct(signed short snShort, int n)
{
    if (snShort < 0)
    {
        snShort = snShort - n;
    }
    return snShort;
}