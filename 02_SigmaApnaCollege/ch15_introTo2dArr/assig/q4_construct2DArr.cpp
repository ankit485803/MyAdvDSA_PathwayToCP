

/*

24th Sep 2026 (Thursday)

qno 2022  https://leetcode.com/problems/convert-1d-array-into-2d-array/

ansMatr[i][j] = original[i * n + j];

*/


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        // Impossible to create m*n cells
        if (original.size() != m * n) {
            return {};
        }

        vector<vector<int>> ansMatr(m, vector<int>(n));  //sc=O(m * n) =sc

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ansMatr[i][j] = original[i * n + j];
            }
        }

        return ansMatr;
    }
};


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n)
            return {};

        vector<vector<int>> ansMatr(m, vector<int>(n));

        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ansMatr[i][j] = original[k++];
            }
        }

        return ansMatr;
    }
};
