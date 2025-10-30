


/*


30th Oct 2025 (Thursday)  


qno 3701   https://leetcode.com/problems/compute-alternating-sum/


3701. Compute Alternating Sum
Solved
Easy
Topics

Companies
Hint
You are given an integer array nums.

The alternating sum of nums is the value obtained by adding elements at even indices and subtracting elements at odd indices. That is, nums[0] - nums[1] + nums[2] - nums[3]...

Return an integer denoting the alternating sum of nums.

 

Example 1:

Input: nums = [1,3,5,7]

Output: -4

Explanation:

Elements at even indices are nums[0] = 1 and nums[2] = 5 because 0 and 2 are even numbers.
Elements at odd indices are nums[1] = 3 and nums[3] = 7 because 1 and 3 are odd numbers.
The alternating sum is nums[0] - nums[1] + nums[2] - nums[3] = 1 - 3 + 5 - 7 = -4.
Example 2:

Input: nums = [100]

Output: 100

Explanation:

The only element at even indices is nums[0] = 100 because 0 is an even number.
There are no elements on odd indices.
The alternating sum is nums[0] = 100.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


*/




class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {  // TC=O(n), sc=O(1)
            if (i % 2 == 0)
                sum += nums[i];  // even index: add
            else
                sum -= nums[i];  // odd index: subtract
        }
        return sum;
    }
};



/*

qno 2544  https://leetcode.com/problems/alternating-digit-sum/

2544. Alternating Digit Sum
Easy
Topics

Companies
Hint
You are given a positive integer n. Each digit of n has a sign according to the following rules:

The most significant digit is assigned a positive sign.
Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.

 

Example 1:

Input: n = 521
Output: 4
Explanation: (+5) + (-2) + (+1) = 4.
Example 2:

Input: n = 111
Output: 1
Explanation: (+1) + (-1) + (+1) = 1.
Example 3:

Input: n = 886996
Output: 0
Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.
 

Constraints:

1 <= n <= 109



*/


class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n); // Convert integer to string
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0'; // Convert char to int
            
            // Add or subtract based on position (starting with + for most significant digit)
            if (i % 2 == 0) {
                sum += digit;
            } else {
                sum -= digit;
            }
        }

        return sum;
    }
};


//TC=O(n), sc=O(1)