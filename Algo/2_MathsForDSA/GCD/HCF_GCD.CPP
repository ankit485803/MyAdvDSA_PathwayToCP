
#include <iostream>
using namespace std;



/* GCD (greatest commin divisor) is same HCF (highest common factor)


method1: brute force -- O(min(a, b))

 for (int i = 1; i <= min_num; i++) {
        // Check if i divides both numbers
        if (a % i == 0 && b % i == 0) {
            gcd = i;  // Update the GCD
        }


method2: Euclid's Algo

method3: If you are using C++17 or later, the C++ Standard Library provides a built-in function for calculating the GCD:

#include <numeric>  // For std::gcd
int result = gcd(num1, num2);



*/


int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if(a == 0) return b;
    return a;
}

//gcd using ITERATORS method is difficult so we use the RECURSION 
int gcdRec(int a, int b) {
    if(b == 0) return a;

    return gcdRec(b, a % b);
}



int main() {

    cout << gcd(20, 28) << endl;
    cout << gcdRec(0, 28) << endl;

    return 0;
}