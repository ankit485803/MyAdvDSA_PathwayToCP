

/*

6th Aug 2026 (Thursday)

qno 3345  https://leetcode.com/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06

3345. Smallest Divisible Digit Product I
Easy
Topics

Companies
Hint
You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

 

Example 1:

Input: n = 10, t = 2

Output: 10

Explanation:

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:

Input: n = 15, t = 3

Output: 16

Explanation:

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

 

Constraints:

1 <= n <= 100
1 <= t <= 10
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
114,937/161.7K
Acceptance Rate
71.1%
Topics
Mid Level
Math
Enumeration
Biweekly Contest 143

*/



class Solution {
public:
    int smallestNumber(int n, int t) {
        //bruteForce appraoch tc=O(n), sc=O(1)   myFirst approach

        int ans = 0; //smalllestNo

        for(int i = n; i >= n; i++) {
            //for each numb we have to check prod divisibility
            int digit = n % 10;
            int prod = digit * i;
            n /= 2;  //removeLastD

            if(prod % t == 0) {
                ans = n;
            }
            return ans;
        }
    }
};



/*
Your approach has several issues:

You're using n instead of the current number i.
n /= 2 should be temp /= 10 to remove the last digit.
The product should be of all digits, not digit * i.
for(int i = n; i >= n; i++) is effectively an infinite loop unless you return; it should increment i.
You should return the first number whose digit product is divisible by t.

A simple brute-force solution works because n <= 100 and t <= 10.


Line 5: Char 27: error: expected ';' in 'for' statement specifier
    5 |         for(int i = n; i++) {
      |                           ^
1 error generated.

*/

