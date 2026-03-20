



/*


20th March 2026 (Friday)


qno 3567  https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/?envType=daily-question&envId=2026-03-20


3567. Minimum Absolute Difference in Sliding Submatrix
Medium
Topics

Companies
Hint
You are given an m x n integer matrix grid and an integer k.

For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.

Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.

Note: If all elements in the submatrix have the same value, the answer will be 0.

A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.
 

Example 1:

Input: grid = [[1,8],[3,-2]], k = 2

Output: [[2]]

Explanation:

There is only one possible k x k submatrix: [[1, 8], [3, -2]].
Distinct values in the submatrix are [1, 8, 3, -2].
The minimum absolute difference in the submatrix is |1 - 3| = 2. Thus, the answer is [[2]].
Example 2:

Input: grid = [[3,-1]], k = 1

Output: [[0,0]]

Explanation:

Both k x k submatrix has only one distinct element.
Thus, the answer is [[0, 0]].
Example 3:

Input: grid = [[1,-2,3],[2,3,5]], k = 2

Output: [[1,2]]

Explanation:

There are two possible k × k submatrix:
Starting at (0, 0): [[1, -2], [2, 3]].
Distinct values in the submatrix are [1, -2, 2, 3].
The minimum absolute difference in the submatrix is |1 - 2| = 1.
Starting at (0, 1): [[-2, 3], [3, 5]].
Distinct values in the submatrix are [-2, 3, 5].
The minimum absolute difference in the submatrix is |3 - 5| = 2.
Thus, the answer is [[1, 2]].
 

Constraints:

1 <= m == grid.length <= 30
1 <= n == grid[i].length <= 30
-105 <= grid[i][j] <= 105
1 <= k <= min(m, n)
 
Discover more
Technical interview guides
Seen this question in a real interview before?
1/5
Yes
No
Accepted
22,769/32.4K
Acceptance Rate
70.3%
Topics
Senior
Array
Sorting
Matrix
Weekly Contest 452


*/



//Approach - Iterate and check all k*k matrices
//T.C : O(O((m−k)×(n−k)×k^2×logk)
//S.C : O(k^2)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> result(m-k+1, vector<int>(n-k+1, 0));
        
        for (int i = 0; i <= m-k; i++) {
            for (int j = 0; j <= n-k; j++) {
                
                // Set for distinct + sorted
                set<int> vals;
                
                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.insert(grid[r][c]);
                    }
                }
                
                // If all elements were same, set has only 1 element
                if (vals.size() == 1) {
                    continue;
                }
                
                int minAbsDiff = INT_MAX;
                auto prev = vals.begin();
                auto curr = next(prev);
                
                while (curr != vals.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                
                result[i][j] = minAbsDiff;
            }
        }
        
        return result;
    }
};