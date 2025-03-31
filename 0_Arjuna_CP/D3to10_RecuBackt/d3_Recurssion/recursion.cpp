

/* Recursion is a programming technique where a function calls itself to solve a problem.


Key Properties
Base Case: The condition that stops recursion (prevents infinite loops).
Recursive Case: The part where the function calls itself with a smaller subproblem.

How It Works? (Recursive Tree) 

TC = O(n)--Each call reduces n by 1
SC = O(n)  -- Due to the recursive call stack.


Application = factorial, fibonaci series, 

Optimized Fibonacci (Using Memoization)


*/



#include <iostream>
using namespace std;



/*
Problem Statement:

Write a C++ program that calculates the sum of the digits of a given integer n using recursion. 
The sum of digits of a number is obtained by repeatedly adding its individual digits until the number becomes 0.

*/


#include <iostream>
#include <cmath> // For handling negative numbers if necessary
using namespace std;


int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    
    // Get the last digit and recurse for the remaining number
    return abs(n % 10) + sum_of_digits(n / 10);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of digits of " << n << " is: " << sum_of_digits(n) << endl;

    return 0;
}
