



/*

24th Aug 2025 (Saunday)


method1: iterative using Euclidean algo
*/

#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 56;
    int b = 98;
    std::cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << std::endl;
    return 0;
}



//method2:  Implementing the Euclidean Algorithm (Recursive):

int gcd(int a, int b) { //TC=O(log(min(a, b))) = SC
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a = 105;
    int b = 30;
    std::cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << std::endl;
    return 0;
}





//method3: using C++ STL
#include <iostream>
#include <numeric> // Required for std::gcd

int main() {
    int a = 56;
    int b = 98;
    int gcd_value = std::gcd(a, b);
    std::cout << "GCD of " << a << " and " << b << " is: " << gcd_value << std::endl;  //TC=O(1)
    return 0;
}