
/*

23rd June 2026 (Tuesday)

qno 3699  https://leetcode.com/problems/number-of-zigzag-arrays-i/?envType=daily-question&envId=2026-06-23

3699. Number of ZigZag Arrays I
Hard
Topics

Companies
Hint
You are given three integers n, l, and r.

A ZigZag array of length n is defined as follows:

Each element lies in the range [l, r].
No two adjacent elements are equal.
No three consecutive elements form a strictly increasing or strictly decreasing sequence.
Return the total number of valid ZigZag arrays.

Since the answer may be large, return it modulo 109 + 7.

A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

Example 1:

Input: n = 3, l = 4, r = 5

Output: 2

Explanation:

There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

[4, 5, 4]
[5, 4, 5]​​​​​​​
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 2000
1 <= l < r <= 2000
 
Discover more
Android Apps
Seen this question in a real interview before?
1/6
Yes
No
Accepted
45,258/98.4K
Acceptance Rate
46.0%
Topics
Senior Staff
Dynamic Programming
Prefix Sum
Weekly Contest 469

*/

// approach1: Recursive Memoization  but give TLE 
// Time: O(n * m^2), Space: O(n * m) where m = r - l + 1
class Solution {
    static constexpr long long MOD = 1000000007LL;

    int n, l, r;
    vector<vector<vector<long long>>> memo;

    long long helper(int ind, int prev, int nextLarger) {
        // Base case: last element
        if (ind == n - 1) {
            return nextLarger ? (r - prev) : (prev - l);
        }

        long long &res = memo[ind][prev - l][nextLarger];
        if (res != -1) return res;

        res = 0;

        if (nextLarger) {
            // Next element must be greater than prev
            for (int x = prev + 1; x <= r; x++) {
                res = (res + helper(ind + 1, x, 0)) % MOD;
            }
        } else {
            // Next element must be smaller than prev
            for (int x = l; x < prev; x++) {
                res = (res + helper(ind + 1, x, 1)) % MOD;
            }
        }

        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        this->n = n;
        this->l = l;
        this->r = r;

        int m = r - l + 1;
        memo.assign(n, vector<vector<long long>>(m, vector<long long>(2, -1)));

        long long ans = 0;

        for (int start = l; start <= r; start++) {
            ans = (ans + helper(1, start, 1)) % MOD; // next larger
            ans = (ans + helper(1, start, 0)) % MOD; // next smaller
        }

        return (int)ans;
    }
};


// approach2: Bottom-Up DP with Prefix Sums (Optimal)
// Time: O(n * m), Space: O(m) where m = r - l + 1
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        static constexpr long long MOD = 1000000007LL;

        int m = r - l + 1;

        // up[j]   = ways ending at value j, expecting next to go down
        // down[j] = ways ending at value j, expecting next to go up
        vector<long long> up(m, 1), down(m, 1);

        for (int len = 2; len <= n; len++) {
            vector<long long> preDown(m + 1, 0);
            for (int j = 0; j < m; j++) {
                preDown[j + 1] = (preDown[j] + down[j]) % MOD;
            }

            vector<long long> sufUp(m + 1, 0);
            for (int j = m - 1; j >= 0; j--) {
                sufUp[j] = (sufUp[j + 1] + up[j]) % MOD;
            }

            vector<long long> newUp(m, 0), newDown(m, 0);

            for (int j = 0; j < m; j++) {
                // previous value < j
                newUp[j] = preDown[j];

                // previous value > j
                newDown[j] = sufUp[j + 1];
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;
        for (int j = 0; j < m; j++) {
            ans = (ans + up[j] + down[j]) % MOD;
        }

        return (int)ans;
    }
};


class Solution {
public:
    static constexpr int MOD = 1000000007;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {
            reverse(dp.begin(), dp.end());
            int sum = 0;
            for (auto& d : dp)
                sum = (sum + exchange(d, sum)) % MOD;
        }

        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
    }
};