


/*


18th April 2026 (Saturday)


qno 3483  https://leetcode.com/problems/mirror-distance-of-an-integer/?envType=daily-question&envId=2026-04-18

3783. Mirror Distance of an Integer
Solved
Easy
Topics

Companies
Hint
You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.

 

Example 1:

Input: n = 25

Output: 27

Explanation:

reverse(25) = 52.
Thus, the answer is abs(25 - 52) = 27.
Example 2:

Input: n = 10

Output: 9

Explanation:

reverse(10) = 01 which is 1.
Thus, the answer is abs(10 - 1) = 9.
Example 3:

Input: n = 7

Output: 0

Explanation:

reverse(7) = 7.
Thus, the answer is abs(7 - 7) = 0.
 

Constraints:

1 <= n <= 109
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
81,927/91K
Acceptance Rate
90.0%
Topics
Mid Level
Math
Weekly Contest 481


*/


class Solution {
public:
    int mirrorDistance(int n) { //sc=O(1)  old submission on 24th Dec 2025
        //step1: Rev 
        int R = 0;
        int original = n;
        
        // ReverseNum - tc=O(n)
        while (n > 0) {
            R = R * 10 + (n % 10);  // Get the last digit and add it to R
            n /= 10;  // Remove the last digit from n
        }

        //step2: calculateDiff
        int diff = original - R;

        return abs(diff);
    }
};



class Solution {
public:
    int mirrorDistance(int n) {  //sc=O(1)  yah aag wala hai submission
        int original = n;

        //step1: reverse the n, tc=O(digits)
        int revN = 0;
        while(n > 0) {
            revN = revN * 10 + (n % 10);
            n /= 10;
        }

        //step2: calculate abs diff
        int mirrDist = abs(original - revN);
        return mirrDist;
    }
};


class Solution {
public:
    int mirrorDistance(int n) {  //sc=O(1)
        int original = n;

        //step1: reverse the n, tc=O(digits)
        int revN = 0;
        while(n > 0) {
            revN = revN * 10 + (n % 10);  //revN*10 + lastDigit
            n /= 10;  //removeLastD
        }

        //step2: calculate abs diff
        int mirrDist = abs(original - revN);
        return mirrDist;
    }
};