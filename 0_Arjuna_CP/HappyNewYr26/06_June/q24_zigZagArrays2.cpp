

/*

24th June 2026 (Wednesday)

qno 3700  https://leetcode.com/problems/number-of-zigzag-arrays-ii/?envType=daily-question&envId=2026-06-24

3700. Number of ZigZag Arrays II
Solved
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
[5, 4, 5]
Example 2:

Input: n = 3, l = 1, r = 3

Output: 10

Explanation:

​​​​​​​There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

[1, 2, 1], [1, 3, 1], [1, 3, 2]
[2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
[3, 1, 2], [3, 1, 3], [3, 2, 3]
All arrays meet the ZigZag conditions.

 

Constraints:

3 <= n <= 109
1 <= l < r <= 75​​​​​​​
 
Discover more
Mathematics
Programming
Math
Seen this question in a real interview before?
1/6
Yes
No
Accepted
41,406/64.7K
Acceptance Rate
64.0%
Topics
Principal
Math
Dynamic Programming
Weekly Contest 469

*/


#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:
    static const int MOD = 1000000007;
    
    // Standard matrix multiplication under mod
    vector<vector<long long>> mul(const vector<vector<long long>>& A, 
                                 const vector<vector<long long>>& B) {
        int m = A.size();
        vector<vector<long long>> C(m, vector<long long>(m, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                long long sum = 0;
                for (int k = 0; k < m; k++) {
                    sum = (sum + A[i][k] * B[k][j]) % MOD;
                }
                C[i][j] = sum;
            }
        }
        return C;
    }
    
    // Binary exponentiation for matrices
    vector<vector<long long>> matPow(vector<vector<long long>> base, 
                                    long long e, int m) {
        // Identity matrix
        vector<vector<long long>> res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            res[i][i] = 1;
        }
        
        while (e > 0) {
            if (e % 2 == 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            e >>= 1;
        }
        return res;
    }
    
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        // Transition matrix T where T[i][j] = 1 if value i can follow value j in a zigzag
        // i.e. i > j (going up) — the down direction is handled by symmetry (*2 at the end)
        // Time: O(m^3 * log n), Space: O(m^2)
        vector<vector<long long>> T(m, vector<long long>(m, 0));
        for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1; // value i is strictly greater than value j
            }
        }
        
        // T^(n-1) encodes all valid zigzag transitions across n elements
        vector<vector<long long>> powT = matPow(T, n - 1, m);
        
        // Sum all entries: each (i,j) entry = number of zigzag arrays starting at j ending at i
        long long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                total = (total + powT[i][j]) % MOD;
            }
        }
        
        // Multiply by 2 to account for both up-first and down-first zigzag sequences
        return static_cast<int>((total * 2) % MOD);
    }
};