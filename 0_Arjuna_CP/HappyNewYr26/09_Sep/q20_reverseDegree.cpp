

// 20th Sep 2026 (Sunday)
qno 3498 https://leetcode.com/problems/reverse-degree-of-a-string


class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result += (26 - (s[i] - 'a')) * (i+1);
        }
        return result;
    }
};