

/*

16th May 2026 (Saturday)

qno 154  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?envType=daily-question&envId=2026-05-16

same yesterday wala prob

154. Find Minimum in Rotated Sorted Array II
Solved
Hard
Topics

Companies
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.
 

Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

 

 
Discover more
Skill Enhancement Workshops
Seen this question in a real interview before?
1/6
Yes
No
Accepted
640,845/1.4M
Acceptance Rate
45.3%
Topics
Array
Binary Search


*/


class Solution {
public:
    int findMin(vector<int>& nums) {  //using STL tc=O(n), sc=O(1)
        int ans = *min_element(nums.begin(), nums.end());

        return ans;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = n-1;  //left right

        while(l < r) {
            int mid = l + (r - l)/2;
            
            if(nums[mid] > nums[r]) {  //tc=O(logN)  using BS
                l = mid+1;
            } else {
                r = mid;
            }
        }

        return nums[r];
    }
};




class Solution {
public:
    int findMin(vector<int>& nums) {  //tc=O(n) dueToDuplicate even used BS, sc=O(1)
        int n = nums.size();
        
        int l = 0, r = n-1;  //left right
        int resultIdx = 0;

        while(l <= r) {

            while(l < r && nums[l] == nums[l+1] ) l++;
            while(r > l && nums[r] == nums[r - 1] ) r--;

            int mid = l + (r - l)/2;
            
            if(nums[mid] < nums[resultIdx]) {
                resultIdx = mid;
            }

            if(nums[mid] > nums[r]) {  //rotated
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return nums[resultIdx];
    }
};