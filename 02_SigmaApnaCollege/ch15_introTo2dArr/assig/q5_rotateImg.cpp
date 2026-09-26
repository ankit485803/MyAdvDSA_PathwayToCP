
git commit -m "feat(sigmaApnaCollege): done with assig ques and ready for newCh (ch15_introTo2dArr)" 
/*

26th Sep 2026 (Saturday)

qno 48  https://leetcode.com/problems/rotate-image/description/



*/

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