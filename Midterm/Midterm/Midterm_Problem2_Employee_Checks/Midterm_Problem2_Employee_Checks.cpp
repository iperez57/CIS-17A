/*
 * File:   Midterm_Problem2_Employee_Checks
 * Author: Isaac Perez
 * Created: 04/21/2026
 * Purpose:  use a structure
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries
struct Employee
{
    string name;
    float hrsWorked;
    float payRate;
    float grossPay;
    string grossPayWord;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getData(Employee*, const int);
void calculatePay(Employee*, const int);
string numberToWords(float);
void displayCheck(Employee*, const int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int numOfEmp;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "How many employees? ";
    cin >> numOfEmp;

    Employee* e = new Employee[numOfEmp];

    getData(e, numOfEmp);
    calculatePay(e, numOfEmp);
    displayCheck(e, numOfEmp);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    delete[] e;
    return 0;
}

//Function Implementations
void getData(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {
        cout << endl;
        cout << "Employee #" << i + 1 << endl;
        cout << "Name: ";
        getline(cin >> ws, e[i].name);
        cout << "Hours worked: ";
        cin >> e[i].hrsWorked;
        cout << "Pay rate: $";
        cin >> e[i].payRate;

    }
}

void calculatePay(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {
        if (e[i].hrsWorked <= 40)
        {
            e[i].grossPay = e[i].hrsWorked * e[i].payRate;
        }
        else if (e[i].hrsWorked > 40 && e[i].hrsWorked <= 50)
        {
            e[i].grossPay = (40 * e[i].payRate) + (e[i].hrsWorked - 40) * (e[i].payRate * 2);
        }
        else
        {
            e[i].grossPay = (40 * e[i].payRate) +
                (10 * e[i].payRate * 2) +
                (e[i].hrsWorked - 50) * (e[i].payRate * 3);
        }
    }
}

string numberToWords(float n2Cnvrt)
{
    string result = "";

    if (n2Cnvrt >= 1 && n2Cnvrt <= 9999)
    {

        int n = (int)n2Cnvrt;
        //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s, n100s, n10s, n1s;
        n1000s = n / 1000;   //Shift 3 places to the left
        n100s = n % 1000 / 100;//Remainder of division of 1000 then shift 2 left
        n10s = n % 100 / 10;   //Remainder of division of 100 then shift 1 left
        n1s = n % 10;        //Remainder of division by 10

        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch (n1000s) {
        case 9: result += "Nine thousand "; break;
        case 8: result += "Eight thousand "; break;
        case 7: result += "Seven thousand "; break;
        case 6: result += "Six thousand "; break;
        case 5: result += "Five thousand "; break;
        case 4: result += "Four thousand "; break;
        case 3: result += "Three thousand "; break;
        case 2: result += "Two thousand "; break;
        case 1: result += "One thousand "; break;
        }

        //Output the number of 100's
        //Using the Ternary Operator
        result += (n100s == 9 ? "nine hundred " :
            n100s == 8 ? "eight hundred " :
            n100s == 7 ? "seven hundred " :
            n100s == 6 ? "six hundred " :
            n100s == 5 ? "five hundred " :
            n100s == 4 ? "four hundred " :
            n100s == 3 ? "three hundred " :
            n100s == 2 ? "two hundred " :
            n100s == 1 ? "one hundred " : "");

        //Output the number of 10's
        //Using Independent If Statements
        if (n10s == 1)
        {
            if (n1s == 0) result += "ten ";
            else if (n1s == 1) result += "eleven ";
            else if (n1s == 2) result += "twelve ";
            else if (n1s == 3) result += "thirteen ";
            else if (n1s == 4) result += "fourteen ";
            else if (n1s == 5) result += "fifteen ";
            else if (n1s == 6) result += "sixteen ";
            else if (n1s == 7) result += "seventeen ";
            else if (n1s == 8) result += "eighteen ";
            else if (n1s == 9) result += "nineteen ";
        }
        //Output the number of 10's
        //Using Independent If Statements
        else
        {
            if (n10s == 9) result += "ninety ";
            if (n10s == 8) result += "eighty ";
            if (n10s == 7) result += "seventy ";
            if (n10s == 6) result += "sixty ";
            if (n10s == 5) result += "fifty ";
            if (n10s == 4) result += "forty ";
            if (n10s == 3) result += "thirty ";
            if (n10s == 2) result += "twenty ";
        }

        //Output the number of 1's
        //Using Dependent If Statements
        if (n1s == 9) result += "nine ";
        else if (n1s == 8) result += "eight ";
        else if (n1s == 7) result += "seven ";
        else if (n1s == 6) result += "six ";
        else if (n1s == 5) result += "five ";
        else if (n1s == 4) result += "four ";
        else if (n1s == 3) result += "three ";
        else if (n1s == 2) result += "two ";
        else if (n1s == 1) result += "one ";
    }
    return result;
}

void displayCheck(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {

        e[i].grossPayWord = numberToWords(e[i].grossPay);
        int dollars = (int)e[i].grossPay;
        int cents = (int)((e[i].grossPay - dollars) * 100);
        cout << endl;
        cout << "Best Company" << endl;
        cout << "123 Best Way Dr " << endl;
        cout << "Best City, CA, 13012" << endl;
        cout << "Name: " << e[i].name << " Amount: $" << e[i].grossPay << endl;
        cout << "Amount: " << e[i].grossPayWord << "& " << cents << "/100" << endl;
        cout << "Signature Line: ____________________________" << endl;
    }
}