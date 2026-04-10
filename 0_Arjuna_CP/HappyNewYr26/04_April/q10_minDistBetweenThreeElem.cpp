

/*


10th April 2026 (Friday)

qno 3740  https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/?envType=daily-question&envId=2026-04-10

3740. Minimum Distance Between Three Equal Elements I
Easy
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

1 <= n == nums.length <= 100
1 <= nums[i] <= n
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
42,809/68.5K
Acceptance Rate
62.5%
Topics
Mid Level
Array
Hash Table
Weekly Contest 475



*/



class Solution {
public:
    int minimumDistance(vector<int>& nums) {  //bruteForce tc=O(n), sc=O(1)
        //take three idx pointer and initialize
        int i=0, j=1, k=2;

        int ans = -1;
        while(nums.size() > 2) {
            if(nums[i] == nums[j] == nums[k]) {  //good idx condition
                ans += abs(i-j) + abs(j-k) + abs(k-i);
                i++;
                j++;
                k++;
            }  //i miss the minDist criteria
        }

        return ans;
    }
};



/*
You’re on the right track thinking about indices, but your current approach has a few critical issues:
❌ Problems in your code

Wrong equality check
nums[i] == nums[j] == nums[k]
This does NOT check all three equal. It evaluates left to right:
(nums[i] == nums[j]) == nums[k]
which is incorrect..


Infinite loop
while(nums.size() > 2)
nums.size() never changes → loop never ends.
Not checking all triplets
You're only sliding (i, j, k) together → missing most combinations.


Wrong answer logic
You’re summing distances instead of taking minimum.
✅ Key Insight
For indices i < j < k, the distance simplifies:
|i - j| + |j - k| + |k - i|
= (j - i) + (k - j) + (k - i)
= 2 * (k - i)
👉 So we only need to minimize (k - i).



🚀 Optimal Approach
Store indices of each number.
For each number with ≥ 3 occurrences:
Check every consecutive triple.
Compute distance = 2 * (k - i).


*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {  //tc=O(n)=sc
        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // check each value
        for (auto &p : mp) {
            vector<int> &v = p.second;

            if (v.size() < 3) continue;

            // check consecutive triples
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};