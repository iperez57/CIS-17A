/*
 * File:   Midterm_Problem_7_Prime_Numbers
 * Author: Isaac Perez
 * Created: 04/25/2026
 * Purpose:  NASA Format conversion
 */

 //System Libraries
#include <iostream>  //I/O Library

using namespace std;

//User Libraries
struct Prime
{
    unsigned char power; //Power associated with the prime number
    unsigned char prime; //Prime number factor
};

struct Primes
{
    unsigned short n; //Number to factor into Primes
    unsigned char nPrimes; //Number of Primes
    Prime* pStrAry; //The Prime Structure Array
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Primes* factor(int); //Factor the number into it's Primes
void prtPrms(const Primes*); //Print the prime factors
void cleanUp(Primes*); //Clean it all up
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int num;
    Primes* p;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "Enter number: ";
    cin >> num;

    p = factor(num);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
Primes* factor(int num)
{
    Primes* result = new Primes;
    result->n = num;
    result->nPrimes = 0;
    result->pStrAry = new Prime[20];

    int n = num;
    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                count++;
            }

            result->pStrAry[result->nPrimes].prime = i;
            result->pStrAry[result->nPrimes].power = count;
            result->nPrimes++;
        }
    }

    return result;
}