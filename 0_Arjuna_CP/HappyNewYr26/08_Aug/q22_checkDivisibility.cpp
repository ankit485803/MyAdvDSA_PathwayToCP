

/*

22nd Aug 2026 (Saturday)

qno 3622  https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/?envType=daily-question&envId=2026-08-22

3622. Check Divisibility by Digit Sum and Product
Attempted
Easy
Topics

Companies
Hint
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).

The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.

 

Example 1:

Input: n = 99

Output: true

Explanation:

Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:

Input: n = 23

Output: false

Explanation:

Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.

 

Constraints:

1 <= n <= 106
 
Discover more
Online assessment services
Seen this question in a real interview before?
1/6
Yes
No
Accepted
140,200/191.9K
Acceptance Rate
73.1%
Topics
Mid Level
Math
Weekly Contest 459

*/


class Solution {
public:
    //helperFun
    int calcaluteDigSum(int n) {  //tc=O(no of digits) = O(logN), sc=O(1)  myFirstAttempt
        int sum = 0;
        for(int num : n) {
            int lastD = num % 10;
            sum += lastD;
            num /= 10;  //removingLast
        }
        
        return sum;
    }

    int calculateDigProd(int n) {
        int prod = 1;  //initilize with 1
        for(int num : n) {
            int lastD = num % 10;
            prod *= lastD;
            num /= 10;  
        }

        return prod;
    }


    bool checkDivisibility(int n) {
        //createTwo helperFunct
        int digSum = calcaluteDigSum(n), digProd = calculateDigProd(n);

        int totalSum = digSum + digProd;

        return (n % totalSum == 0); 
    }
};

/*output c++ syntax error

for(int num : n)


A range-based for loop (for (int x : something)) works with containers/arrays, not with a single integer.

Since n is an integer, you should repeatedly extract its last digit using % 10 and remove it using / 10.

Also, your current loop has another subtle issue: num /= 10 would only modify the local loop variable, not n.


*/


class Solution {
public:
    //helperFun
    int calcaluteDigSum(int n) {  //tc=O(no of digits) = O(logN), sc=O(1)
        int sum = 0;
        
       while(n > 0) {
            int lastD = n % 10;
            sum += lastD;
            n /= 10;  //removingLast
        }
        
        return sum;
    }

    int calculateDigProd(int n) {
        int prod = 1;  //initilize with 1
        
        while(n > 0) {
            int lastD = n % 10;
            prod *= lastD;
            n /= 10;  
        }

        return prod;
    }


    bool checkDivisibility(int n) {
        //createTwo helperFunct
        int digSum = calcaluteDigSum(n), digProd = calculateDigProd(n);

        int totalSum = digSum + digProd;

        return (n % totalSum == 0); 
    }
};


//approach2: using singleLoop
class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int prod = 1;

        while (n > 0) {
            int digit = n % 10;

            sum += digit;
            prod *= digit;

            n /= 10;
        }

        return original % (sum + prod) == 0;
    }
};


//Approach 3: Using string  tc=(no of digits) = O(logN) = sc
#include <string>
bool checkDivisibility(int n) {
    string s = to_string(n);
    int sum = 0, prod = 1;

    for(char c : s) {
        int digit = c - '0';

        sum += digit;
        prod *= digit;
    }

    return n % (sum + prod) == 0;
    
}