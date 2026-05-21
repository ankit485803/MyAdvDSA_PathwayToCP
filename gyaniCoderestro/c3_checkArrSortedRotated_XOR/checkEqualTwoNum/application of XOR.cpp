#include <iostream>
using namespace std;

/*
    Check two numbers are equal or not
    without using arithmetic and comparison operators

    Concept:
    Using Bitwise XOR (^)

    Properties:
    A ^ A = 0
    A ^ 0 = A

    Logic:
    - If both numbers are same,
      then XOR gives 0
    - If numbers are different,
      then XOR gives non-zero

    Applications of XOR:
    1. Find different number among same numbers
       Example:
       A = 7, B = 12
       7 ^ 12 != 0

    2. Find unique element in array
       Example:
       {2, 3, 4, 3, 2}
       Unique = 4

    3. Swap two numbers without third variable

    4. Find missing element in arrays
*/

void checkEqual(int a, int b) {

    if (a ^ b)
        cout << "Not Equal";

    else
        cout << "Equal";
}

int main() {

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    checkEqual(a, b);

    return 0;
}