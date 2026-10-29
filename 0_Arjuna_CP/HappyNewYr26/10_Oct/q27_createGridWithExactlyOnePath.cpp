


/*

27th Oct 2026 (Tuesday)

qno 3963 https://leetcode.com/problems/create-grid-with-exactly-one-path/description/?envType=daily-question&envId=2026-10-27

*/


class Solution {
public:
    vector<string> createGrid(int m, int n) {  //tc=O(m*n), sc=O(n)
        string topRow(n, '.');
        string remaining = string(n-1, '#')+ '.';

        vector<string> result;
        result.push_back(topRow);

        for(int i=1; i<m; i++) {
            result.push_back(remaining);
        }
        return result;
    }
};