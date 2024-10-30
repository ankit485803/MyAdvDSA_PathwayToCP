
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>


// Qno 151.    https://leetcode.com/problems/reverse-words-in-a-string/description/


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++) {
            string word = "";
            while(i<n && s[i] != ' ') {   //step1: POSITION last to first
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());  //step2: FORM ko tik kar rahe h each word ka
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};


// TC = O(n) , SC = O(1)