

/*


11th March 2026 (Wednesday)


qno 1009  https://leetcode.com/problems/complement-of-base-10-integer/?envType=daily-question&envId=2026-03-11

1009. Complement of Base 10 Integer
Easy
Topics

Companies
Hint
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.

 

Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
Example 2:

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
Example 3:

Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
 

Constraints:

0 <= n < 109
 

Note: This question is the same as 476: https://leetcode.com/problems/number-complement/

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
375,397/606.5K
Acceptance Rate
61.9%
Topics
Junior
Bit Manipulation
Weekly Contest 128


*/


method1: bruteForce

step1: decimal n converts into binary
step2: flippinng the digits
step3: convert that flippedDigit into decimal and return it



class Solution {
public:
    int bitwiseComplement(int n) {  //tc=O(logN) = sc
        if(n == 0) return 1;

        vector<int> binary;

        // Step 1: decimal -> binary
        while(n > 0){
            binary.push_back(n % 2);
            n /= 2;
        }

        // Step 2: flip bits
        for(int &bit : binary){
            bit = !bit;
        }

        // Step 3: binary -> decimal
        int ans = 0;
        int power = 1;

        for(int bit : binary){
            ans += bit * power;
            power *= 2;
        }

        return ans;
    }
};




class Solution {
public:
    int bitwiseComplement(int n) {  //tc=O(logN), sc=O(1) using bitManipulation
        if(n == 0) return 1;

        int mask = 0;
        int temp = n;

        while(temp > 0){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return n ^ mask;
    }
};