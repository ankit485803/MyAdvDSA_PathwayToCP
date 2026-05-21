#include <iostream>
using namespace std;

/*
    Find Missing Number using XOR (^)

    Problem:
    Array contains numbers from 1 to n
    but one number is missing.

    Example:
    arr = {1, 2, 4, 5}
    Missing number = 3

    Concept:
    XOR of same numbers becomes 0

    Properties:
    A ^ A = 0
    A ^ 0 = A

    Logic:
    Step 1:
    XOR all array elements

    Step 2:
    XOR numbers from 1 to n

    Step 3:
    Same numbers cancel each other

    Remaining number = Missing number

    Dry Run:

    arr = {1, 2, 4, 5}
    n = 5

    xor1 = 1 ^ 2 ^ 4 ^ 5
    xor2 = 1 ^ 2 ^ 3 ^ 4 ^ 5

    Final:
    xor1 ^ xor2 = 3
*/

int main() {

    int arr[] = {1, 2, 4, 5};
    int n = 5;

    int xor1 = 0;
    int xor2 = 0;

    // XOR of array elements
    for(int i = 0; i < n - 1; i++) {
        xor1 = xor1 ^ arr[i];
    }

    // XOR from 1 to n
    for(int i = 1; i <= n; i++) {
        xor2 = xor2 ^ i;
    }

    int missing = xor1 ^ xor2;

    cout << "Missing Number = " << missing;

    return 0;
}