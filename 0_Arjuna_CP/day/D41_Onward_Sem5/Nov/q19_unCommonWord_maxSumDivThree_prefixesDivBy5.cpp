


/*


27th Nov 2025  (Thursday)


qno  884  https://leetcode.com/problems/uncommon-words-from-two-sentences/


884. Uncommon Words from Two Sentences
Attempted
Easy
Topics

Companies
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.



*/



#include <unordered_map>
#include <sstream>
#include <string>

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) { //TC=O(n + m), sc=O(distinctWord)
        //wordCount
        unordered_map<string, int> wordC;


        // Function to count words and update their frequency
        auto countW = [&](const string& sentence) {
            istringstream stream(sentence);
            string word;
            while (stream >> word) {
                wordC[word]++;
            }
        };

        countW(s1);
        countW(s2);

        vector<string> result;

        //find uncommon words
        for (const auto& entry : wordC) {
            if (entry.second == 1) {  // Word appears exactly once
                result.push_back(entry.first);
            }
        }

        return result;
    }
};



/*

qno 944  https://leetcode.com/problems/delete-columns-to-make-sorted/description/



944. Delete Columns to Make Sorted
Easy
Topics

Companies
You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid.

For example, strs = ["abc", "bce", "cae"] can be arranged as follows:
abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

 

Example 1:

Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.
Example 2:

Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.
Example 3:

Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.
 

Constraints:

n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 1000
strs[i] consists of lowercase English letters.


*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {  //TC=O(n*m), sc=O(a1)
        int deletionCount = 0;
        int numCol = strs[0].size();  //Length of each string (all strings are of equal length)

        for(int col=0; col<numCol; ++col) {
            for(int row=1; row<strs.size(); ++row) {
                 // Check if this column is sorted by comparing adjacent rows
                if(strs[row][col] < strs[row - 1][col] ) {
                    deletionCount++;
                    break;
                }
            }
        }

        return deletionCount;
    }
};




/*

qno 1262 https://leetcode.com/problems/greatest-sum-divisible-by-three/


1262. Greatest Sum Divisible by Three
Medium
Topics

Companies
Hint
Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

Constraints:

1 <= nums.length <= 4 * 104
1 <= nums[i] <= 104


*/


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);  // dp[0] is for sum % 3 == 0, dp[1] for sum % 3 == 1, dp[2] for sum % 3 == 2
        

        for (int num : nums) {
            // to avoid overwritingResult, makeCopy
            vector<int> temp = dp;
            
            // For each possible remainder (0, 1, 2), update the dp array
            for (int i = 0; i < 3; i++) {
                int newRem = (i + num) % 3;
                temp[newRem] = max(temp[newRem], dp[i] + num);
            }
            
            dp = temp;
        }
        
        // The answer is the maximum sum divisible by 3, which is stored in dp[0]
        return dp[0];
    }
};





/*

qno 1018  https://leetcode.com/problems/binary-prefix-divisible-by-5/description/


1018. Binary Prefix Divisible By 5
Easy
Topics

Companies
Hint
You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).

For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
Return an array of booleans answer where answer[i] is true if xi is divisible by 5.

 

Example 1:

Input: nums = [0,1,1]
Output: [true,false,false]
Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
Only the first number is divisible by 5, so answer[0] is true.
Example 2:

Input: nums = [1,1,1]
Output: [false,false,false]
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.


*/



class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {  //tc=O(n)
         
        vector<bool> result;  //SC=O(n)
        int curr = 0;

        for(int num : nums) {
            curr = (curr *2 + num) % 5;  // Update the current number (mod 5)
            result.push_back(curr == 0);
        }

        return result;
    }
};







/*


qno 859  https://leetcode.com/problems/buddy-strings/description/

859. Buddy Strings
Attempted
Easy
Topics

Companies
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 

Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.



*/

class Solution {
public:
    bool buddyStrings(string s, string goal) { //tc = O(n) = sc
        // If lengths are diff
        if (s.length() != goal.length()) return false;

        
        // If strings are equal, check for at least two identical characters
        if (s == goal) {
            unordered_set<char> seen;
            for (char c : s) {
                if (seen.count(c)) return true;
                seen.insert(c);
            }
            return false;
        }
        

        // If strings are not equal, find the indices where they differ
        vector<int> diffIndices;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != goal[i]) {
                diffIndices.push_back(i);
            }
        }

        
        // For the strings to become equal by one swap, we should have exactly two differences
        if (diffIndices.size() != 2) return false;
        
        int i = diffIndices[0], j = diffIndices[1];
        return s[i] == goal[j] && s[j] == goal[i];
    }
};



/*

qno 1528  https://leetcode.com/problems/shuffle-string/description/


1528. Shuffle String
Easy
Topics

Companies
Hint
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.




*/


class Solution {
public:
    string restoreString(string s, vector<int>& indices) {  //TC=O(n)
        int n = indices.size();
        vector<char> result(n);  // Use a vector to store the shuffled string, sc=O(n)

        // Place each character at the correct position
        for (int i = 0; i < n; ++i) {
            result[indices[i]] = s[i];
        }

        // Convert the result vector to a string  
        return string(result.begin(), result.end());
    }
};
