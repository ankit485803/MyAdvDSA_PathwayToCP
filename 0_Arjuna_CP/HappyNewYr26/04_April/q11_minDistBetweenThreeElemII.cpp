

/*

11th April 2026 (Saturday)


qno 3741  https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-11


3741. Minimum Distance Between Three Equal Elements II
Medium
Topics

Companies
Hint
You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

 

Example 1:

Input: nums = [1,2,1,1,3]

Output: 6

Explanation:

The minimum distance is achieved by the good tuple (0, 2, 3).

(0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.

Example 2:

Input: nums = [1,1,2,3,2,1,2]

Output: 8

Explanation:

The minimum distance is achieved by the good tuple (2, 4, 6).

(2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8.

Example 3:

Input: nums = [1]

Output: -1

Explanation:

There are no good tuples. Therefore, the answer is -1.

 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= n
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
41,238/59.6K
Acceptance Rate
69.1%
Topics
Senior
Array
Hash Table
Weekly Contest 475


*/


//Approach - Optimal : Using map for storing indices and checking for 3 indices for a number 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for(int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];
                int siz = vec.size();

                int i = vec[siz-3];
                result = min(result, k-i);
            }
        }

        return result >= INT_MAX ? -1 : 2*result;
    }
};