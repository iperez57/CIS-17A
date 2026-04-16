/*
 * File:   Drink_Machine_Simulator
 * Author: Isaac Perez
 * Created: 04/16/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>

using namespace std;

//User Libraries
struct VendingMachine
{
    string name;
    int cost;
    int numOfDrink;

};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void display(VendingMachine drinks[]);
void selection(string choice, VendingMachine drinks[]);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    string choice;
    //Initialize all known variables
    VendingMachine drinks[5];
    drinks[0].name = "Cola";
    drinks[0].cost = 75;
    drinks[0].numOfDrink = 20;

    drinks[1].name = "Root Beer";
    drinks[1].cost = 75;
    drinks[1].numOfDrink = 20;

    drinks[2].name = "Lemon-Lime";
    drinks[2].cost = 75;
    drinks[2].numOfDrink = 20;

    drinks[3].name = "Grape Soda";
    drinks[3].cost = 80;
    drinks[3].numOfDrink = 20;

    drinks[4].name = "Cream Soda";
    drinks[4].cost = 80;
    drinks[4].numOfDrink = 20;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    while (true)
    {
        display(drinks);
        cin >> choice;

        if (choice == "Quit" || choice == "quit" ||
            choice == "q" || choice == "Q")
        {
            break;
        }

        selection(choice, drinks);
    }

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void display(VendingMachine drinks[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(11) << drinks[i].name << setw(4) << drinks[i].cost << drinks[i].numOfDrink << endl;
    }
    cout << "Quit" << endl;
}

void selection(string choice, VendingMachine drinks[])
{
    int payment = 0;
    int change;
    int more;
    int index;
    if (choice == "Cola" || choice == "cola") index = 0;
    else if (choice == "Root Beer" || choice == "root beer") index = 1;
    else if (choice == "Lemon-Lime" || choice == "lemon-lime") index = 2;
    else if (choice == "Grape Soda" || choice == "grape soda") index = 3;
    else if (choice == "Cream Soda" || choice == "cream soda") index = 4;
    else return;

    if (drinks[index].numOfDrink > 0)
    {
        cin >> payment;
        while (payment <= 0 || payment > 100)
        {
            cin >> payment;
        }
    
        while (payment < drinks[index].cost)
        {
            cin >> more;
            while (more <= 0 || more > 100)
            {
                cin >> more;
            }
            payment += more;
        }
    
        change = payment - drinks[index].cost;
        drinks[index].numOfDrink--;
        cout << change << endl;
    }
    else
    {
        cout << "Out of stock" << endl;
    }
}