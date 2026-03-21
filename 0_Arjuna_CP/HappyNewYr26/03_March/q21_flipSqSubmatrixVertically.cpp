

/*


21st March 2026 (Satursday)


qno 3643  https://leetcode.com/problems/flip-square-submatrix-vertically/?envType=daily-question&envId=2026-03-21

Code
Testcase
Testcase
Test Result
3643. Flip Square Submatrix Vertically
Easy
Topics

Companies
Hint
You are given an m x n integer matrix grid, and three integers x, y, and k.

The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.

 

Example 1:


Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3

Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]

Explanation:

The diagram above shows the grid before and after the transformation.

Example 2:

​​​​​​​
Input: grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2

Output: [[3,4,4,2],[2,3,2,3]]

Explanation:

The diagram above shows the grid before and after the transformation.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 100
0 <= x < m
0 <= y < n
1 <= k <= min(m - x, n - y)
 
Discover more
programming
Seen this question in a real interview before?
1/5
Yes
No
Accepted
98,683/128.5K
Acceptance Rate
76.8%
Topics
Mid Level
Array
Two Pointers
Matrix
Weekly Contest 462


*/



class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {  //tc=O(k^2), sc=O(1)
        int stRow = x, endRow = x+k-1;
        int stCol = y, endCol = y + k-1;

        for(int i=stRow; i<=endRow; i++) {
            for(int j=stCol; j<=endCol; j++) {
                swap(grid[i][j], grid[endRow][j] );
            }
            endRow--;
        }

        return grid;
    }
};



class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int stRow = x, endRow = x + k - 1;
        int stCol = y, endCol = y + k - 1;

        while (stRow < endRow) {
            for (int j = stCol; j <= endCol; j++) {
                swap(grid[stRow][j], grid[endRow][j]);
            }
            stRow++;
            endRow--;
        }

        return grid;
    }
};


