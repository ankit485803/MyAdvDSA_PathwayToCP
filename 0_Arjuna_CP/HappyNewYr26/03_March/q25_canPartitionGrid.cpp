




/*


25th March 2026 (Wednesday)


qno 3546  https://leetcode.com/problems/equal-sum-grid-partition-i/?envType=daily-question&envId=2026-03-25


3546. Equal Sum Grid Partition I
Medium
Topics

Companies
Hint
You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.

 

Example 1:

Input: grid = [[1,4],[2,3]]

Output: true

Explanation:



A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

Example 2:

Input: grid = [[1,3],[2,4]]

Output: false

Explanation:

No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

 

Constraints:

1 <= m == grid.length <= 105
1 <= n == grid[i].length <= 105
2 <= m * n <= 105
1 <= grid[i][j] <= 105


*/



class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {  //tc=O(m * n) = sc
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> rowSum(m, 0);
        vector<ll> colSum(n, 0);

        ll total = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                total += grid[i][j];
                //row = i
                rowSum[i] += grid[i][j];
                //col = j
                colSum[j] += grid[i][j];
            } 
        }

        if(total % 2 != 0) {
            return false;
        }

        //horizontal split
        ll upper = 0;
        for(int i=0; i<m-1; i++) {
            upper += rowSum[i];
            if(upper == total - upper) {
                return true;
            }
        }

        //vertical split
        ll left = 0;
        for(int i=0; i<n-1; i++) {
            left += colSum[i];
            if(left == total - left) {
                return true;
            }
        }

        return false;
    }
};