

/*

switch statement is rarely used 


A switch statement in C++ is used when you want to check a single variable against multiple fixed values.


switch(expression) {
    case value1:
        // code
        break;

    case value2:
        // code
        break;

    case value3:
        // code
        break;

    default:
        // code if no case matches
}



expression is usually an int or char.
case values must be constant.
break stops execution of the switch.
default runs if no case matches.




*/



#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter day number (1-7): ";
    cin >> day;

    switch(day) {
        case 1:
            cout << "Monday";
            break;

        case 2:
            cout << "Tuesday";
            break;

        case 3:
            cout << "Wednesday";
            break;

        case 4:
            cout << "Thursday";
            break;

        case 5:
            cout << "Friday";
            break;

        case 6:
            cout << "Saturday";
            break;

        case 7:
            cout << "Sunday";
            break;

        default:
            cout << "Invalid day";
    }

    return 0;
}