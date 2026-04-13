


/*

13th April 2026 (Monday)

qno 1848  https://leetcode.com/problems/minimum-distance-to-the-target-element/?envType=daily-question&envId=2026-04-13

1848. Minimum Distance to the Target Element
Attempted
Easy
Topics

Companies
Hint
Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.

Return abs(i - start).

It is guaranteed that target exists in nums.

 

Example 1:

Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
Example 2:

Input: nums = [1], target = 1, start = 0
Output: 0
Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
Example 3:

Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
Output: 0
Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
0 <= start < nums.length
target is in nums.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
109,325/178.1K
Acceptance Rate
61.4%
Topics
Mid Level
Array
Weekly Contest 239

*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {  //tc=O(n), sc=O(1) this code run on some Testcase but not all
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                ans += abs(i - start);
                break;
            }
        }

        return ans;
    }
};


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {  //approch2
        int idx;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                idx = i;
                break;
            }
        }

        return abs(idx - start);
    }
};



class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) { //tc=O(n), sc=O(1)
        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                ans = min(ans, abs(i - start));  //minizedVal
            }
        }

        return ans;
    }
};


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                int dist = abs(i - start);
                
                if(dist == 0) return 0;  // 🔥 early exit
                
                ans = min(ans, dist);
            }
        }

        return ans;
    }
};


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        if(nums[start] == target) return 0;  // 🚀 fastest case

        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};