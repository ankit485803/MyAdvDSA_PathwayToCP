

/*

4th March 2026 (Wednesday)


qno 1582   https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2026-03-04


1582. Special Positions in a Binary Matrix
Attempted
Easy
Topics

Companies
Hint
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
183,009/262.5K
Acceptance Rate
69.7%
Topics
Mid Level
Array
Matrix
Weekly Contest 206


*/


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {  //tc=O(n^2), sc=O(1) usingTwoPointer
        int n = mat.size();  //size of matrix

        int countS = 0;  //spcialPosition

        for(int i=0; i<n; i++) {
            for(int j=n; j>=0; j--) {  //innerLoop starts in revOrder
                if(mat[i][j] == 1 && rest all zero) {
                    countS++;
                }
            }
        }

        return countS;
    }
};




class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {  //tc=O(m*n), sc=O(m+n)
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Count 1s in each row and column
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int countS = 0;
        
        // Check for special positions
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    countS++;
                }
            }
        }
        
        return countS;
    }
};