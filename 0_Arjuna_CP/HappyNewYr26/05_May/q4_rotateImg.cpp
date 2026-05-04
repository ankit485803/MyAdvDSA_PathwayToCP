

/*

4th May 2026 (Monday)


qno 48  https://leetcode.com/problems/rotate-image/?envType=daily-question&envId=2026-05-04

48. Rotate Image
Attempted
Medium
Topics

Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
 
Discover more
Math
Mathematics
Seen this question in a real interview before?
1/6
Yes
No
Accepted
2,858,216/3.6M
Acceptance Rate
79.8%
Topics
Array
Math
Matrix

*/



class Solution {  //fistAttempt
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res(n, vector<int>(n));   //sc=O(n^2)

        for(int i=0; i < n; i++) {  //tc=O(n^2)
            for(int j=0; j<n; j++) {
                res[j][n - 1 - i] = matrix[i][j];  //mainLogic lastRow into firstCol
            }
        }
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res(n, vector<int>(n));   //sc=O(n^2)

        for(int i=0; i < n; i++) {  //tc=O(n^2)
            for(int j=0; j<n; j++) {
                res[j][n - 1 - i] = matrix[i][j];  //mainLogic lastRow into firstCol
            }
        }

        //copyToOriginal
        matrix = res;
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {  //tc=O(n^2), sc=O(1)
        int n = matrix.size();

        //step1: transpose
        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);    //diagonally
            }
        }

        //step2: revEachRow to get clockwise 90 deg
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};





// https://leetcode.com/contest/weekly-contest-500/problems/count-indices-with-opposite-parity/description/
// https://leetcode.com/contest/weekly-contest-500/problems/sum-of-primes-between-number-and-its-reverse/
// https://leetcode.com/contest/weekly-contest-500/problems/minimum-cost-to-move-between-indices/description/
