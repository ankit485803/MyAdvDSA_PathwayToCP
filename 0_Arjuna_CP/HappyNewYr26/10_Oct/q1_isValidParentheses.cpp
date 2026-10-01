

/*

1st Oct 2026 (Thursday)

qno 20  https://leetcode.com/problems/valid-parentheses/?envType=daily-question&envId=2026-10-01


*/

//Approach (Using Stack - you can use a string as well)
class Solution {
public:
    bool isValid(string s) {  //tc=O(n)=sc using stack
        stack<char> st;
        
        for(char ch:s) {
            if (ch == '(')
       st.push(')');
      else if (ch == '{')
       st.push('}');
            else if (ch == '[')
                st.push(']');
            else if (st.empty() || st.top() != ch)
                return false;
            else {
                st.pop();
            }
        }
        
        return st.empty();
    }
};