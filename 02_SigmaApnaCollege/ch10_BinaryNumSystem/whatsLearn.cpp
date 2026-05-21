

/*

15th May 2026 (Friday) from this we will mention the what's imp concepts learnt from this chapter


1.0 build in function in cpp for a power b calculate
1.1  int datType size = 4 byte = 32 bits given

1.2 Add two binary numbers using binary rules
1.3 Optional: Using string method


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




// Add two binary numbers using binary rules
int addBinary(int a, int b) {
    int result = 0;
    int carry = 0;
    int pow = 1;

    while (a > 0 || b > 0 || carry > 0) {
        int bit1 = a % 10;
        int bit2 = b % 10;

        int sum = bit1 ^ bit2 ^ carry; // XOR for sum
        carry = (bit1 & bit2) | (bit2 & carry) | (bit1 & carry); // AND-OR for carry

        result += sum * pow;
        pow *= 10;

        a /= 10;
        b /= 10;
    }

    return result;
}


//Optional: Using string method
int binToDecimalStr(string s) {
    int dec = 0;
    int pow = 1;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == '1') dec += pow;
        pow *= 2;
    }
    return dec;
}