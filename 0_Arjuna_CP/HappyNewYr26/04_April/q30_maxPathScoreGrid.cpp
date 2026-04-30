

/*

30th April 2026 (Thursday)

qno 3742  https://leetcode.com/problems/maximum-path-score-in-a-grid/?envType=daily-question&envId=2026-04-30

3742. Maximum Path Score in a Grid
Solved
Medium
Topics

Companies
Hint
You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

Each cell contributes a specific score and incurs an associated cost, according to their cell values:

0: adds 0 to your score and costs 0.
1: adds 1 to your score and costs 1.
2: adds 2 to your score and costs 1. ​​​​​​​
Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

 

Example 1:

Input: grid = [[0, 1],[2, 0]], k = 1

Output: 2

Explanation:​​​​​​​

The optimal path is:

Cell	grid[i][j]	Score	Total
Score	Cost	Total
Cost
(0, 0)	0	0	0	0	0
(1, 0)	2	2	2	1	1
(1, 1)	0	0	2	0	1
Thus, the maximum possible score is 2.

Example 2:

Input: grid = [[0, 1],[1, 2]], k = 1

Output: -1

Explanation:

There is no path that reaches cell (1, 1)​​​​​​​ without exceeding cost k. Thus, the answer is -1.

 

Constraints:

1 <= m, n <= 200
0 <= k <= 103​​​​​​​
​​​​​​​grid[0][0] == 0
0 <= grid[i][j] <= 2
 
Discover more
Programming language courses
Seen this question in a real interview before?
1/6
Yes
No
Accepted
37,175/80.7K
Acceptance Rate
46.1%
Topics
Staff
Array
Dynamic Programming
Matrix
Weekly Contest 475

*/


//Approach-2 (Bottom Up)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost, vector<vector<vector<int>>>& t) {
        if(i >= m || j >= n)
            return INT_MIN;
        
        int newCost = cost + (grid[i][j] > 0);

        if(newCost > k)
            return INT_MIN;
        
        if(i == m-1 && j == n-1)
            return grid[i][j]; //score
        
        if(t[i][j][cost] != -1) {
            return t[i][j][cost];
        }
        
        //down
        //right
        int down  = solve(grid, k, i+1, j, newCost, t);
        int right = solve(grid, k, i, j+1, newCost, t);

        int bestNext = max(down, right);

        if(bestNext == INT_MIN) {
            return t[i][j][cost] = INT_MIN;
        }

        return t[i][j][cost] = grid[i][j] + bestNext;
    }


    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));

        int result = solve(grid, k, 0, 0, 0, t);

        return result == INT_MIN ? -1 : result;
    }
};


//Approach-1 (Recursion + Memoization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(
            m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1))
        );

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] > 0);

                    if (newCost > k) continue;

                    // Base case: destination
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down  = -1;
                    int right = -1;

                    if (i + 1 < m)
                        down = t[i + 1][j][newCost];

                    if (j + 1 < n)
                        right = t[i][j + 1][newCost];

                    int bestNext = max(down, right);

                    if (bestNext != -1) {
                        t[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        return t[0][0][0];
    }
};