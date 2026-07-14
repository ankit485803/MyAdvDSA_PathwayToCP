

/*

14th July 2026 (Tuesday)

qno 3336  https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/?envType=daily-question&envId=2026-07-14

Code
Testcase
Testcase
Test Result
3336. Find the Number of Subsequences With Equal GCD
Hard
Topics

Companies
Hint
You are given an integer array nums.

Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:

The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
Return the total number of such pairs.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 10

Explanation:

The subsequence pairs which have the GCD of their elements equal to 1 are:

([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
Example 2:

Input: nums = [10,20,30]

Output: 2

Explanation:

The subsequence pairs which have the GCD of their elements equal to 10 are:

([10, 20, 30], [10, 20, 30])
([10, 20, 30], [10, 20, 30])
Example 3:

Input: nums = [1,1,1,1]

Output: 50

 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 200
 
Discover more
Computer Education
Seen this question in a real interview before?
1/6
Yes
No
Accepted
44,457/73K
Acceptance Rate
60.9%
Topics
Senior Staff
Array
Math
Dynamic Programming
Number Theory
Weekly Contest 421


*/

//Approach-1 (Recursion + Memoization)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
    int t[201][201][201];
public:
    int solve(vector<int> &nums,int i, int first, int second){
        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdsMatch    = (first == second);
            return (bothNonEmpty && gcdsMatch) ? 1 : 0;
        }
        
        if(t[i][first][second] != -1) 
            return t[i][first][second];
        
        // Skip this index entirely
        int skip = solve(nums, i + 1, first, second);

        // Include this index in seq1
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

        // Include this index in seq2
        int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));
        
        // Summing up all the possibilites
        return t[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums) 
            maxEl = max(maxEl, x);
        
        int dp[n+1][maxEl+1][maxEl+1];

        // Base case
        for (int first = 0; first <= maxEl; first++) {
            for (int second = 0; second <= maxEl; second++) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch    = (first == second);
                dp[n][first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = dp[i + 1][first][second]; //solve(i+1, first, second);

                    // Include this index in seq1
                    int take1 = dp[i + 1][__gcd(first, nums[i])][second]; 

                    // Include this index in seq2
                    int take2 = dp[i + 1][first][__gcd(second, nums[i])];

                    dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
        }
 
        return dp[0][0][0]; //return solve(nums, 0, 0, 0);
    }
};



//Approach-3 (Bottom Up - 2D DP, space optimized)
//T.C : O(n * M * M), M = max element
//S.C : O(M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums) 
            maxEl = max(maxEl, x);

        // prev = layer i+1, curr = layer i   (2D instead of 3D)
        vector<vector<int>> prev(maxEl+1, vector<int>(maxEl+1, 0));

        // Base case
        for (int first = maxEl; first >= 0; first--) {
            for (int second = maxEl; second >= 0; second--) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch    = (first == second);
                prev[first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(maxEl+1, vector<int>(maxEl+1, 0));
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = prev[first][second];

                    // Include this index in seq1
                    int take1 = prev[__gcd(first, nums[i])][second];

                    // Include this index in seq2
                    int take2 = prev[first][__gcd(second, nums[i])];

                    curr[first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
            prev = move(curr);
        }

        return prev[0][0];
    }
};