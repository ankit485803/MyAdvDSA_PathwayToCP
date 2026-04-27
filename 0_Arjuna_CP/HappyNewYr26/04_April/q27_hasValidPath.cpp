

/*

27th April 2026 (Monday)


qno 1391  https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/?envType=daily-question&envId=2026-04-27

1391. Check if There is a Valid Path in a Grid
Solved
Medium
Topics

Companies
Hint
You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 

Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6
 
Discover more
Skill development programs
Seen this question in a real interview before?
1/6
Yes
No
Accepted
56,452/99.5K
Acceptance Rate
56.7%
Topics
Staff
Array
Depth-First Search
Breadth-First Search
Union-Find
Matrix
Weekly Contest 181

*/



//Approach (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;

    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}}
    };

    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i == m-1 && j == n-1)
            return true;
        
        visited[i][j] = true;

        for(auto &dir : directions[grid[i][j]]) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited[new_i][new_j])
                continue;
            
            //IMPORTANT = can you come back to i and j from new_i and new_j
            for(auto &backDir : directions[grid[new_i][new_j]]) {
                if(new_i + backDir[0] == i &&
                   new_j + backDir[1] == j) {
                        if(dfs(grid, new_i, new_j, visited)) {
                            return true;
                        }
                   }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //T.C : O(m*n)

        return dfs(grid, 0, 0, visited);
    }
};


