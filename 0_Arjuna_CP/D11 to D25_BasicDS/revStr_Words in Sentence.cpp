

#include <iostream>
using namespace std;
#include <vector>



/*

17th Junly 2025 (Thursday) reverse the string like arr

qno 344  https://leetcode.com/problems/reverse-string/


Imagine you want to rearrange books on a real shelf:

Pass by value: You take a photo of the shelf, rearrange the photo, and hang it somewhere else. The real shelf remains unchanged.
Pass by reference: You rearrange the actual shelf, and now the books are in new order permanently.

*/



void revStr(vector<char>& myStr) {  //yaha pass by reference imp hai otherwise same string print hoga Ankit be alert

    int st=0, end = myStr.size()-1;

    while(st < end) {
        swap(myStr[st], myStr[end]);
        st++;
        end--;
    }

}



int main() {

    vector<char> myStr = {'B', 'O', 'O', 'K'};

    revStr(myStr);

    //printing
    for(char C : myStr) {
        cout << C;
    }

    cout << endl;

    return 0;

}

// TC=O(n), SC=O(1)



/*
qno 544  https://leetcode.com/problems/reverse-string-ii/description/

✅ Problem Summary:

You are given:
A string s
An integer k
You must reverse the first k characters of every 2k segment in the string.

🧠 Rules:
For every block of 2k characters:
Reverse the first k characters
Leave the next k characters as is

If the remaining characters are:
< k → Reverse all of them
≥ k but < 2k → Reverse the first k, leave the rest as is



*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k) {
    for (int i = 0; i < s.length(); i += 2 * k) {
        // Reverse from i to i+k or till end of string
        int end = min(i + k, (int)s.length());
        reverse(s.begin() + i, s.begin() + end);
    }
    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;

    string result = reverseStr(s, k);
    cout << result << endl; // Output: bacdfeg

    return 0;
}









class Solution {
public:
    string reverseStr(string s, int k) {
        
        for(int i=0; i<s.length(); i += 2*k) {
            int end = min(i+k, (int)s.length());  //to select min

            reverse(s.begin()+i, s.begin()+end);
        }
        return s;
    }
};


// TC=O(n), SC=O(1)



// qno 151  https://leetcode.com/problems/reverse-words-in-a-string/description/

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