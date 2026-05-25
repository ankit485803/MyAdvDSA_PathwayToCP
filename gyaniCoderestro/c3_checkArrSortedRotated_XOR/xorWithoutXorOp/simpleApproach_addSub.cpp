#include <iostream>

using namespace std;

/**
 * Method 3: Arithmetic Subtraction Method
 * Concept: Eliminates columns where both bits are 1 without needing borrows.
 * Formula: (A OR B) - (A AND B)
 */
int xorMethod3(int a, int b) {
    return (a | b) - (a & b);
}

int main() {
    // Test parameters
    int a = 3;
    int b = 5;
    
    cout << "Inputs: A = " << a << ", B = " << b << endl;
    cout << "Derived XOR Result: " << xorMethod3(a, b) << endl;
    
    return 0;
}
