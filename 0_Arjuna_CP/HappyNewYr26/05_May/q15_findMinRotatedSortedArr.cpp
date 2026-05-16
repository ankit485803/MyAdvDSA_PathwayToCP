

/*

15th May 2026 (Friday)


qno 153  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-15
alreadySolved on 22nd Sep 2025 using BinarySearch

153. Find Minimum in Rotated Sorted Array
Solved
Medium
Topics

Companies
Hint
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
 
Discover more
Personalized learning paths
Seen this question in a real interview before?
1/6
Yes
No
Accepted
3,047,556/5.6M
Acceptance Rate
54.3%
Topics
Array
Binary Search

*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2;

            // If mid element is greater than rightmost, min is in right half
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                // Otherwise, min is in left half (including mid)
                end = mid;
            }
        }
        
        // At the end, st == end -> pointing to minimum
        return nums[st];
    }
};

//tc=O(log N), sc=O(1)




class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());   //using c++ STL tc=O(N), sc=O(1)

        return min;
    }
};

//method2 - binarySearch tc=O(logN), sc=O(1)



class Solution {
public:
    int findMin(vector<int>& nums) {  //tc=O(logN), sc=O(1) using BS
        int n = nums.size();

        int l = 0, r = n-1;

        while(l < r) {
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[r];
    }
};

