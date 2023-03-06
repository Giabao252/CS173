/*
author: Thanh Do - Bao Luu
date: Feb 23, 2023
class: CS173
professor: Dr. Asif
Thanh's tasks: design algorithm, write convert function, program testing
Bao's tasks: design algorithm, write main function, program testing
*/

#include <iostream>
#include <map>
#include <math.h>
using namespace std;

string convert(int year);

int main()
{
    int year;
    while (int i = 1)
    {
        cout << "Enter year 1 to 2023 (0 to quit): ";
        cin >> year;
        if (year == 0)
            break;
        else if (year < 0 || year > 2023)
            continue;
        string roman = convert(year);
        cout << year << " = " << roman << endl;
    }

    return 0;
}

string convert(int year)
{
    /*
    This function takes an integer and converts it into Roman numeral form
    Precondition: input is an integer
    Return value: a string represents a Roman numeral
    */
    string roman = "";

    // map of all posible cases
    map<int, string> int_roman = {{0, ""}, {1000, "M"}, {2000, "MM"}, {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"}, {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}};

    // get each part of integer
    int digit[4];
    for (int i = 0; i < 4; i++)
    {
        digit[i] = year % 10;
        year = year / 10;
    }

    // get Roman numeral for each part of integer
    for (int i = 3; i > -1; i--)
    {
        roman = roman + int_roman[digit[i] * pow(10, i)];
    }

    return roman;
}

/*
TEST CASES AND EXPLANATIONS:

TEST CASE 1: 2040 - EXPECTED OUTPUT: Null
Explanation: This test case tests the default input constraint of 0 to 2023 

TEST CASE 2: 1958 - EXPECTED OUTPUT: MCMLVIII
Explanation: This test case tests a random value that satisfies the input constraint 

TEST CASE 3: 0 - EXPECTED VALUE: program quits
Explanation: This test case checks if the input loop is working good by ordering it to quit
*/