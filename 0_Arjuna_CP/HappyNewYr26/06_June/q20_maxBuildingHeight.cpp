

/*

20th June 2026 (Saturday)


qno 1840  https://leetcode.com/problems/maximum-building-height/?envType=daily-question&envId=2026-06-20

1840. Maximum Building Height
Solved
Hard
Topics

Companies
Hint
You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

However, there are city restrictions on the heights of the new buildings:

The height of each building must be a non-negative integer.
The height of the first building must be 0.
The height difference between any two adjacent buildings cannot exceed 1.
Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

Return the maximum possible height of the tallest building.

 

Example 1:


Input: n = 5, restrictions = [[2,1],[4,1]]
Output: 2
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
Example 2:


Input: n = 6, restrictions = []
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
Example 3:


Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
 

Constraints:

2 <= n <= 109
0 <= restrictions.length <= min(n - 1, 105)
2 <= idi <= n
idi is unique.
0 <= maxHeighti <= 109
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
37,660/64K
Acceptance Rate
58.9%
Topics
Senior Staff
Array
Math
Sorting
Weekly Contest 238

*/


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& nums) {

        // Let m = number of restricted buildings
        // Time:  O(m log m) for sorting + O(m) for the passes
        // Space: O(m)

        sort(nums.begin(), nums.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int len = nums.size();
        if (len == 0) return n - 1; // No restrictions, max height bounded only by edges

        // Check if the last building already has a restriction
        bool isLast = (nums[len - 1][0] == n);

        // Total points to process: restrictions + building 1 + (building n if not already included)
        int m = len + 1 + (isLast ? 0 : 1);

        vector<vector<int>> h(m, vector<int>(2, 0)); // h[i] = {position, max height at position}
        h[0][0] = 1;
        h[0][1] = 0; // Building 1 has height 0

        // Left-to-right pass: propagate max possible height forward, capped by restrictions
        for (int i = 0; i < len; i++) {
            int diff = nums[i][0] - h[i][0];
            int ht = h[i][1] + diff;
            h[i + 1][0] = nums[i][0];
            h[i + 1][1] = min(ht, nums[i][1]);
        }

        // Add building n if it wasn't part of the restrictions
        if (!isLast) {
            int diff = n - h[len][0];
            int ht = h[len][1] + diff;
            h[len + 1][0] = n;
            h[len + 1][1] = min(ht, n - 1);
        }

        // Right-to-left pass: propagate max possible height backward, capped similarly
        for (int i = m - 2; i >= 0; i--) {
            int diff = h[i + 1][0] - h[i][0];
            int ht = h[i + 1][1] + diff;
            h[i][1] = min(h[i][1], ht);
        }

        // For each consecutive pair of capped points, compute the max peak height achievable between them
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int left = h[i - 1][0];
            int right = h[i][0];
            int h1 = h[i - 1][1];
            int h2 = h[i][1];

            // Peak height formula: average the "slack" distance and add to the taller endpoint
            int mx = (right - left - abs(h1 - h2)) / 2 + max(h1, h2);
            ans = max(ans, mx);
        }

        return ans;
    }
};