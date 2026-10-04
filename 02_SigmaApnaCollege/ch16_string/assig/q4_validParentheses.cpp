
git commit -m "feat(sigmaApnaCollege): done with assig Ques 2 normal locally practice and 2 LeetCode probNo and readyForNewChap (ch16_string)" 
/*
/*

probNo 20  https://leetcode.com/problems/valid-parentheses/description/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true



*/

// Brute-force complexity
// find() and erase() can require traversing/shifting the string repeatedly.
// TC ≈ O(n²)
// SC = O(n) because the string is modified.
class Solution {
public:
    bool isValid(string s) {  

        while(s.find("()") != string::npos ||
              s.find("{}") != string::npos ||
              s.find("[]") != string::npos) {

            size_t pos;

            if((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
            }
            else if((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
            }
            else {
                pos = s.find("[]");
                s.erase(pos, 2);
            }
        }

        return s.empty();
    }
};



class Solution {
public:
    bool isValid(string s) {  //tc=O(n)=sc using stack
        stack<char> st;
        
        for(char ch : s) {
            if(ch == '(')
                st.push(')');
            else if(ch == '{')
                st.push('}');
            else if(ch == '[')
                st.push(']');
            else if(st.empty() || st.top() != ch)
                return false;
            else
                st.pop();
        }
        
        return st.empty();
    }
};

