


/*

Matrix Similarity After Cyclic Shifts


27th March 2026 (Friday)


qno 2946  https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/?envType=daily-question&envId=2026-03-27


2946. Matrix Similarity After Cyclic Shifts
Attempted
Easy
Topics

Companies
Hint
You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

The following proccess happens k times:

Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.


Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.


Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

Output: false

Explanation:

In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).



Example 2:

Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2

Output: true

Explanation:



Example 3:

Input: mat = [[2,2],[2,2]], k = 3

Output: true

Explanation:

As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.

 

Constraints:

1 <= mat.length <= 25
1 <= mat[i].length <= 25
1 <= mat[i][j] <= 25
1 <= k <= 50
 
Discover more
Mathematics
Mock interview sessions
Seen this question in a real interview before?
1/5
Yes
No
Accepted
68,789/99.2K
Acceptance Rate
69.3%
Topics
Mid Level
Array
Math
Matrix
Simulation
Weekly Contest 373


*/


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) { //tc=O(m * n)=sc
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;

        if(k == 0) {  //no shifting
            return true;
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                int currIdx = j;
                int finalIdx;

                if(i % 2 == 0) { //even
                    finalIdx = (j + k) % n;  //for perserve CYCLIC nature to take modulo
                } else {
                    finalIdx = (j - k + n) % n;
                }

                if(mat[i] [currIdx] != mat[i] [finalIdx]) {
                    return false;
                }
            }
        }

        return true;
    }
};





//Approach-1 (Simulation + extra space)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat;
        int m = mat.size();
        int n = mat[0].size();
        k = k%n;
        if(k == 0) { //no shifting
            return true;
        }
      
        for(int i = 0; i<m; i++) {
            if(i%2) { // odd
                rotate(rbegin(mat[i]), rbegin(mat[i]) + k, rend(mat[i]));
            } else {
                rotate(begin(mat[i]), begin(mat[i]) + k, end(mat[i]));
            }
        }

        return temp == mat;
    }
};


//Approach-2 (Without rotation and O(1) space)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = (k%n);

        if(k == 0) { //no shifting
            return true;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int currIdx = j;
                int finalIdx;

                if(i % 2 == 0) { //even : left shift
                    finalIdx = (j + k)%n;
                } else {
                    finalIdx = (j - k + n) % n;
                }

                if(mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }

            }
        }

        return true;
    }
};
