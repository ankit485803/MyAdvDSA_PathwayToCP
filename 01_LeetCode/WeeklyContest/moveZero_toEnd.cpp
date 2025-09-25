


/*

25th Sep 2025 (Thursday - fourth day puja Maa Durja)

qno 283     https://leetcode.com/problems/move-zeroes/



283. Move Zeroes
Easy
Topics
premium lock icon
Companies
Hint
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?

ankit learn:
nums is passed by reference (vector<int>& nums), so all modifications inside the function directly update the original array.
That’s why we don’t need return nums;.




*/



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZero = 0;

        // Step 1: Move all non-zero elements forward
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[lastNonZero++] = nums[i];
            }
        }

        // Step 2: Fill remaining positions with zeros
        for (int i = lastNonZero; i < n; i++) {
            nums[i] = 0;
        }
    }
};

// two pointe  appraoch O(n) time and O(1) extra space