

/*

10th Nov 2026 (Tuesday)

qno 3693  https://leetcode.com/problems/climbing-stairs-ii/?envType=daily-question&envId=2026-11-10

*/

//Approach-1 (Recursion + Memo)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> memo;

    int solve(int i, int n, vector<int>& costs) {
        if (i == n)
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int cost = INT_MAX;

        int j = i + 1; 
        if(j <= n)                                 // jump of 1
            cost = solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i);

        j = i + 2;                                      // jump of 2
        if (j <= n)
            cost = min(cost, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));

        j = i + 3;                                      // jump of 3
        if (j <= n)
            cost = min(cost, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));

        return memo[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        memo.assign(n + 1, -1);
        return solve(0, n, costs);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int i = n-1; i >= 0; i--) {
            
            int cost = INT_MAX;

            int j = i + 1; 
            if(j <= n)                           // jump of 1
                cost = dp[j] + costs[j - 1] + (j - i) * (j - i);

            j = i + 2;                                  // jump of 2
            if (j <= n)
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));

            j = i + 3;                                  // jump of 3
            if (j <= n)
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));

            dp[i] = cost;
        }

        return dp[0];
    }
};