


/*

27th Sep 2025 (Satursday - sixth day puja)

qno  162   https://leetcode.com/problems/find-peak-element/description/



162. Find Peak Element
Medium
Topics

Companies
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {  //O(log N) using BinarySearch 
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak is in the left half (including mid)
                right = mid;
            } else {
                // Peak is in the right half
                left = mid + 1;
            }
        }
        
        return left; // left == right, the peak index
    }
};


/*

Q. here is not target like in binary search we cosnider
Instead of comparing against a fixed target, we compare adjacent elements (nums[mid] vs nums[mid+1]) to decide which half must contain a peak.




*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {  //BruteForce - TC = O(N), SC=O(1)
        // Step 1: find the maximum element
        int maxElem = *max_element(nums.begin(), nums.end());

        // Step 2: return the index of that element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxElem) {
                return i;
            }
        }
        return -1; // should never happen
    }
};
