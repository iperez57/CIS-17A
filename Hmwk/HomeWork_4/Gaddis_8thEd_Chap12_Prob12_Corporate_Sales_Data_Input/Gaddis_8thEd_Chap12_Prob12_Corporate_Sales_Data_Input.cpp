/*
 * File:    Gaddis_8thEd_Chap12_Prob11_Corporate_Sales_Data_Input.cpp
 * Author: Isaac Perez
 * Created: 04/18/2026
 * Purpose:  structure to binary file
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

//User Libraries
struct CompanyDiv
{
    char name[10];
    float q1;
    float q2;
    float q3;
    float q4;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void readFile(CompanyDiv div[], int size);
void calcData(CompanyDiv div[], int size);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    CompanyDiv div[4];
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    readFile(div, 4);
    calcData(div, 4);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations

void readFile(CompanyDiv div[], int size)
{
    ifstream in("sales.bin", ios::binary);

    if (!in)
    {
        cout << "Error opening file" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        in.read(reinterpret_cast<char*>(&div[i]), sizeof(CompanyDiv));
    }
    in.close();
}

void calcData(CompanyDiv div[], int size)
{
    float totQ1 = 0;
    float totQ2 = 0;
    float totQ3 = 0;
    float totQ4 = 0;
    float totDivSales = 0;
    float totCorpSales = 0;
    float avgQSales = 0;
    float highQ = totQ1;
    float lowQ = totQ1;
    string highQName = "Q1";
    string lowQName = "Q1";

    for (int i = 0; i < size; i++)
    {
        totQ1 += div[i].q1;
        totQ2 += div[i].q2;
        totQ3 += div[i].q3;
        totQ4 += div[i].q4;

        totDivSales = div[i].q1 + div[i].q2 + div[i].q3 + div[i].q4;
        totCorpSales += totDivSales;

        cout << div[i].name << " yearly: $" << totDivSales << endl;

    }
    
     cout << "Total Q1: $" << totQ1 << endl;
     cout << "Total Q2: $" << totQ2 << endl;
     cout << "Total Q3: $" << totQ3 << endl;
     cout << "Total Q4: $" << totQ4 << endl;

     cout << "Total Corporate Sales: $" << totCorpSales << endl;

     for (int i = 0; i < size; i++)
     {
         avgQSales = (div[i].q1 + div[i].q2 + div[i].q3 + div[i].q4) / 4.0f;
         cout << div[i].name << " average quarterly sales: $" << avgQSales << endl;
     }

     if (totQ2 > highQ)
     {
         highQ = totQ2; highQName = "Q2";
     }
      if (totQ3 > highQ)
      {
          highQ = totQ3; highQName = "Q3";
      }
      if (totQ4 > highQ)
      {
          highQ = totQ4; highQName = "Q4";
      }



      if (totQ2 < lowQ)
      {
          lowQ = totQ2; lowQName = "Q2";
      }
      if (totQ3 < lowQ)
      {
          lowQ = totQ3; lowQName = "Q3";
      }      
      if (totQ4 < lowQ)
      {
          lowQ = totQ4; lowQName = "Q4";
      }

      cout << "Highest Quarter: " << highQName << endl;
      cout << "Lowest Quarter: " << lowQName << endl;
}
