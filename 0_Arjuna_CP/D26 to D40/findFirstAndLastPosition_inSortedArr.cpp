


/*



2nd Sep 2025 (Tuesday) 

qno 34   https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/



34. Find First and Last Position of Element in Sorted Array

Medium
Topics

Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]


Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 


Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109


*/



class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int first = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                first = mid;       // possible answer
                end = mid - 1;     // but keep searching left
            } 
            else if (nums[mid] < target) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int last = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                last = mid;        // possible answer
                st = mid + 1;      // but keep searching right
            } 
            else if (nums[mid] < target) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};


/*

Time Complexity: O(log n) (two binary searches).
Space Complexity: O(1) (only variables used).

*/