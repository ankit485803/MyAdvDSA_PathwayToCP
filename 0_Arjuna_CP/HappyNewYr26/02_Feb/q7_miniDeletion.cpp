



/*


7th Feb 2026 (Satursday)


qno 1653  https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2026-02-07


1653. Minimum Deletions to Make String Balanced
Solved
Medium
Topics

Companies
Hint
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 

Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.
 
Discover more
Computer programming
Programming
Seen this question in a real interview before?
1/5
Yes
No
Accepted
236,294/353.1K
Acceptance Rate
66.9%
Topics
Senior
String
Dynamic Programming
Stack
Biweekly Contest 39


*/




class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else { // c == 'a'
                deletions = min(deletions + 1, bCount);
            }
        }

        return deletions;
    }
};
