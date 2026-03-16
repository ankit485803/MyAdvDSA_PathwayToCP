

/*

16th March 2026 (Monday)


qno 1878  https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/?envType=daily-question&envId=2026-03-16


1878. Get Biggest Three Rhombus Sums in a Grid
Medium
Topics

Companies
Hint
You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
Example 2:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
42,409/67.7K
Acceptance Rate
62.6%
Topics
Staff
Array
Math
Sorting
Heap (Priority Queue)
Matrix
Prefix Sum
Biweekly Contest 53


*/



 
//Approach-1 (Brute Force)
//T.C : O(m*n * min(m, n)^2)
//S.C : O(1)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;

        auto addToSet = [&](int val) {
            st.insert(val);
            if (st.size() > 3)
                st.erase(begin(st));
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                addToSet(grid[r][c]);   //every cell is valid for rohmbus of side = 0

                for (int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {

                    int sum = 0;

                    for (int k = 0; k < side; k++) {
                        sum += grid[r - side + k][c + k];   // top to right corner
                        sum += grid[r + k][c + side - k];   // right to bottom corner
                        sum += grid[r + side - k][c - k];   // bottom to left corner
                        sum += grid[r - k][c - side + k];   // left to top corner
                    }

                    addToSet(sum);
                }
            }
        }

        return vector<int>(rbegin(st), rend(st));
    }
};




//Approach-2 (Using Diagonal Prefix Sum to get rid of innermost for loop)
//T.C : O(m*n * min(m, n))
//S.C : O(1)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        //left to right diagonals prefix
        vector<vector<int>> d1(m, vector<int>(n));

        //right to left diagonals prefix
        vector<vector<int>> d2(m, vector<int>(n));

        // building d1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                d1[i][j] = grid[i][j];
                if(i > 0 && j > 0)
                    d1[i][j] += d1[i-1][j-1];
            }
        }

        // building d2
        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--){
                d2[i][j] = grid[i][j];
                if(i > 0 && j+1 < n)
                    d2[i][j] += d2[i-1][j+1];
            }
        }

        set<int> st;

        auto addToSet = [&](int val){
            st.insert(val);
            if(st.size() > 3)
                st.erase(st.begin());
        };

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){

                // rhombus with side = 0
                addToSet(grid[r][c]);

                for(int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {
                    int sum = 0;

                    int top_r = r-side, top_c = c;
                    int right_r = r, right_c = c+side;
                    int bottom_r = r+side, bottom_c = c;
                    int left_r = r, left_c = c-side;

                    // top to right corner
                    sum += d1[right_r][right_c];
                    if(top_r-1 >= 0 && top_c-1 >= 0)
                        sum -= d1[top_r-1][top_c-1];

                    // right to bottom corner
                    sum += d2[bottom_r][bottom_c];
                    if(right_r-1 >= 0 && right_c+1 < n)
                        sum -= d2[right_r-1][right_c+1];

                    // bottom to left corner
                    sum += d1[bottom_r][bottom_c];
                    if(left_r-1 >= 0 && left_c-1 >= 0)
                        sum -= d1[left_r-1][left_c-1];

                    // left to top corner
                    sum += d2[left_r][left_c];
                    if(top_r-1 >= 0 && top_c+1 < n)
                        sum -= d2[top_r-1][top_c+1];

                    // remove corners counted twice
                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];

                    addToSet(sum);
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};