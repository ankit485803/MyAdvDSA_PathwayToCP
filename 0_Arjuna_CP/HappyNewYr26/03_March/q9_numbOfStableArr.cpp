

/*


9th March 2026 (Monday)


qno 3129  https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/?envType=daily-question&envId=2026-03-09

3129. Find All Possible Stable Binary Arrays I
Medium
Topics

Companies
Hint
You are given 3 positive integers zero, one, and limit.

A binary array arr is called stable if:

The number of occurrences of 0 in arr is exactly zero.
The number of occurrences of 1 in arr is exactly one.
Each subarray of arr with a size greater than limit must contain both 0 and 1.
Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: zero = 1, one = 1, limit = 2

Output: 2

Explanation:

The two possible stable binary arrays are [1,0] and [0,1], as both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.

Example 2:

Input: zero = 1, one = 2, limit = 1

Output: 1

Explanation:

The only possible stable binary array is [1,0,1].

Note that the binary arrays [1,1,0] and [0,1,1] have subarrays of length 2 with identical elements, hence, they are not stable.

Example 3:

Input: zero = 3, one = 3, limit = 2

Output: 14

Explanation:

All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].

 

Constraints:

1 <= zero, one, limit <= 200
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
32,561/72.9K
Acceptance Rate
44.7%
Topics
Staff
Dynamic Programming
Prefix Sum
Biweekly Contest 129



Key observation 🔑
The condition
“Each subarray with size > limit must contain both 0 and 1”

means:
❗ You cannot have more than limit consecutive 0s or 1s.

So the problem becomes:
    Count binary arrays with exactly zero 0s and one 1s where max consecutive equal elements ≤ limit.


*/



class Solution {
public:
    int mod = 1e9 + 7;
    int ans = 0;

    void dfs(int z, int o, int last, int run, int limit) {  //method1: bruteForce - Backtracking give TLE
        if (z == 0 && o == 0) {
            ans = (ans + 1) % mod;
            return;
        }

        // place 0
        if (z > 0) {
            if (last != 0)
                dfs(z - 1, o, 0, 1, limit);
            else if (run < limit)
                dfs(z - 1, o, 0, run + 1, limit);
        }

        // place 1
        if (o > 0) {
            if (last != 1)
                dfs(z, o - 1, 1, 1, limit);
            else if (run < limit)
                dfs(z, o - 1, 1, run + 1, limit);
        }
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        dfs(zero, one, -1, 0, limit);
        return ans;
    }
};




//Approach-1 (Recursion + Memoization)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
        if(onesLeft == 0 && zerosLeft == 0) {
            return 1;
        }

        if(t[onesLeft][zerosLeft][lastWasOne] != -1) {
            return t[onesLeft][zerosLeft][lastWasOne];
        }


        int result = 0;

        if(lastWasOne == true) { //explore 0s
            for(int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        } else { //explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zerosLeft][lastWasOne] = result;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;

    }
};




//Approach-2 (Bottom Up)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(t, 0, sizeof(t));

        // Base case: solve(0,0,lastWasOne) = 1
        t[0][0][0] = 1;
        t[0][0][1] = 1;


        for(int onesLeft = 0; onesLeft <= one; onesLeft++) {
            for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {

                if(onesLeft == 0 && zerosLeft == 0) continue;

                int result = 0;

                // if(lastWasOne == true) { explore 0s }
                result = 0;
                for(int len = 1; len <= min(zerosLeft, limit); len++) {
                    result = (result + t[onesLeft][zerosLeft - len][0]) % M;
                }
                t[onesLeft][zerosLeft][1] = result;

                // else { explore 1s }
                result = 0;
                for(int len = 1; len <= min(onesLeft, limit); len++) {
                    result = (result + t[onesLeft - len][zerosLeft][1]) % M;
                }
                t[onesLeft][zerosLeft][0] = result;
            }
        }

        int startWithOne  = t[one][zero][false]; //solve(one, zero, false, limit);
        int startWithZero = t[one][zero][true]; //solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};