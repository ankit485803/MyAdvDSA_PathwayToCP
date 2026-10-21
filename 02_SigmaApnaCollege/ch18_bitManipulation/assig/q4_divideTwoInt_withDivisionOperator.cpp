

/*

LeetCode probNo 29  https://leetcode.com/problems/divide-two-integers/description/

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        //bruteFore -- usig divisor mathematical op

        int ans = dividend / divisor;
        return ans;
    }
};


//error: Line 6: Use of the division operator / is prohibited.



class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to safely handle INT_MIN
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Find the largest shifted divisor that fits
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        if (negative) {
            ans = -ans;
        }

        return (int)ans;
    }
};






class Solution {
public:
    int divide(int dividend, int divisor) {  //old submission 24th July 2025
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

            // Double temp until it exceeds a
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

