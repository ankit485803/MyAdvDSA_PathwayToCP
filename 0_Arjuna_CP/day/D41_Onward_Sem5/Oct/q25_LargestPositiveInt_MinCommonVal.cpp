




/*

4th Nov 2025 (Tuesday - at lastDay myHome from Diwali to ChhathPuja)


qno 2441   https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/ 



2441. Largest Positive Integer That Exists With Its Negative
Attempted
Easy
Topics

Companies
Hint
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

 

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
 

Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0



*/


class Solution {
public:
    int findMaxK(vector<int>& nums) {  //TC=O(nLogN), SC=O(1)
        // Step 1: sortArr
        sort(nums.begin(), nums.end());
        
        int maxK = -1;
        
        // Step 2: Check for each number if its negative exists
        for (int i = 0; i < nums.size(); i++) {
            // We need to check only positive numbers for the largest k
            if (nums[i] > 0 && myBinarySearch(nums, -nums[i])) {
                maxK = max(maxK, nums[i]);
            }
        }
        
        return maxK;
    }
    


    // Step 3: Binary search to find if the negative number exists
    bool myBinarySearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return false;
    }
};



#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int findMaxK(vector<int>& nums) {  //TC=o(n), SC=O(n) due to unorderedSet
        unordered_set<int> numSet;
        
        // Step 1: Insert all elements into the set
        for (int num : nums) {
            numSet.insert(num);
        }
        
        int maxK = -1;
        

        // Step 2: Iterate through the set and check for each number if its negative exists
        for (int num : nums) {
            if (numSet.count(-num)) {
                maxK = max(maxK, abs(num));  // We take the absolute value because k must be positive
            }
        }
        
        return maxK;
    }
};





/*


qno 2540   https://leetcode.com/problems/minimum-common-value/description/


2540. Minimum Common Value
Easy
Topics

Companies
Hint
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.


*/



class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {  //TC=O(m+n), sc=O(1)
        int i = 0, j = 0;

        //twoPointerApproach
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];  // Found the smallest common value
            }
            else if (nums1[i] < nums2[j]) {
                i++;  // Move forward in nums1
            }
            else {
                j++;  // Move forward in nums2
            }
        }

        return -1;  // No common element found
    }
};




/*




*/