



/*


3rd Jan 2026 (Satursday)


qno 1411  https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03


1411. Number of Ways to Paint N × 3 Grid
Hard
Topics

Companies
Hint
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

Example 1:


Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.
Example 2:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
1 <= n <= 5000
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
45,869/68.5K
Acceptance Rate
67.0%
Topics
Dynamic Programming
Weekly Contest 184





*/


class Solution {
public:
    int numOfWays(int n) {  
        const int MOD = 1e9 + 7;
        
        // Base case for 1 row
        long long dp = 12;  // 12 ways to paint a 1 x 3 grid
        
        for (int i = 2; i <= n; ++i) {
            dp = (dp * 6) % MOD;
        }
        
        return dp;
    }
};








class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long long aba = 6; // patterns like ABA
        long long abc = 6; // patterns like ABC
        
        for (int i = 2; i <= n; i++) {
            long long newAba = (aba * 3 + abc * 2) % MOD;
            long long newAbc = (aba * 2 + abc * 2) % MOD;
            aba = newAba;
            abc = newAbc;
        }
        
        return (aba + abc) % MOD;
    }
};



