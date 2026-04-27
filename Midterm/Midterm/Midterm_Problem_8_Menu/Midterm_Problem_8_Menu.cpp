/*
 * File:   Midterm_Problem_8_Menu
 * Author: Isaac Perez
 * Created: 04/27/2026
 * Purpose:  Menu selection
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <string>

using namespace std;

//User Libraries

#pragma region Problem 1
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
#pragma endregion

#pragma region Problem 2
struct Employee
{
    string name;
    float hrsWorked;
    float payRate;
    float grossPay;
    string grossPayWord;
};
#pragma endregion

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
//Menu
void displayMenu();
void prob1();
void prob2();
void prob4();
void prob5();

#pragma region Problem 1
void getData(Customer*);
void calculateBalance(Customer*);
void displayData(Customer*);
#pragma endregion

#pragma region Problem 2
void getData(Employee*, const int);
void calculatePay(Employee*, const int);
string numberToWords(float);
void displayCheck(Employee*, const int);
#pragma endregion

#pragma region Problem 4
void menu();
void encrypt();
void decrypt();
#pragma endregion


//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function

    //Initialize all known variables
    int menuSelect = -1;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    while (menuSelect != 0)
    {
        displayMenu();
        cin >> menuSelect;
        switch (menuSelect)
        {
        case 1: 
            prob1();
            break;
        case 2:
            prob2();
            break;
        case 3:
            cout << "On a different project" << endl;
            break;
        case 4:
            prob4();
            break;
        case 5:
            prob5();
            break;
        }
    }
    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
void displayMenu()
{
    cout << "1. Problem 1 Financial Tracker" << endl;
    cout << "2. Problem 2 Employee Checks" << endl;
    cout << "3. Problem 3 Mean Median Mode" << endl;
    cout << "4. Problem 4 Data Encryption" << endl;
    cout << "5. Problem 5 Exploration of Data Types" << endl;
    cout << "6. Problem 6 NASA conversion" << endl;
    cout << "7. Problem 7 Prime Numbers" << endl;
    cout << "0. Exit" << endl;

}

#pragma region Problem 1
void prob1()
{
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
}

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
        cout << "Enter amount for check " << i + 1 << ": $";
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
    cout << endl << endl;
}
#pragma endregion

#pragma region Problem 2
void prob2()
{
    //Set the random number seed here

//Declare all variables for this function

//Initialize all known variables
    int numOfEmp;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    cout << "How many employees? ";
    cin >> numOfEmp;

    Employee* e = new Employee[numOfEmp];

    getData(e, numOfEmp);
    calculatePay(e, numOfEmp);
    displayCheck(e, numOfEmp);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    delete[] e;
}

void getData(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {
        cout << endl;
        cout << "Employee #" << i + 1 << endl;
        cout << "Name: ";
        getline(cin >> ws, e[i].name);
        cout << "Hours worked: ";
        cin >> e[i].hrsWorked;
        cout << "Pay rate: $";
        cin >> e[i].payRate;

    }
}

void calculatePay(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {
        if (e[i].hrsWorked <= 40)
        {
            e[i].grossPay = e[i].hrsWorked * e[i].payRate;
        }
        else if (e[i].hrsWorked > 40 && e[i].hrsWorked <= 50)
        {
            e[i].grossPay = (40 * e[i].payRate) + (e[i].hrsWorked - 40) * (e[i].payRate * 2);
        }
        else
        {
            e[i].grossPay = (40 * e[i].payRate) +
                (10 * e[i].payRate * 2) +
                (e[i].hrsWorked - 50) * (e[i].payRate * 3);
        }
    }
}

string numberToWords(float n2Cnvrt)
{
    string result = "";

    if (n2Cnvrt >= 1 && n2Cnvrt <= 9999)
    {

        int n = (int)n2Cnvrt;
        //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s, n100s, n10s, n1s;
        n1000s = n / 1000;   //Shift 3 places to the left
        n100s = n % 1000 / 100;//Remainder of division of 1000 then shift 2 left
        n10s = n % 100 / 10;   //Remainder of division of 100 then shift 1 left
        n1s = n % 10;        //Remainder of division by 10

        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch (n1000s) {
        case 9: result += "Nine thousand "; break;
        case 8: result += "Eight thousand "; break;
        case 7: result += "Seven thousand "; break;
        case 6: result += "Six thousand "; break;
        case 5: result += "Five thousand "; break;
        case 4: result += "Four thousand "; break;
        case 3: result += "Three thousand "; break;
        case 2: result += "Two thousand "; break;
        case 1: result += "One thousand "; break;
        }

        //Output the number of 100's
        //Using the Ternary Operator
        result += (n100s == 9 ? "nine hundred " :
            n100s == 8 ? "eight hundred " :
            n100s == 7 ? "seven hundred " :
            n100s == 6 ? "six hundred " :
            n100s == 5 ? "five hundred " :
            n100s == 4 ? "four hundred " :
            n100s == 3 ? "three hundred " :
            n100s == 2 ? "two hundred " :
            n100s == 1 ? "one hundred " : "");

        //Output the number of 10's
        //Using Independent If Statements
        if (n10s == 1)
        {
            if (n1s == 0) result += "ten ";
            else if (n1s == 1) result += "eleven ";
            else if (n1s == 2) result += "twelve ";
            else if (n1s == 3) result += "thirteen ";
            else if (n1s == 4) result += "fourteen ";
            else if (n1s == 5) result += "fifteen ";
            else if (n1s == 6) result += "sixteen ";
            else if (n1s == 7) result += "seventeen ";
            else if (n1s == 8) result += "eighteen ";
            else if (n1s == 9) result += "nineteen ";
        }
        //Output the number of 10's
        //Using Independent If Statements
        else
        {
            if (n10s == 9) result += "ninety ";
            if (n10s == 8) result += "eighty ";
            if (n10s == 7) result += "seventy ";
            if (n10s == 6) result += "sixty ";
            if (n10s == 5) result += "fifty ";
            if (n10s == 4) result += "forty ";
            if (n10s == 3) result += "thirty ";
            if (n10s == 2) result += "twenty ";
        }

        //Output the number of 1's
        //Using Dependent If Statements
        if (n1s == 9) result += "nine ";
        else if (n1s == 8) result += "eight ";
        else if (n1s == 7) result += "seven ";
        else if (n1s == 6) result += "six ";
        else if (n1s == 5) result += "five ";
        else if (n1s == 4) result += "four ";
        else if (n1s == 3) result += "three ";
        else if (n1s == 2) result += "two ";
        else if (n1s == 1) result += "one ";
    }
    return result;
}

void displayCheck(Employee* e, const int numOfEmp)
{
    for (int i = 0; i < numOfEmp; i++)
    {

        e[i].grossPayWord = numberToWords(e[i].grossPay);
        int dollars = (int)e[i].grossPay;
        int cents = (int)((e[i].grossPay - dollars) * 100);
        cout << endl;
        cout << "Best Company" << endl;
        cout << "123 Best Way Dr " << endl;
        cout << "Best City, CA, 13012" << endl;
        cout << "Name: " << e[i].name << " Amount: $" << e[i].grossPay << endl;
        cout << "Amount: " << e[i].grossPayWord << "& " << cents << "/100" << endl;
        cout << "Signature Line: ____________________________" << endl << endl;
    }
}
#pragma endregion

#pragma region Problem 4
void prob4()
{
    //Set the random number seed here

  //Declare all variables for this function

  //Initialize all known variables
    int option;
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    do
    {
        menu();
        cin >> option;

        switch (option)
        {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        default:
            cout << "Invalid option. Try again" << endl;

        }
    } while (option != 0);

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

}

void menu()
{
    cout << "Menu" << endl;
    cout << "1. Encrypt Data" << endl;
    cout << "2. Decrypt Data" << endl;
}
void encrypt()
{
    int num;
    const int size = 4;
    int digit[size];
    cout << "Enter a 4-digit number to encrypt (only use numbers 0-7): ";
    cin >> num;

    digit[0] = num / 1000;
    digit[1] = (num / 100) % 10;
    digit[2] = (num / 10) % 10;
    digit[3] = num % 10;

    for (int i = 0; i < size; i++)
    {
        if (digit[i] > 7)
        {
            cout << "digits must be 0-7 only" << endl;
            return;
        }
    }

    for (int i = 0; i < size; i++)
    {
        digit[i] = (digit[i] + 3) % 8;
    }

    swap(digit[0], digit[2]);
    swap(digit[1], digit[3]);

    cout << "Encrypted: ";
    for (int i = 0; i < size; i++)
    {
        cout << digit[i];
    }
    cout << endl;
}


void decrypt()
{
    const int decryptMap[8] = { 5,6,7,0,1,2,3,4 };
    int num;
    const int size = 4;
    int digit[size];
    cout << "Enter a 4-digit number to encrypt (only use numbers 0-7): ";
    cin >> num;

    digit[0] = num / 1000;
    digit[1] = (num / 100) % 10;
    digit[2] = (num / 10) % 10;
    digit[3] = num % 10;

    for (int i = 0; i < size; i++)
    {
        if (digit[i] > 7)
        {
            cout << "digits must be 0-7 only" << endl;
            return;
        }
    }

    for (int i = 0; i < size; i++)
    {
        digit[i] = decryptMap[digit[i]];
    }
    swap(digit[0], digit[2]);
    swap(digit[1], digit[3]);

    cout << "Decrypted: ";
    for (int i = 0; i < size; i++)
    {
        cout << digit[i];
    }
    cout << endl << endl;
}
#pragma endregion

#pragma region Problem 5
void prob5()
{

    //Display the Inputs/Outputs

    cout << "Unsigned byte = !5" << endl;
    cout << "Signed byte = !5" << endl;
    cout << "Short = !7" << endl;
    cout << "Unsigned short = !8" << endl;
    cout << "Int = !12" << endl;
    cout << "Unsigned int = !12" << endl;
    cout << "Long = !12" << endl;
    cout << "Unsigned long = !12" << endl;
    cout << "Long long = !20" << endl;
    cout << "Unsigned long long = !20" << endl;
    cout << "Float = !34" << endl;
    cout << "Double = !170" << endl;

}
#pragma endregion
