


/*

10th May 2026 (Sunday)

qno 2770  https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/?envType=daily-question&envId=2026-05-10

2770. Maximum Number of Jumps to Reach the Last Index
Medium
Topics

Companies
Hint
You are given a 0-indexed array nums of n integers and an integer target.

You are initially positioned at index 0. In one step, you can jump from index i to any index j such that:

0 <= i < j < n
-target <= nums[j] - nums[i] <= target
Return the maximum number of jumps you can make to reach index n - 1.

If there is no way to reach index n - 1, return -1.

 

Example 1:

Input: nums = [1,3,6,4,1,2], target = 2
Output: 3
Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1. 
- Jump from index 1 to index 3.
- Jump from index 3 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 3 jumps. Hence, the answer is 3. 
Example 2:

Input: nums = [1,3,6,4,1,2], target = 3
Output: 5
Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1.
- Jump from index 1 to index 2.
- Jump from index 2 to index 3.
- Jump from index 3 to index 4.
- Jump from index 4 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 5 jumps. Hence, the answer is 5. 
Example 3:

Input: nums = [1,3,6,4,1,2], target = 0
Output: -1
Explanation: It can be proven that there is no jumping sequence that goes from 0 to n - 1. Hence, the answer is -1. 
 

Constraints:

2 <= nums.length == n <= 1000
-109 <= nums[i] <= 109
0 <= target <= 2 * 109
 
Discover more
Programming
Online project hosting
Seen this question in a real interview before?
1/6
Yes
No
Accepted
62,566/147.2K
Acceptance Rate
42.5%
Topics
Senior
Array
Dynamic Programming
Weekly Contest 353

*/


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {  //tc=O(n), sc=O(1) using bruteForce twoPointer appraoch
        int n = nums.size();

        int jumps = -1;

        //declare and initialize twoPointers
        int i=0, j=1;

        while(i<n && j<n) {
            if(nums[j] - nums[i] <= target) {
                jumps++;
            }
            i++;
            j++;
        }

        return jumps;
    }
};



class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);  //sc=O(n)

        dp[0] = 0;

        for (int i = 0; i < n; i++) {   //tc=O(n^2)
            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};



// bruteForce try all the possible give TLE 

class Solution {
public:
    int solve(int i, vector<int>& nums, int target) {  //tc=O(2^n) exponential, sc=O(n)
        int n = nums.size();

        // reached last index
        if (i == n - 1)
            return 0;

        int ans = -1;

        // try every possible jump
        for (int j = i + 1; j < n; j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                int jumps = solve(j, nums, target);

                if (jumps != -1) {
                    ans = max(ans, 1 + jumps);
                }
            }
        }

        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        return solve(0, nums, target);
    }
};



//Approach-1 (Recursion + Memo)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int n;

    int solve(int i, vector<int>& nums, int target, vector<int>& t) {
        if(i == n-1) {
            return t[i] = 0; //no more steps. reached destination
        }

        if(t[i] != INT_MIN) {
            return t[i];
        }

        int result = INT_MIN;

        for(int j = i+1; j < n; j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int temp = 1 + solve(j, nums, target, t);

                result = max(result, temp);
            }
        }

        return t[i] = result;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        vector<int> t(n+1, INT_MIN);

        int result = solve(0, nums, target, t);

        
        return result < 0 ? -1 : result;

    }
};



//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> t(n+1, INT_MIN);

        t[n-1] = 0;

        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target &&
                    t[j] != INT_MIN) {
                        int temp = 1 + t[j];

                        t[i] = max(t[i], temp);
                    }
            }
        }

        return t[0] < 0 ? -1 : t[0];

        
    }
};