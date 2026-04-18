/*
 * File:   Ga9EdC11P11
 * Author: Isaac Perez
 * Created: 04/15/2026
 * Purpose:  Use structures
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <iomanip>

using namespace std;

//User Libraries
struct MonthlyBudget
{
    float housing = 500.00;
    float utilities = 150.00;
    float householdExpenses = 65.00;
    float transportation = 50.00;
    float food = 250.00;
    float medical = 30.00;
    float insurance = 100.00;
    float entertainment = 150.00;
    float clothing = 75.00;
    float miscellaneous = 50.00;

};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
MonthlyBudget input(MonthlyBudget m);
void ReportIndication(MonthlyBudget m, MonthlyBudget budget);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    MonthlyBudget budget;
    MonthlyBudget m;
    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    m =input(m);
    ReportIndication(m, budget);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
MonthlyBudget input(MonthlyBudget m)
{
    
    cout << "Enter housing cost for the month:$" << endl;
    cin >> m.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> m.utilities;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> m.householdExpenses;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> m.transportation;
    cout << "Enter food cost for the month:$" << endl;
    cin >> m.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> m.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> m.insurance;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> m.entertainment;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> m.clothing;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> m.miscellaneous;

    return m;
}

void ReportIndication(MonthlyBudget m, MonthlyBudget budget)
{
    //housing comparison
    if (m.housing == budget.housing)
    {
        cout << "Housing Even" << endl;
    }
    else if (m.housing > budget.housing)
    {
        cout << "Housing Over" << endl;
    }
    else
    {
        cout << "Housing Under" << endl;
    }

    //Utilities comparison
    if (m.utilities == budget.utilities)
    {
        cout << "Utilities Even" << endl;
    }
    else if (m.utilities > budget.utilities)
    {
        cout << "Utilities Over" << endl;
    }
    else
    {
        cout << "Utilities Under" << endl;
    }

    //Household comparison
    if (m.householdExpenses == budget.householdExpenses)
    {
        cout << "Household Expenses Even" << endl;
    }
    else if (m.householdExpenses > budget.householdExpenses)
    {
        cout << "Household Expenses Over" << endl;
    }
    else
    {
        cout << "Household Expenses Under" << endl;
    }

    //Transportation comparison
    if (m.transportation == budget.transportation)
    {
        cout << "Transportation Even" << endl;
    }
    else if (m.transportation > budget.transportation)
    {
        cout << "Transportation Over" << endl;
    }
    else
    {
        cout << "Transportation Under" << endl;
    }

    //Food comparison
    if (m.food == budget.food)
    {
        cout << "Food Even" << endl;
    }
    else if (m.food > budget.food)
    {
        cout << "Food Over" << endl;
    }
    else
    {
        cout << "Food Under" << endl;
    }

    //Medical comparison
    if (m.medical == budget.medical)
    {
        cout << "Medical Even" << endl;
    }
    else if (m.medical > budget.medical)
    {
        cout << "Medical Over" << endl;
    }
    else
    {
        cout << "Medical Under" << endl;
    }

    //Insurance comparison
    if (m.insurance == budget.insurance)
    {
        cout << "Insurance Even" << endl;
    }
    else if (m.insurance > budget.insurance)
    {
        cout << "Insurance Over" << endl;
    }
    else
    {
        cout << "Insurance Under" << endl;
    }

    //Entertainment comparison
    if (m.entertainment == budget.entertainment)
    {
        cout << "Entertainment Even" << endl;
    }
    else if (m.entertainment > budget.entertainment)
    {
        cout << "Entertainment Over" << endl;
    }
    else
    {
        cout << "Entertainment Under" << endl;
    }

    //Clothing comparison
    if (m.clothing == budget.clothing)
    {
        cout << "Clothing Even" << endl;
    }
    else if (m.clothing > budget.clothing)
    {
        cout << "Clothing Over" << endl;
    }
    else
    {
        cout << "Clothing Under" << endl;
    }

    //Miscellaneous comparison
    if (m.miscellaneous == budget.miscellaneous)
    {
        cout << "Miscellaneous Even" << endl;
    }
    else if (m.miscellaneous > budget.miscellaneous)
    {
        cout << "Miscellaneous Over" << endl;
    }
    else
    {
        cout << "Miscellaneous Under" << endl;
    }
    
    //Total budget comparison
    float totalM = m.housing + m.utilities + m.householdExpenses + m.transportation + m.food
        + m.medical + m.insurance + m.entertainment + m.clothing + m.miscellaneous;
    float totalB = budget.housing + budget.utilities + budget.householdExpenses + budget.transportation + budget.food
        + budget.medical + budget.insurance + budget.entertainment + budget.clothing + budget.miscellaneous;
    
    if (totalM == totalB)
    {
        cout << "Your budget was even" << endl;
    }
    else if (totalM > totalB)
    {
        cout << fixed << setprecision(2) << "You were $" << totalM - totalB << " over budget" << endl;
    }
    else
    {
        cout << fixed << setprecision(2) << "You were $" << totalB - totalM << " under budget";
    }

}