
#include <iostream>
using namespace std;
#include <vector>


// qno 230   https://leetcode.com/problems/search-a-2d-matrix-ii/description/


/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.



*/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int r = 0,  c = n-1;  //row, cols
        while(r < m && c>= 0) {
            if(target == mat[r][c]) {
                return true;

            } else if(target < mat[r][c]) {
                c--;

            } else {
                r++;
            }
        }

        return false;
    }
};

// TC = O(n + m), SC = O(1)