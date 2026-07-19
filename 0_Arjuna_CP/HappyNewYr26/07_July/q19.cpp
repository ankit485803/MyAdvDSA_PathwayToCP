
qno 1081 https://leetcode.com/problems/smallest-subsequence-of-distinct-characters



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
