

/*

27th June 2026 (Saturday)

qno 3020  https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/?envType=daily-question&envId=2026-06-27


3020. Find the Maximum Number of Elements in Subset
Solved
Medium
Topics

Companies
Hint
You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:

You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.

 

Example 1:

Input: nums = [5,4,1,2,2]
Output: 3
Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and 22 == 4. Hence the answer is 3.
Example 2:

Input: nums = [1,3,2,4]
Output: 1
Explanation: We can select the subset {1}, which can be placed in the array as [1] which follows the pattern. Hence the answer is 1. Note that we could have also selected the subsets {2}, {3}, or {4}, there may be multiple subsets which provide the same answer. 
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= 109
 
Discover more
Dictionaries & Encyclopedias
Seen this question in a real interview before?
1/6
Yes
No
Accepted
62,790/174.6K
Acceptance Rate
36.0%
Topics
Senior
Array
Hash Table
Enumeration
Weekly Contest 382


*/


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Frequency map for all elements
        // Time: O(n log(maxVal)), Space: O(n)
        unordered_map<long long, int> freq;
        int ones = 0;

        for (int num : nums) {
            freq[num]++;
            if (num == 1) ones++;
        }

        // Any odd-length subsequence of 1s is valid
        int ans = (ones % 2 == 0) ? ones - 1 : ones;

        // Remove 1s since they are already handled
        freq.erase(1LL);

        for (const auto& entry : freq) {
            long long num = entry.first;
            int count = 0;
            long long curr = num;

            // Follow the squaring chain: num -> num^2 -> num^4 -> ...
            while (freq.count(curr)) {
                if (freq[curr] >= 2) {
                    count += 2;  // Can take a pair at this level
                } else {
                    count++;     // Only one occurrence, end the chain
                    break;
                }

                // Prevent overflow when squaring
                if (curr > LLONG_MAX / curr) break;
                curr = curr * curr;
            }

            // Result must be odd
            if (count % 2 == 0) count--;

            ans = max(ans, count);
        }

        return ans;
    }
};