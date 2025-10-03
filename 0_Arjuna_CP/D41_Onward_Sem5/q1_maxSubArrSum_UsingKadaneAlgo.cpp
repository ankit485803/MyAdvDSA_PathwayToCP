

/*

3rd Oct 2025 (Friday)


qno  53  https://leetcode.com/problems/maximum-subarray/

Kadane's Algorithm is a dynamic programming algorithm used to find the maximum sum of a contiguous subarray within a one-dimensional
 array of numbers. It is particularly efficient, solving the problem in linear time complexity, O(n), with constant space complexity, O(1)




53. Maximum Subarray
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.



Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


*/




class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = INT_MIN;

        //method1: BruteForce approach - two pointer - O(n^2) time and SC=O(1), but this give TLE error
        for(int st=0; st<n; st++) {
            int currSum = 0;
            for(int end=st; end<n; end++) {
                currSum += nums[end];
                maxSum = max(currSum,  maxSum);

            }
        }

        return maxSum;
    }
};






class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;


        //method3:  optimized using  Kande DP Algo  - TCO(n), SC=O(1) 
        for(int val : nums) {
            currSum += val;
            maxSum = max(currSum, maxSum);

            if(currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }

};