//8th Nov 2026 (Sunday)
qno 1267 https://leetcode.com/problems/count-servers-that-communicate


//Approach - 2 (Better Approach)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);
        
        //Preprocessing
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) { //found a server at grid[row][col]
                    indexColCount[col] += 1;
                    indexRowCount[row] += 1;
                }
            }
        }

        int resultServers = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)) {
                    resultServers++;
                }
            }
        }
        return resultServers;
    }
};
