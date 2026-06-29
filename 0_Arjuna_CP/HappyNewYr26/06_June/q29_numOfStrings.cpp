

/*

29th June 2026 (Monday)

qno 1967  https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/?envType=daily-question&envId=2026-06-29

1967. Number of Strings That Appear as Substrings in Word
Solved
Easy
Topics

Companies
Hint
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
Example 2:

Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
Example 3:

Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".
 

Constraints:

1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] and word consist of lowercase English letters.
 
Discover more
Online Learning Platform
Seen this question in a real interview before?
1/6
Yes
No
Accepted
173,744/204.3K
Acceptance Rate
85.1%
Topics
Mid Level
Array
String
Weekly Contest 254


*/


class Solution {
public:
    // Compute LPS (Longest Proper Prefix which is also Suffix) array
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    //KMP
    vector<int> search(string pat, string txt) {
        int N = txt.length();
        int M = pat.length();
        vector<int> result;

        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0, j = 0;
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                result.push_back(i - j + 1);
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    int numOfStrings(vector<string>& patterns, string word) {  //solved using the KMP algo Str
        int count = 0;
        for (const string& pat : patterns) {
            if (!search(pat, word).empty()) {
                count++;
            }
        }
        return count;
    }
};