//25th May 2026 (Monday) find XOR whithout xor operator 

#include <iostream>
#include <cmath> // Required for abs()

using namespace std;

/**
 * Method 1: Using Boolean Logic Identity
 * Concept: Standard logical gate representation of XOR. 
 * Formula: (A AND NOT B) OR (NOT A AND B)
 * It extracts unique bits from 'a', unique bits from 'b', and combines them.
 */
int xorMethod1(int a, int b) {
    return (a & ~b) | (~a & b);
}

/**
 * Method 2: Using OR and AND Exclusion
 * Concept: Grab all active bits using OR, then strip out the common bits using AND.
 * Formula: (A OR B) AND NOT(A AND B)
 */
int xorMethod2(int a, int b) {
    return (a | b) & ~(a & b);
}

/**
 * Method 3: Your Clever Arithmetic Subtraction Method
 * Concept: Since every bit in (A & B) is guaranteed to be a 1 in (A | B), 
 * subtracting them eliminates columns where both bits are 1 without needing borrows.
 * Formula: (A OR B) - (A AND B)
 */
int xorMethod3(int a, int b) {
    return (a | b) - (a & b);
}

/**
 * Method 4: Bit-by-Bit Arithmetic (Modulo / Absolute Difference)
 * Concept: Iterates through each bit position. For single bits, 
 * adding them and taking modulo 2 (or taking the absolute difference) mimics XOR.
 */
int xorMethod4(int a, int b) {
    int result = 0;
    // Iterate through all 32 bits of a standard integer
    for (int i = 0; i < 32; ++i) {
        // Extract the i-th bit of both numbers
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        
        // Apply single-bit XOR math: (bitA + bitB) % 2  OR  abs(bitA - bitB)
        int xorBit = (bitA + bitB) % 2; 
        
        // Shift the resulting bit back to its original position
        result |= (xorBit << i);
    }
    return result;
}

int main() {
    // Test case from your notes: A = 3, B = 5
    int a = 3;
    int b = 5;
    
    cout << "--- Testing XOR implementations for A=" << a << ", B=" << b << " ---" << endl;
    cout << "Standard C++ Operator (a ^ b) : " << (a ^ b) << endl;
    cout << "Method 1 (Boolean Logic)      : " << xorMethod1(a, b) << endl;
    cout << "Method 2 (OR/AND Exclusion)   : " << xorMethod2(a, b) << endl;
    cout << "Method 3 (Your Subtraction)   : " << xorMethod3(a, b) << endl;
    cout << "Method 4 (Bit-by-Bit Modulo)  : " << xorMethod4(a, b) << endl;
    
    return 0;
}

