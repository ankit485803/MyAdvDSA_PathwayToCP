


/*


26th Sep 2025 (Friday - fifth Puja Navratri)

qno 268   https://leetcode.com/problems/missing-number/



268. Missing Number
Easy
Topics
premium lock icon
Companies
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.



Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.


*/


//Optimized Solution (using sum formula):  TC=O(n), sc=O(1)
class Solution {  
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Sum of first n natural numbers is n * (n + 1) / 2
        int expected_sum = n * (n + 1) / 2;
        
        // Sum of elements in the input array
        int actual_sum = 0;
        for (int num : nums) {
            actual_sum += num;
        }
        
        // The missing number is the difference between the expected sum and actual sum
        return expected_sum - actual_sum;
    }
};





/
/*

qno  485  https://leetcode.com/problems/max-consecutive-ones/description/


What does for (int num : nums) mean?
This is called a range-based for loop in C++. It was introduced in C++11.





*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;
        
        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }
        
        return maxCount;
    }
};


//tc = O(n), sc=O(1)