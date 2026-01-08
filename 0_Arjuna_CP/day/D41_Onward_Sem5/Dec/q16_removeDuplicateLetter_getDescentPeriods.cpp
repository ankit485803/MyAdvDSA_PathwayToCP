




/*



16th Dec 2025 (Tuesday)


qno 316  https://leetcode.com/problems/remove-duplicate-letters/description/


316. Remove Duplicate Letters
Medium
Topics

Companies
Hint
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/


*/


 class Solution {
public:
    string removeDuplicateLetters(string s) {  //tc=O(n)
        // Step1: countFreq
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step2: st
        stack<char> st;
        vector<bool> inStack(26, false);  //sc=O(1)

        // Step3: Traverse
        for (char c : s) {
            count[c - 'a']--;

            if (inStack[c - 'a']) continue;

            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        // Step4: final
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};



//fron GPT

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Step 1: Count the frequency of each character
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step 2: Stack to build the result
        stack<char> st;
        vector<bool> inStack(26, false); // Keeps track of whether the character is in the stack

        // Step 3: Traverse through the string
        for (char c : s) {
            // Step 3.1: Decrease the frequency of the current character
            count[c - 'a']--;

            // Step 3.2: If the character is already in the stack, skip it
            if (inStack[c - 'a']) continue;

            // Step 3.3: Pop characters from the stack if they are greater than the current character
            // and still have occurrences later in the string.
            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            // Step 3.4: Push the current character onto the stack and mark it as in the stack
            st.push(c);
            inStack[c - 'a'] = true;
        }

        // Step 4: Build the final string from the stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};






/*


qno 1081  https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/




1081. Smallest Subsequence of Distinct Characters
Medium
Topics

Companies
Hint
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
 

Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/


*/


class Solution {
public:
    string smallestSubsequence(string s) {
        // Step1: countFreq
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step2: st
        stack<char> st;
        vector<bool> inStack(26, false);  //sc=O(1)

        // Step3: Traverse
        for (char c : s) {
            count[c - 'a']--;

            if (inStack[c - 'a']) continue;

            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        // Step4: final
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};






/*



qno 2110    https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/


2110. Number of Smooth Descent Periods of a Stock
Medium
Topics

Companies
Hint
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.

 

Example 1:

Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
Example 2:

Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
Example 3:

Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]
 

Constraints:

1 <= prices.length <= 105
1 <= prices[i] <= 105



*/


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {  //tc=O(n), sc=O(1)
        long long totalPeriods = 0;
        int count = 1;  

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                count++;  
            } else {
                totalPeriods += (long long) count * (count + 1) / 2;
                count = 1;
            }
        }

        totalPeriods += (long long) count * (count + 1) / 2;

        return totalPeriods;
    }
};
