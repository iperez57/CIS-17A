/*
 * File:   Gaddis_8thEd_Chap15_Prob1_Employee_ProductionWorkers_Classes.h
 * Author: Isaac Perez
 * Created on 05/14/2026
 * Purpose:  use class
 */

#ifndef Gaddis_8thEd_Chap13_Prob5_Retail_Item_Class_H
#define Gaddis_8thEd_Chap13_Prob5_Retail_Item_Class_H
#include <iostream>

using namespace std;

class RetailItem
{
private:
    string description;
    int unitsOnHand;
    double price;
public:
    //constructor
    RetailItem(string, int, double);

    //mutators
    void setDescription(string);
    void setUnitsOnHand(int);
    void setPrice(double);

    //accessors
    string getDescription();
    int getUnitsOnHand();
    double getPrice();


};


//Function Implementations
RetailItem::RetailItem(string d, int u, double p)
{
    description = d;
    unitsOnHand = u;
    price = p;
}

//accessors
string RetailItem::getDescription()
{
    return description;
}

int RetailItem::getUnitsOnHand()
{
    return unitsOnHand;
}

double  RetailItem::getPrice()
{
    return price;
}

//mutators
void RetailItem::setDescription(string d)
{
    description = d;
}

void RetailItem::setUnitsOnHand(int u)
{
    unitsOnHand = u;
}

void RetailItem::setPrice(double p)
{
    price = p;
}
#endif