



/*

22nd Dec 2025 (Monday)






qno 3780  https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/


3780. Maximum Sum of Three Numbers Divisible by Three
Solved
Medium

Companies
Hint
You are given an integer array nums.

Your task is to choose exactly three integers from nums such that their sum is divisible by three.

Return the maximum possible sum of such a triplet. If no such triplet exists, return 0.

 

Example 1:

Input: nums = [4,2,3,1]

Output: 9

Explanation:

The valid triplets whose sum is divisible by 3 are:

(4, 2, 3) with a sum of 4 + 2 + 3 = 9.
(2, 3, 1) with a sum of 2 + 3 + 1 = 6.
Thus, the answer is 9.

Example 2:

Input: nums = [2,1,5]

Output: 0

Explanation:

No triplet forms a sum divisible by 3, so the answer is 0.

 

Constraints:

3 <= nums.length <= 105
1 <= nums[i] <= 105



*/





class Solution {
public:
    int maximumSum(vector<int>& nums) {   //greedy tc=O(n logN), sc=O(n)
        vector<int> r0, r1, r2;
        
        // Split by remainder
        for (int x : nums) {
            if (x % 3 == 0) r0.push_back(x);
            else if (x % 3 == 1) r1.push_back(x);
            else r2.push_back(x);
        }
        
        // Sort descending
        sort(r0.begin(), r0.end(), greater<int>());
        sort(r1.begin(), r1.end(), greater<int>());
        sort(r2.begin(), r2.end(), greater<int>());
        
        int ans = 0;
        
        // Case 1: three from same remainder
        if (r0.size() >= 3)
            ans = max(ans, r0[0] + r0[1] + r0[2]);
        
        if (r1.size() >= 3)
            ans = max(ans, r1[0] + r1[1] + r1[2]);
        
        if (r2.size() >= 3)
            ans = max(ans, r2[0] + r2[1] + r2[2]);
        
        // Case 2: one from each remainder
        if (!r0.empty() && !r1.empty() && !r2.empty())
            ans = max(ans, r0[0] + r1[0] + r2[0]);
        
        return ans;
    }
};
