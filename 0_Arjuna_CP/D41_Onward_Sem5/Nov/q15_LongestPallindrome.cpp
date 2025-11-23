


/*


23rd Nov 2025 (Sunday)


qno  3330   https://leetcode.com/problems/find-the-original-typed-string-i/description/





qno  405  https://leetcode.com/problems/longest-palindrome/description/


409. Longest Palindrome
Easy
Topics

Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.



*/


class Solution {
public:
    int longestPalindrome(string s) {  //TC=O(n), SC=O(1)
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        int length = 0;
        bool oddFound = false;
        
        for (auto& [c, count] : freq) {
            if (count % 2 == 0) {
                // If count is even, use all occurrences
                length += count;
            } else {
                // If count is odd, use the largest even part
                length += count - 1;
                oddFound = true; 
            }
        }
        

        if (oddFound) {
            length += 1;
        }
        
        return length;
    }
};




