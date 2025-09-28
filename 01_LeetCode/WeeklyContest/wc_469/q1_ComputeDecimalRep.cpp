


/*

28th Sep 2025 (Sunday - 7th puja Maa Durga Navartri)

qno 01   https://leetcode.com/contest/weekly-contest-469/problems/compute-decimal-representation/



Code
Testcase
Testcase
Test Result
Q1. Compute Decimal Representation
Easy
3 pt.
You are given a positive integer n.

A positive integer is a base-10 component if it is the product of a single digit from 1 to 9 and a non-negative power of 10. For example, 500, 30, and 7 are base-10 components, while 537, 102, and 11 are not.
Express n as a sum of only base-10 components, using the fewest base-10 components possible.
Return an array containing these base-10 components in descending order.

 

Example 1:
Input: n = 537
Output: [500,30,7]
Explanation:
We can express 537 as 500 + 30 + 7. It is impossible to express 537 as a sum using fewer than 3 base-10 components.

Example 2
Input: n = 102
Output: [100,2]
Explanation:
We can express 102 as 100 + 2. 102 is not a base-10 component, which means 2 base-10 components are needed.

Example 3:
Input: n = 6
Output: [6]
Explanation:
6 is a base-10 component.

 

Constraints:
1 <= n <= 109



*/





// myfirst approach
vector<int> decimalRepresentation(int nums) { //rename n to nums 
    int n = nums.size(); //size of each nums //iterate to each digit in nums and return its 10th multiple place for(int i=0; i<n; i++) { if(nums[i] == 0) { //base case if zero in digit place then not return in final output pass; } else { return nums[i]* 10**n; } }

/*

which is very bad appraoch wrong 
Problems in your code:


1. vector<int> decimalRepresentation(int nums)
    Here nums is just a single integer, not a vector.
    So nums.size() doesn’t make sense.

2. You’re trying to iterate digit by digit, but you’re treating an integer as though it’s an array.
3. pass; is Python syntax, not valid in C++.

4.  10**n in C++ means XOR, not exponentiation.
    You should use pow(10, k) from <cmath>, or just multiply directly by place value.






Correct Approach:
Take integer n.
Extract each digit and its place value.
If digit ≠ 0, compute digit * (10^position).
Store these in a vector.
Return them in descending order.




*/









#include <vector>
#include <algorithm>  // for reverse
using namespace std;

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result; 
        long long place = 1;  // use 64-bit, to tracks the current power of 10 (1, 10, 100, ...)

        
        while (n > 0) {
            int digit = n % 10;  // extract the last digit

            if (digit != 0) {
                // form the base-10 component = digit * place
                result.push_back(digit * place);
            }

            n /= 10;       // move to next digit
            place *= 10;   // shift place value (units -> tens -> hundreds...)
        }

     
        // Reverse so they are in descending order as required.
        reverse(result.begin(), result.end());

        return result;
    }
};


// TC = O(log₁₀(n))  -> at most 10 iterations for n ≤ 1e9
// sc =  O(log₁₀(n))  -> stores at most one component per digit©leetcode