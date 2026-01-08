





/*


8th Oct 2025 (Wednesday)

qno  1768   https://leetcode.com/problems/merge-strings-alternately/description/





1768. Merge Strings Alternately
Easy
Topics

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

 


Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r



Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s




Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.



string a = "Hello";
string b = " World";
a += b;  // Equivalent to a = a + b;
// Now a is "Hello World"

 
*/


class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        //solve using twoPointer approach 
        int i=0, j = 0;

        string merged = "";

        while(i < word1.size()  ||  j < word2.size()) {

            if(i < word1.size()) {
                merged += word1[i++];
            }

            if(j < word2.size()) {
                merged += word2[j++];   // Add character from word2 and increment j
            }
        }

        return merged;

    }  

    //TC = O(n + m)  sum of length of word1 and word2
    // SC = O(1) 

};





/*

qno 1790   https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

1790. Check if One String Swap Can Make Strings Equal
Easy
Topics
premium lock icon
Companies
Hint
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".


Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.



Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 

Constraints:
1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.





*/




class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        //BASE CASE: If the strings are already the same
        if (s1 == s2) return true;


        
        // To store indices where characters differ
        vector<int> diff;

        // Find positions where characters differ
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // If there are not exactly 2 mismatches, return false
        if (diff.size() != 2) return false;


        // Check if swapping s2's characters at these positions makes them equal
        int i = diff[0], j = diff[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};













/* TC=O(n) , SC=O(n) due to the diff vector that stores the mismatched indice
Edge Cases:

        Strings that are already equal (no swap needed).
        Strings with more than 2 mismatches (impossible to fix with one swap).
        Strings where a swap can make them equal.


*/