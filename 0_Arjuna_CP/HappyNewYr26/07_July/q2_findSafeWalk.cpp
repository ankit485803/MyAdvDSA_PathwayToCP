

/*

2nd July 2026 (Thursday)

qno 3286  https://leetcode.com/problems/find-a-safe-walk-through-a-grid/?envType=daily-question&envId=2026-07-02

3286. Find a Safe Walk Through a Grid
Solved
Medium
Topics

Companies
Hint
You are given an m x n binary matrix grid and an integer health.

You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 

Example 1:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.


Example 2:

Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.


Example 3:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.



Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
2 <= m * n
1 <= health <= m + n
grid[i][j] is either 0 or 1.
 
Discover more
Developer Job Board
Seen this question in a real interview before?
1/6
Yes
No
Accepted
79,999/170.7K
Acceptance Rate
46.9%
Topics
Staff
Array
Breadth-First Search
Graph Theory
Heap (Priority Queue)
Matrix
Shortest Path
Biweekly Contest 139

Companies

*/



//Appoach-1 Using Dijkstra's
//T.C : O(E · log V) = O(m·n · log(m·n))
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, pair<int,int>> P;

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        result[0][0] = grid[0][0]; //Source = {0, 0}
        pq.push({result[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (d > result[r][c]) continue;

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (d + grid[nr][nc] < result[nr][nc]) {
                    result[nr][nc] = d + grid[nr][nc];
                    pq.push({d + grid[nr][nc], {nr, nc}});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};


//Appoach-2 (Using 0-1 BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        result[0][0] = grid[0][0]; //source {0, 0}
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (result[r][c] + grid[nr][nc] < result[nr][nc]) {

                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if (grid[nr][nc] == 0) 
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};