


/*

2nd March 2026 (Monday)

qno 1536   https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/?envType=daily-question&envId=2026-03-02


1536. Minimum Swaps to Arrange a Binary Grid
Medium
Topics

Companies
Hint
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

 

Example 1:


Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
Example 2:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
Example 3:


Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
grid[i][j] is either 0 or 1
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
47,263/75.6K
Acceptance Rate
62.6%
Topics
Staff
Array
Greedy
Matrix
Weekly Contest 200


*/



class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();  //rows == column given squareMatrix

        vector<int> endZeros(n, 0);
        //endZeros[i] = count of consecutive 0s from the end of ith row

        for(int i=0; i<n; i++) {
            int j = n - 1;  //start from end

            int count = 0;
            while(j >=0 && grid[i][j] == 0) {
                count++;
                j--;
            }

            endZeros[i] = count;
        }

        int steps = 0;

        for(int i=0; i<n; i++) {  //tc=O(n^2) like bubbleSort, sc=O(1)
            int need = n - i -1;   //formulaMake

            int j = i;

            while(j<n && endZeros[j] < need) {
                j++;
            }

            if(j == n) {
                return -1;
            }

            steps += j-i;

            while(j > i) {
                swap(endZeros[j], endZeros[j-1]);
                j--;
            }
        }

        return steps;
    }
};

