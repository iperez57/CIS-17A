/*
 * File:   Gaddis_8thEd_Chap13_Prob5_Retail_Item_Class.cpp
 * Author: Isaac Perez
 * Created: 05/14/2026
 * Purpose:  use class
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries
#include "Gaddis_8thEd_Chap13_Prob5_Retail_Item_Class.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << item1.getDescription() << " " << item1.getUnitsOnHand() << " " << item1.getPrice() << endl;
    cout << item2.getDescription() << " " << item2.getUnitsOnHand() << " " << item2.getPrice() << endl;
    cout << item3.getDescription() << " " << item3.getUnitsOnHand() << " " << item3.getPrice() << endl;
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations