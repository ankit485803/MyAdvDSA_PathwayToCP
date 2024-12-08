
#include <iostream>
using namespace std;
#include <vector>


// qno 51   https://leetcode.com/problems/n-queens/


class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) { // O(n)
        // Check the current row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check the current column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check the upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check the upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) { // O(n)
        // If all queens are placed, add the solution to the answer list
        if (row == n) {
            ans.push_back(board);  // Corrected this line
            return;
        }

        // Try placing a queen in each column of the current row
        for (int j = 0; j < n; j++) {  // Corrected this line
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';  // Place the queen
                nQueens(board, row + 1, n, ans);  // Recurse for the next row
                board[row][j] = '.';  // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));  // Initialize the board
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);  // Start solving from the first row
        return ans;
    }
};


// TC = O(n!) , SC = O(n) -- using backtracking