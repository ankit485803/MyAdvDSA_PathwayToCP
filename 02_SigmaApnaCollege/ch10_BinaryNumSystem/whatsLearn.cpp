

/*

15th May 2026 (Friday) from this we will mention the what's imp concepts learnt from this chapter


1.0 build in function in cpp for a power b calculate
1.1  int datType size = 4 byte = 32 bits given

1.2 


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


