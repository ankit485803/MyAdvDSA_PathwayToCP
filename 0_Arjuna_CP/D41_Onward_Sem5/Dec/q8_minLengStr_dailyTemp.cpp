


/*


10th Dec 2025 (Wednesday - myDell laptop lock Hing replace at SP Verma, Dakbanga Patna JN)



qno 2696  https://leetcode.com/problems/minimum-string-length-after-removing-substrings/



Code
Testcase
Testcase
Test Result
2696. Minimum String Length After Removing Substrings
Easy
Topics

Companies
Hint
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

 

Example 1:

Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.
Example 2:

Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.
 

Constraints:

1 <= s.length <= 100
s consists only of uppercase English letters.



*/



class Solution {
public:
    int minLength(string s) {  //tc=O(n)=sc
        string st;   // acts as stack

        for (char c : s) {
            if (!st.empty()) {
                char top = st.back();
                // Check canceling pairs
                if ((top == 'A' && c == 'B') || 
                    (top == 'C' && c == 'D')) {
                    st.pop_back();   // remove the pair
                    continue;
                }
            }
            st.push_back(c);  // otherwise push normally
        }

        return st.size();
    }
};




/*



qno 739   https://leetcode.com/problems/daily-temperatures/


739. Daily Temperatures
Medium
Topics

Companies
Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100


*/




class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {  //classicMonaticProb tc=O(n)=sc
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices of days

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;  // number of days waited
            }
            st.push(i);
        }

        return ans;
    }
};
