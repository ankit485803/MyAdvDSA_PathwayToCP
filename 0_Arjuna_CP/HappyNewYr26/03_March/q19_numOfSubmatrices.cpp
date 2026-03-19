


/*

19th March 2026 (Thursday)


qno 3212 https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/?envType=daily-question&envId=2026-03-19

This is a classic 2D prefix sum + hashmap problem, very similar to “count subarrays with sum = 0”, but extended to matrices.




3212. Count Submatrices With Equal Frequency of X and Y
Medium
Topics

Companies
Hint
Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.
 

Example 1:

Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3

Explanation:



Example 2:

Input: grid = [["X","X"],["X","Y"]]

Output: 0

Explanation:

No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:

Input: grid = [[".","."],[".","."]]

Output: 0

Explanation:

No submatrix has at least one 'X'.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
31,242/57.5K
Acceptance Rate
54.4%
Topics
Staff
Array
Matrix
Prefix Sum
Weekly Contest 405


*/



//Approach (Using Same Cumulative Sum of Submatrices Concept we used in Leetcode 3070)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cumSumX(m, vector<int>(n, 0));
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if(i-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i-1][j];
                    cumSumY[i][j] += cumSumY[i-1][j];
                }

                if(j-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j-1];
                    cumSumY[i][j] += cumSumY[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i-1][j-1];
                    cumSumY[i][j] -= cumSumY[i-1][j-1];
                }
                
                if(cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;
                }
                

            }
        }

        return count;
    }
};