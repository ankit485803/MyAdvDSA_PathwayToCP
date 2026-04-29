

/*

29th April 2026 (Wednesday)

qno 3225  https://leetcode.com/problems/maximum-score-from-grid-operations/description/?envType=daily-question&envId=2026-04-29


3225. Maximum Score From Grid Operations
Solved
Hard
Topics

Companies
Hint
You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.

The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.

Return the maximum score that can be achieved after some number of operations.

 

Example 1:

Input: grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]

Output: 11

Explanation:


In the first operation, we color all cells in column 1 down to row 3, and in the second operation, we color all cells in column 4 down to the last row. The score of the resulting grid is grid[3][0] + grid[1][2] + grid[3][3] which is equal to 11.

Example 2:

Input: grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]

Output: 94

Explanation:


We perform operations on 1, 2, and 3 down to rows 1, 4, and 0, respectively. The score of the resulting grid is grid[0][0] + grid[1][0] + grid[2][1] + grid[4][1] + grid[1][3] + grid[2][3] + grid[3][3] + grid[4][3] + grid[0][4] which is equal to 94.

 

Constraints:

1 <= n == grid.length <= 100
n == grid[i].length
0 <= grid[i][j] <= 109
 
Discover more
Remote developer jobs
Seen this question in a real interview before?
1/6
Yes
No
Accepted
20,442/35.4K
Acceptance Rate
57.8%
Topics
Principal
Array
Dynamic Programming
Matrix
Prefix Sum
Biweekly Contest 135


*/


using ll=long long;
static ll colSum[100][101]={{0}}; // 1-indexed prefix col sums
// (j, num of black items in curr col, cur col score exclusive/inclusive)
static ll dp[100][101][2];
static int n;

class Solution {
public:
    static long long maximumScore(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==1) return 0;
        // compute col prefix sums
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                colSum[j][i+1]=colSum[j][i]+grid[i][j];
            }
        }
        for(int j=0; j<n; j++)
            memset(dp[j], 0, sizeof(ll)*(n+1)*2);

        for(int j=1; j<n; j++){
            for(int b0=0; b0<=n; b0++){
                ll p0=dp[j-1][b0][0];
                ll p1=dp[j-1][b0][1];

                for(int b1=0; b1<=n; b1++){
                    bool isBigger=b1>b0;
                    
                    ll prvX=isBigger?(colSum[j-1][b1]-colSum[j-1][b0]):0;
                    ll curX=!isBigger?(colSum[j][b0]-colSum[j][b1]):0;
                    
                    // State 0: score in cur col exclusive
                    dp[j][b1][0]=max(dp[j][b1][0], max(prvX+p0, p1));
                    
                    // State 1: score in cur col inclusive
                    dp[j][b1][1]=max(dp[j][b1][1], curX+max(p1, prvX+p0));
                }
            }
        }
        ll ans=0;
        for(int b=0; b<=n; b++) 
            ans=max(ans, dp[n-1][b][1]);
        
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();