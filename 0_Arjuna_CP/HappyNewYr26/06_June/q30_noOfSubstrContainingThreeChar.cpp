

/*

30th June 2026 (Tuesday)

qno 1358  https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2026-06-30


1358. Number of Substrings Containing All Three Characters
Solved
Medium
Topics

Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
 
Discover more
Development Tools
Language Resources
Seen this question in a real interview before?
1/6
Yes
No
Accepted
530,651/717.1K
Acceptance Rate
74.0%
Topics
Staff
Hash Table
String
Sliding Window
Biweekly Contest 20

*/


class Solution {
public:
    int numberOfSubstrings(string s) {  //tc=O(2*n) = O(n), sc=O(1) using slidingWindow approach
        int n = s.length();

        int result = 0;

        vector<int> mp(3, 0);  //0 idx - a, 1 idx pe b, 2 idx pe c

        int i = 0, j = 0;

        while(j < n) {
            char ch = s[j];
            mp[ch - 'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += (n - j);

                mp[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return result;
    }
};