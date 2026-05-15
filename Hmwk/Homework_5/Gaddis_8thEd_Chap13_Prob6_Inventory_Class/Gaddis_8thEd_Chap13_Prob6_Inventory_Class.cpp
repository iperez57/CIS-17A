/*
 * File:   Gaddis_8thEd_Chap13_Prob6_Iventory_Class.cpp
 * Author: Isaac Perez
 * Created: 05/14/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries
class Inventory
{
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
public:
    Inventory();
    Inventory(int, int);
    void setItemNumber(int);
    void setQuantity(int);
    void setCost(double);
    void setTotalCost(double);
    int getItemNumber();
    int getQuantity();
    double getCost();
    double getTotalCost();
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
//Constructor
Inventory::Inventory()
{
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int i, int q)
{
    itemNumber = i;
    quantity = q;
    //setTotalCost()
}

//setters
void Inventory::setItemNumber(int i)
{
    itemNumber = i;
}

void Inventory::setCost(double c)
{
    cost = c;
}

void Inventory::setQuantity(int q)
{
    quantity = q;
}

void Inventory::setTotalCost(double tc)
{
    tc = quantity * cost;
}

//getters
int Inventory::getItemNumber()
{
    return itemNumber;
}

int Inventory::getQuantity()
{
    return quantity;
}

double Inventory::getCost()
{
    return cost;
}

double Inventory::getTotalCost()
{
    return totalCost;
}