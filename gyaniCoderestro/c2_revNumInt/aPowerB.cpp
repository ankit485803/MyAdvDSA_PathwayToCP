

/*

15th May 2026 (Friday)

build in function in cpp for a power b calculate

src: D:\GitProj\MyAdvDSA_PathwayToCP\02_SigmaApnaCollege\ch10_BinaryNumSystem\whatsLearn.cpp


*/


#include <iostream>
#include <cmath> // Required for pow()

using namespace std;

int main() {
    double base = 2.0;
    double exponent = 3.0;
    
    // Calculates 2 raised to the power of 3 (2^3)
    double result = pow(base, exponent);
    
    cout << "Result: " << result << endl; // Output: 8
    return 0;
}





#include <iostream>
#include <cmath> // Required header

int main() {
    double base = 2.0;
    double exponent = 3.0;
    
    // Calculates 2^3
    double result = std::pow(base, exponent); 
    
    std::cout << base << " ^ " << exponent << " = " << result << std::endl;
    return 0;
}



// Performance Optimization for Integers
long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}
