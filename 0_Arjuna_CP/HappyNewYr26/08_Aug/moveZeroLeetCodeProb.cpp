

/*

26th Aug 2026 (Wednesday)

qno 283  https://leetcode.com/problems/move-zeroes/submissions/2120745763/

283. Move Zeroes
Solved
Easy
Topics

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
 
Discover more
Skill Enhancement Courses
Seen this question in a real interview before?
1/6
Yes
No
Accepted
5,571,829/8.7M
Acceptance Rate
64.3%
Topics
Array
Two Pointers

*/


class Solution {
public:
    //T.C -> O(N);
    //S.C -> O(1);
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        
        while(right<n){
            if(nums[right]!=0){
                swap(nums[right], nums[left]);
                left++;
            }
            right++;
        }
    }
};