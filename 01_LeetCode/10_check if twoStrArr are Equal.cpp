


/*


2nd Oct 2025 (Thursday - 10th  last day Dashara puja)

qno 1662    https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/


Medal LeetCode 50 days  https://leetcode.com/medal/?showImg 
https://leetcode.com/medal/?showImg=0&id=8304728&isLevel=false






1662. Check If Two String Arrays are Equivalent
Easy
Topics

Companies
Hint
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.



Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false



Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:
1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.







*/



class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        // Initialize two indices for iterating through both word arrays
        int i = 0, j = 0;
        int idx1 = 0, idx2 = 0;
        
        // Loop until both arrays are traversed
        while (i < word1.size() && j < word2.size()) {
            // Compare the characters from both strings at the current positions
            if (word1[i][idx1] != word2[j][idx2]) {
                return false; // If characters do not match
            }

            // Move to the next character in word1 and word2
            idx1++;
            idx2++;

            // If we have reached the end of a string in word1 or word2, move to the next string
            if (idx1 == word1[i].size()) {
                i++;
                idx1 = 0; // Reset the index for the next string
            }
            if (idx2 == word2[j].size()) {
                j++;
                idx2 = 0; // Reset the index for the next string
            }
        }
        
        // If both arrays are exhausted at the same time, return true
        return i == word1.size() && j == word2.size();
    }
};


//TC=O(n), sc=O(1)