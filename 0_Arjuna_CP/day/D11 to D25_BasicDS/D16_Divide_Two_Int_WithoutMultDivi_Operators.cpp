

#include <iostream>
using namespace std;



/*

24th July 2025 (Thursday) Divide two integes without multiplication and divisor operators

*/




//method1: basic linear subtraction-based method, which works correctly but inefficiently for large input values so give TLE
   
int get_Quotient(int dividend, int divisor) {
    if (divisor == 0) {
        throw invalid_argument("Division by zero");
    }

    // Handle negative values
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    int absDividend = abs(dividend);
    int absDivisor = abs(divisor);

    int sum = 0;
    int count = 0;


    
    while (sum + absDivisor <= absDividend) {
        sum += absDivisor;
        count++;
    }

    return isNegative ? -count : count;  //ternary operator hai ye condition ? value_if_true : value_if_false;

}

// TC = O(dividend), SC=O(1)







int main() {
    cout << "10 / 3 = " << get_Quotient(10, 3) << endl;
    cout << "43 / -8 = " << get_Quotient(43, -8) << endl;
    cout << "-20 / -4 = " << get_Quotient(-20, -4) << endl;
    cout << "-15 / 2 = " << get_Quotient(-15, 2) << endl;

    return 0;
}



// qno 29 https://leetcode.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle division by zero
        if (divisor == 0) return INT_MAX;

        // Handle overflow case: INT_MIN / -1 = overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Use long long to handle abs(INT_MIN) safely
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Double temp until it exceeds a BITWISE LEFT SHIFT
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Determine sign of result
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        return isNegative ? -result : result;
    }
};


// TC=O(log dividend), SC=O(1)