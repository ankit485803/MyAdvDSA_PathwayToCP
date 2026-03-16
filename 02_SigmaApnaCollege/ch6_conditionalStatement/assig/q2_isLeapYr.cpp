

/*


Question 2:
Write a C++ program that takes a year from the user and prints whether
that year is a leap year or not.

Hint:
A leap year is exactly divisible by 4 except for century years
(years ending with 00). The century year is a leap year only if
it is perfectly divisible by 400.

Examples:
1999 is not a leap year
2000 is a leap year
2004 is a leap year


*/


#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter the year (like 2005, 1998, etc)";
    cin >> year;

    if(year % 4 == 0) {
        cout << "Leap year" << endl;
    } else {
        cout << "Not leap yr" << endl;
    }

    //cout << (year % 4 == 0) ? "Leap year" : "not leap yr" << endl;

    return 0;
}


// Your code would incorrectly say 1900 is a leap year.



#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter the year (like 2005, 1998, etc): ";
    cin >> year;

    if (year % 400 == 0) {
        cout << "Leap year" << endl;
    }
    else if (year % 100 == 0) {
        cout << "Not a leap year" << endl;
    }
    else if (year % 4 == 0) {
        cout << "Leap year" << endl;
    }
    else {
        cout << "Not a leap year" << endl;
    }

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    // if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    //     cout << "Leap year" << endl;
    // else
    //     cout << "Not a leap year" << endl;

    string isLeap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? "Leap yr" : "not leap yr";
    cout << "check year leap or not: " << isLeap << endl;    

    return 0;
}



//testcase: year- 1900, 2000, 2004, 2100

