




/*

21st Sep 2025 (Sunday) weekly contest 468 

qno 1 https://leetcode.com/contest/weekly-contest-468/problems/bitwise-or-of-even-numbers-in-an-array/

Learning from this prob Ankit:
we don't need to first convert the decimal to binary then calcaute bitwise or: In C++ (and all modern programming languages), 
digits and numbers are already stored internally in binary format. 
The bitwise OR operator (`|`) works directly on the binary representations of the values you're comparing. The CPU doesn't need to do any conversions or calculations beyond the core OR logic on each bit.



✅ Summary:
Numbers/digits → stored directly as binary integers.
Characters → stored as binary codes (ASCII/Unicode).
Words (strings) → stored as a sequence of character codes in binary.













Q1. Bitwise OR of Even Numbers in an Array
Solved
Easy
3 pt.
You are given an integer array nums.
Return the bitwise OR of all even numbers in the array.
If there are no even numbers in nums, return 0.

 

Example 1:
Input: nums = [1,2,3,4,5,6]
Output: 6
Explanation:
The even numbers are 2, 4, and 6. Their bitwise OR equals 6.

Example 2:
Input: nums = [7,9,11]
Output: 0
Explanation:
There are no even numbers, so the result is 0.

Example 3:
Input: nums = [1,8,16]
Output: 24
Explanation:
The even numbers are 8 and 16. Their bitwise OR equals 24.

 

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100©leetcode





*/



class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;  // start with 0 since OR with 0 has no effect

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {   // check if even
                result |= nums[i];    // bitwise OR with result
            }
        }

        return result;
    }
};


// TC=O(n), sc=O(1)©leetcode