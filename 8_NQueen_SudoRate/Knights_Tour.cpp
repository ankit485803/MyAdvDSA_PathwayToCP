
#include <iostream>
using namespace std;
#include <vector>



// qno 2596  https://leetcode.com/problems/check-knight-tour-configuration/description/

class Solution {
public:

    bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expVal) {
        // Check bounds and if the current cell is the expected value
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
            return false;
        }

        // Base case: when the knight has reached the last cell
        if (expVal == n * n - 1) {
            return true;
        }

        // Explore the 8 possible knight moves (L-shaped)
        bool ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        bool ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        bool ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        bool ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        bool ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        bool ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        bool ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        bool ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

        // Return true if any of the 8 moves is valid
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // Check if the grid is valid starting from the top-left corner (0, 0) with the expected value 0
        return isValid(grid, 0, 0, n, 0);
    }
};


// TC = O(8* n^2),  SC = O(n^2)