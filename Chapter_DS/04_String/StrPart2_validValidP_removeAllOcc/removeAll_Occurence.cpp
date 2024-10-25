
#include <iostream>
using namespace std;
#include <string>


/* Qno 1910    https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/


step1:  find part in s
s2: delete part in s till the leng of s become zero


*/


class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        //start loop
        while(s.length() > 0  && s.find(part) < s.length()) { //find and erase part in s

            s.erase(s.find(part), part.length());
        }

        return s;  //because we do all changes with original string s
    }
};


// // Time complexity: O(n * m) in the worst case, where n is the length of s and m is the length of part