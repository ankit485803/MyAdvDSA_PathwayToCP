

/*

15th Aug 2026 (Saturday)

qno 3702  https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/?envType=daily-question&envId=2026-08-15

3702. Longest Subsequence With Non-Zero Bitwise XOR
Solved
Medium
Topics

Companies
Hint
You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

 

Example 1:

Input: nums = [1,2,3]

Output: 2

Explanation:

One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:

Input: nums = [2,3,4]

Output: 3

Explanation:

The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
 
Discover more
Technical Skill Development
Seen this question in a real interview before?
1/6
Yes
No
Accepted
95,237/188K
Acceptance Rate
50.7%
Topics
Senior
Array
Bit Manipulation
Weekly Contest 470

*/


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Base case: all elements are 0
        bool allZero = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) return 0;


        
        // Main logic: compute XOR of all elements
        int xorAll = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorAll ^= nums[i];
        }

        //condition
        if (xorAll != 0) {
            return nums.size();
        } else {
            return nums.size() - 1;
        }
    }
};

//TC=o(n), sc-O(1)


//Approach (Simple Observation of XOR property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultXor = 0;
        bool allZero = true;

        for(int &x : nums) {
            resultXor ^= x;
            if(x != 0)
                allZero = false;
        }

        if(allZero)
            return 0;

        return resultXor == 0 ? n-1 : n;
    }
};