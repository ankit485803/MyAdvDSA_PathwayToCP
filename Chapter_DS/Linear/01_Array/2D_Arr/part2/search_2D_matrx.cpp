

#include <iostream>
using namespace std;
#include <vector>



// qno 74. https://leetcode.com/problems/search-a-2d-matrix/description/


/*Desceiption of prob:

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.



You must write a solution in O(log(m * n)) time complexity.


*/



// method1: Brute forca approach -- LinearSearch


// LinearSearch function that works with std::vector
bool LinearSearch(const vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                return true; // Target found
            }
        }
    }

    return false; // Target not found
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Call the LinearSearch function and return the result
        return LinearSearch(matrix, target);
    }
};


// TC = O(m*n)  where m is the number of rows and n is the number of columns, due to the nested loops iterating through all elements of the matrix.
// SC = O(1)



//method2: optimal--Binary Search

// row : range[start, end] -- unique & NON-OVERLAPPPING 


class Solution {
public:

    bool searchInRow(vector<vector<int>>& mat, int target, int row) {  //TC=O(logN)
        int n = mat[0].size();  
        int st = 0, end = n-1;

        while(st <= end) {
            int mid = st + (end-st)/2;
            if(target == mat[row][mid]) {
                return true;
            } else if(target > mat[row][mid]) {
                st = mid+1;

            } else  {
                end = mid-1;
            }
        }

        return false;

    }


    bool searchMatrix(vector<vector<int>>& mat, int target) {  //O(logN)
        // BS on total rows
        int m = mat.size(), n = mat[0].size();

        int startRow = 0, endRow = m-1;

        while(startRow <= endRow) {
            int midRow = startRow + (endRow-startRow)/2;

            if(target >= mat[midRow][0]  && target <= mat[midRow][n-1]) {
                //found the row => BS on this row
                return searchInRow(mat, target, midRow);
                
            } else if(target >= mat[midRow][n-1]  ){
                //down => right
                startRow = midRow + 1;

            } else {
                //up => Left
                endRow = midRow - 1;
            }
        }

        return false;
    }
};

// TC = O(log(m) + log(n)) = O(log(m*n)), SC = O(1)