




/*


10th Jan 2026 (Satursday)


qno 712   https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2026-01-10


712. Minimum ASCII Delete Sum for Two Strings
Medium
Topics

Companies
Hint
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.



*/



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {  //tc=O(m*n)=sc
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1],
                        dp[i][j - 1] + s2[j - 1]
                    );
                }
            }
        }

        return dp[n][m];
    }
};





// ans = sumASCII(s1) + sumASCII(s2) - 2 * maxASCIICommonSubseq


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        int sum1 = 0, sum2 = 0;
        for (char c : s1) sum1 += c;
        for (char c : s2) sum2 += c;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return sum1 + sum2 - 2 * dp[n][m];
    }
};







/*


qno  3663   https://leetcode.com/problems/find-the-least-frequent-digit/



3663. Find The Least Frequent Digit
Easy
Topics

Companies
Hint
Given an integer n, find the digit that occurs least frequently in its decimal representation. If multiple digits have the same frequency, choose the smallest digit.

Return the chosen digit as an integer.

The frequency of a digit x is the number of times it appears in the decimal representation of n.
 

Example 1:

Input: n = 1553322

Output: 1

Explanation:

The least frequent digit in n is 1, which appears only once. All other digits appear twice.

Example 2:

Input: n = 723344511

Output: 2

Explanation:

The least frequent digits in n are 7, 2, and 5; each appears only once.

 

Constraints:

1 <= n <= 231​​​​​​​ - 1



*/



class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);

        // Step1: count digitFreq
        while (n > 0) {
            int d = n % 10;
            freq[d]++;
            n /= 10;
        }

        // Step2: find least freqDigit
        int minFreq = INT_MAX;
        int ans = 0;

        for (int d = 0; d <= 9; d++) {
            if (freq[d] > 0) {  // only digits that appear
                if (freq[d] < minFreq) {
                    minFreq = freq[d];
                    ans = d;
                }
            }
        }

        return ans;
    }
};
