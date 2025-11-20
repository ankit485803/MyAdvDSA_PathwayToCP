




/*

24th Oct 2025 (Friday)


qno 2133   https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/

2133. Check if Every Row and Column Contains All Numbers
Attempted
Easy
Topics

Companies
Hint
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

 

Example 1:


Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.
Example 2:


Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n



*/




class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {  //TC=O(n^2), SC=O(n)
        int n = matrix.size();

        // CheckRow  TC=O(n^2)
        for (int i = 0; i < n; i++) {
            unordered_set<int> rowSet;
            for (int j = 0; j < n; j++) {
                rowSet.insert(matrix[i][j]);  
            }
            if (rowSet.size() != n) return false;
        }

        // Check each column - TC=O(n^2)
        for (int j = 0; j < n; j++) {
            unordered_set<int> colSet;
            for (int i = 0; i < n; i++) {
                colSet.insert(matrix[i][j]);  
            }
            if (colSet.size() != n) return false;
        }

        return true;  
    }
};



