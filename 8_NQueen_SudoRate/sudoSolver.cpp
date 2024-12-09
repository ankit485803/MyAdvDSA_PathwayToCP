

#include <iostream>
using namespace std;
#include <vector>

// qno 37  https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    // Check if placing digit 'dig' is safe in row, col
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == dig) {
                return false;
            }
        }

        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }

        // Check 3x3 subgrid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    // Helper function to solve Sudoku using backtracking
    bool helper(vector<vector<char>>& board, int row, int col) {
        // Base case: if we've reached the 9th row, return true (solved)
        if(row == 9) {
            return true;
        }

        // Move to the next column
        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // Skip cells that are already filled
        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits '1' to '9'
        for(char dig = '1'; dig <= '9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig; // Place the digit

                // Recursively solve the next cell
                if(helper(board, nextRow, nextCol)) {
                    return true;
                }

                board[row][col] = '.'; // Backtrack if the solution is not found
            }
        }

        return false;
    }

    // Main function to solve the Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0); // Start solving from the top-left corner
    }
};


// TC = O(9 ** no of empty cell)