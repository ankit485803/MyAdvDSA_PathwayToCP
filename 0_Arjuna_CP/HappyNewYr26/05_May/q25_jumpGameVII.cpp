

/*

25th May 2026 (Monday)

qno 1871  https://leetcode.com/problems/jump-game-vii/?envType=daily-question&envId=2026-05-25

1871. Jump Game VII
Medium
Topics

Companies
Hint
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

 

Example 1:

Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
Example 2:

Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
 

Constraints:

2 <= s.length <= 105
s[i] is either '0' or '1'.
s[0] == '0'
1 <= minJump <= maxJump < s.length
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
90,891/303.4K
Acceptance Rate
30.0%
Topics
Staff
String
Dynamic Programming
Sliding Window
Prefix Sum
Weekly Contest 242

*/


// ===================================================
// Solution 2: Difference Array (Optimal)
// Time: O(n), Space: O(n)
// ===================================================

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();

        // Early exit: last index must be '0'
        if (s[n - 1] == '1') return false;

        // Difference array
        vector<int> arr(n + 1, 0);

        int count = 0;

        for (int i = 0; i < n; i++) {

            // Apply prefix sum
            count += arr[i];

            // Current index is reachable
            if (i == 0 || (s[i] == '0' && count > 0)) {

                // Mark reachable range
                if (i + minJump < n)
                    arr[i + minJump] += 1;

                if (i + maxJump + 1 < n)
                    arr[i + maxJump + 1] -= 1;
            }
        }

        // Last index reachable or not
        return count > 0;
    }
};