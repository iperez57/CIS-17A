/*
 * File:   Midterm_Problem1_Financial_Tracker
 * Author: Isaac Perez
 * Created: 04/21/2026
 * Purpose:  use a structure
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries
struct Customer
{
    int accNum;
    string name;
    string address;
    float begBalance;
    //Dynamic Array
    float* checks;
    int checkCount;
    //Dynamic Array
    float* deposit;
    int depoCount;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getData(Customer*);
void calculateBalance(Customer*);
void displayData(Customer*);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    Customer* c = new Customer;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    getData(c);
    displayData(c);
    calculateBalance(c);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    delete[] c->checks;
    delete[] c->deposit;
    delete c;
    return 0;
}

//Function Implementations
void getData(Customer* c)
{
    do
    {
        cout << "Enter account number: ";
        cin >> c->accNum;
    } while (c->accNum < 10000 || c->accNum > 99999);

    cout << "Enter name: ";
    getline(cin >> ws, c->name);

    cout << "Enter address: ";
    getline(cin >> ws, c->address);

    cout << "Enter beginning balance: $";
    cin >> c->begBalance;

    cout << "How many checks did you write? ";
    cin >> c->checkCount;

    c->checks = new float[c->checkCount];
    for (int i = 0; i < c->checkCount; i++)
    {
        cout << "Enter amount for check " << i + 1 <<  ": $";
        cin >> c->checks[i];
    }

    cout << "How many deposits did you make? ";
    cin >> c->depoCount;

    c->deposit = new float[c->depoCount];
    for (int i = 0; i < c->depoCount; i++)
    {
        cout << "Enter amount for deposit " << i + 1 << ": $";
        cin >> c->deposit[i];
    }
}

void calculateBalance(Customer* c)
{
    float balance = c->begBalance;
    float fee = 20.00;
    
    cout << endl;
    cout << "Your balance is: $" << c->begBalance << endl;

    for (int i = 0; i < c->checkCount; i++)
    {
        balance -= c->checks[i];
    }
    //check overdraft
    if (balance < 0)
    {
        balance -= fee;
        cout << "Account overdraw $20 fee applied" << endl;
    }
    
    cout << "After checks balance comes out to $" << balance << endl;

    for (int i = 0; i < c->depoCount; i++)
    {
        balance += c->deposit[i];
    }

    cout << "After deposits balance comes out to $" << balance << endl;
}

void displayData(Customer* c)
{
    cout << endl;
    cout << "Account Number: " << c->accNum << endl;
    cout << "Name: " << c->name << endl;
    cout << "Address: " << c->address << endl;
    cout << "Beginning Balance: $" << c->begBalance << endl;
    cout << "Checks written: " << c->checkCount << endl;
    cout << "Value of checks: ";
    for (int i = 0; i < c->checkCount; i++)
    {
        cout << "$" << c->checks[i];
        if (i < c->checkCount - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Deposits made: " << c->depoCount << endl;
    cout << "Value of deposits: ";
    for (int i = 0; i < c->depoCount; i++)
    {
        cout << "$" << c->deposit[i];
        if (i < c->depoCount - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}