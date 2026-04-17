/*
 * File:   Weather_Statistics
 * Author: Isaac Perez
 * Created: 04/17/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>
#include <iomanip>


using namespace std;

//User Libraries
struct WeatherData
{
    string month;
    float totRain;
    float lTemp;
    float hTemp;
};

struct Stats
{
    float avgRainfall;
    float lowestTemp;
    float highestTemp;
    float avgYearTemp;
    string lowMonth;
    string highMonth;
};

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void getData(WeatherData year[], int SIZE);
Stats calculate(WeatherData year[], int SIZE);
void display(Stats yearlyStat);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    const int SIZE = 12;
    WeatherData year[SIZE];
    Stats yearlyStat;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    getData(year, SIZE);
    yearlyStat = calculate(year, SIZE);
    display(yearlyStat);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void getData(WeatherData year[],int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cin >> year[i].month;
        cin >> year[i].totRain;
        cin >> year[i].lTemp;
        cin >> year[i].hTemp;
    }
}

Stats calculate(WeatherData year[], int SIZE)
{
    Stats yearlyCalc;
    float moAvgTemp = 0;
    float highest = year[0].hTemp;
    float lowest = year[0].lTemp;
    float avgRain = 0;
    float avgTemp = 0;
    int indxLow = 0;
    int indxHigh = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (highest < year[i].hTemp)
        {
            highest = year[i].hTemp;
            indxHigh = i;
        }
        if (lowest > year[i].lTemp)
        {
            lowest = year[i].lTemp;
            indxLow = i;
        }
        moAvgTemp = (year[i].hTemp + year[i].lTemp) / 2;
        avgTemp += moAvgTemp;

        avgRain += year[i].totRain;
    }

    yearlyCalc.highestTemp = highest;
    yearlyCalc.lowestTemp = lowest;
    yearlyCalc.avgRainfall = avgRain / SIZE;
    yearlyCalc.avgYearTemp = avgTemp / SIZE;
    yearlyCalc.highMonth = year[indxHigh].month;
    yearlyCalc.lowMonth = year[indxLow].month;


    return yearlyCalc;
}

void display(Stats yearlyStat)
{
    cout << setprecision(2) <<  "Average Rainfall " << yearlyStat.avgRainfall << " inches/month" << endl;
    cout << "Lowest  Temperature " << yearlyStat.lowMonth << "  " << yearlyStat.lowestTemp << " Degrees Fahrenheit" << endl;
    cout << setprecision(3) << "Highest Temperature " << yearlyStat.highMonth << "  " << yearlyStat.highestTemp << " Degrees Fahrenheit" << endl;
    cout << setprecision(2) <<  "Average Temperature for the year " << yearlyStat.avgYearTemp << " Degrees Fahrenheit" << endl;
}