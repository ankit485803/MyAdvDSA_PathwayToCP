#include <iostream>
using namespace std;

/*
    Swap two numbers without third variable
    using Bitwise XOR (^)

    Concept:
    XOR swaps values using binary operation

    Properties:
    A ^ A = 0
    A ^ 0 = A

    Working:

    Suppose:
    a = 5
    b = 7

    Step 1:
    a = a ^ b
    a = 5 ^ 7

    Step 2:
    b = a ^ b
    b = (5 ^ 7) ^ 7
    b = 5

    Step 3:
    a = a ^ b
    a = (5 ^ 7) ^ 5
    a = 7

    Final:
    a = 7
    b = 5

    Applications of XOR:
    1. Swap numbers
    2. Find unique element
    3. Check equal numbers
    4. Missing number problems
*/

int main() {

    int a = 5, b = 7;

    cout << "Before Swap:\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Swapping using XOR
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "\nAfter Swap:\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}