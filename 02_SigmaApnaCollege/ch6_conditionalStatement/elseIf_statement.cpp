

/*

else if statement


The else if statement is used when you need to check multiple conditions one after another.
It allows a program to choose one block of code from many possible options.


*/


if (condition1) {
    // code if condition1 is true
}
else if (condition2) {
    // code if condition2 is true
}
else if (condition3) {
    // code if condition3 is true
}
else {
    // code if none of the above conditions are true
}




#include <iostream>
using namespace std;

int main() {
    int marks = 75;

    if (marks >= 90) {
        cout << "Grade A";
    }
    else if (marks >= 75) {
        cout << "Grade B";
    }
    else if (marks >= 50) {
        cout << "Grade C";
    }
    else {
        cout << "Fail";
    }

    return 0;
}