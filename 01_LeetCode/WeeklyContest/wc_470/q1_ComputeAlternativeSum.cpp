

/*


5th Oct 2025 (Sunday)


q1  https://leetcode.com/contest/weekly-contest-470/problems/compute-alternating-sum/

In C++, void, int, and bool are fundamental data types. void signifies the absence of a value, typically used for functions that don't return anything. int represents integer numbers, and its size can vary depending on the system. bool is a boolean type, representing truth values: true or false





Q1. Compute Alternating Sum
Easy
3 pt.
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
1 <= nums[i] <= 100©leetcode


*/





class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0)
                sum += nums[i];  // even place index: add
            else
                sum -= nums[i];  // odd place index: subtract
        }
        return sum;
    }
};


// TC=O(n), sc=O(1) 