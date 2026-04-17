/*
 * File:   Weather_Statistics
 * Author: Isaac Perez
 * Created: 04/17/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>


using namespace std;

//User Libraries
struct WeatherData
{
    string month;
    float totRain;
    float hTemp;
    float lTemp;
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getData(WeatherData year[], int SIZE, int highest, int lowest, int avgRain, int avgTemp);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    const int SIZE = 12;
    WeatherData year[SIZE];
    float highest = year[0].hTemp;
    float lowest = year[0].lTemp;
    float avgRain = 0;
    float avgTemp = 0;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    getData(year, SIZE, highest, lowest, avgRain, avgTemp);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void getData(WeatherData year[],int SIZE, int highest, int lowest, int avgRain, int avgTemp)
{
    
    for (int i = 0; i < SIZE; i++)
    {
        cin >> year[i].month;
        cin >> year[i].totRain;
        cin >> year[i].hTemp;
        cin >> year[i].lTemp;
    }
}