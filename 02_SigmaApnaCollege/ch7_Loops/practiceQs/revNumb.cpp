

// Reverse the given numb  and print the result


#include <iostream>
using namespace std;

int main() {
    int n = 10829;
    int result = 0;

    while(n > 0) {
        int lastDig = n % 10; 
        result = result * 10 + lastDig;
        n /= 10;
    }

    cout << "reverse numn = " << result << endl;

    return 0;
}



// Edge Cases to handle
// 1. Number ending with 0 → already handled automatically
// 2.  Negative number → needs extra logic
// 3. too large numb

#include <iostream>
using namespace std;

int main() {
    int n = -1200;   // try different inputs
    long long result = 0;

    // Handle negative number
    int sign = 1;
    if(n < 0) {
        sign = -1;
        n = -n;   // make number positive
    }

    // Reverse logic
    while(n > 0) {
        int lastDig = n % 10; 
        result = result * 10 + lastDig;
        n /= 10;
    }

    result *= sign;  // restore sign

    cout << "reverse num = " << result << endl;

    return 0;
}