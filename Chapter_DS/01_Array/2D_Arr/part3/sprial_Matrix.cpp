
#include <iostream>
using namespace std;
#include <vector>



// qno 54   https://leetcode.com/problems/spiral-matrix/description/

/* solve this prob in three steps

step1: Logic boundries
step2: while loop condition  -- we should use = symbol for odd matrix
step3: corner case



*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        // shortform-- mat = matrix, srow = starting row, erow = ending row

        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0, erow = m-1, ecol = n-1;
        vector<int> ans;

        while(srow <= erow && scol <= ecol) {
            //top
            for(int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j] );            
            
            }

            //right
            for(int i = srow+1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);

            }


            //bottom
            for(int j = ecol-1; j >= scol; j--) {
                if(srow == erow) {  // CORNER-CASE  
                    break;
                }
                ans.push_back(mat[erow][j] );

            }

            //left
            for(int i = erow-1; i >= srow+1; i--) {
                if(scol == ecol) {
                    break;  //not repeat the duplicate if equal exist
                }
                ans.push_back(mat[i][scol] );

            }

            srow++; erow--; scol++; ecol--;   // Adjust the boundaries

        }

        return ans; 
    }
};


// TC = O(total no of cell) == O(m*n), SC = O(1)