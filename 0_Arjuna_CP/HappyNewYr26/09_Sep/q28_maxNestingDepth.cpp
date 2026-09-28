

/*

28th Sep 2026 (Monday)

qno 1614  https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2026-09-28


*/

//Approach-1 (using stack)
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;

        stack<char> st;  //tc=O(n)=sc using STACK DS

        for(char& ch : s) {
            if(ch == '(') {
                st.push(ch);
            } else if(ch == ')') {
                st.pop();
            }

            ans = max(ans, (int)st.size());
        }

        return ans;
    }
};



class Solution {
public:
    int maxDepth(string s) {  //tc=O(n), sc=O(1) using constantSpace iterative countingApproach
        int ans = 0;
        int openBrackets = 0;

        for(char& ch : s) {
            if(ch == '(') {
                openBrackets++;
            } else if(ch == ')') {
                openBrackets--;
            }

            ans = max(ans, openBrackets);
        }

        return ans;
    }
};