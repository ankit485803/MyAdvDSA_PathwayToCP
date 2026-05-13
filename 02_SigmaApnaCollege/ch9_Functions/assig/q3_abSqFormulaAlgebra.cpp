

/*

Question 3 : Write a function which takes 2 numbers as parameters (a & b) and
outputs : a^2 + b^2 + 2*ab



using ^ oeprators in c++ we can take square or not
No, you cannot use the ^ operator to calculate a square in C++.
In C++, the ^ symbol does not mean exponentiation. Instead, it is the bitwise XOR (Exclusive OR) operator.

method 1. Direct Multiplication (Recommended for Performance)
int number = 5;
int square = number * number; // Yields 25


method2. Using std::pow (For Dynamic Exponents)
#include <cmath>
double square = std::pow(5, 2); // Yields 25.0




*/


#include <iostream>
using namespace std;

// Function to calculate a^2 + b^2 + 2ab    int squareOfSum(a, b)
int sumAB(int a, int b) {  //tc=O(1)=sc
    int ans = (a*a) + (b*b) + (2 * a*b);

    return ans;
}


int main() {
    int a = 2, b = 3;

    cout << "value of mathematical expression (" << a << " + " << b << ")^2 = " << sumAB(a, b) << endl;

    return 0;
}