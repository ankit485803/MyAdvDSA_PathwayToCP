
8th Oct 2026 (Thursday)
qno 1021 https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {  //TC=O(n) = sc
        string result;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;  // Add the character if it's inside a primitive
                }
                depth++;  // IncreDepth  opening parenthesis

            } else {
                depth--;  // decrease on closing parenthesis
                if (depth > 0) {
                    result += c;  // Add the character if it's inside a primitive
                }
            }
        }

        return result;
    }
};
