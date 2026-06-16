

/*

16th June 2026 (Tuesday)

qno 3612   https://leetcode.com/problems/process-string-with-special-operations-i/?envType=daily-question&envId=2026-06-16

3612. Process String with Special Operations I
Medium
Topics

Companies
Hint
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.

 

Example 1:

Input: s = "a#b%*"

Output: "ba"

Explanation:

i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
Thus, the final result is "ba".

Example 2:

Input: s = "z*#"

Output: ""

Explanation:

i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
Thus, the final result is "".

 

Constraints:

1 <= s.length <= 20
s consists of only lowercase English letters and special characters *, #, and %.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
110,843/159.9K
Acceptance Rate
69.3%
Topics
Senior
String
Simulation
Weekly Contest 458


*/


class Solution {
public:
    string processStr(string s) {  //tc=O(m) = sc
        string result = "";

        for(char &ch : s) {
            if(ch == '*') {
                if(result.length() > 0) result.pop_back();   //remove lastChar O(1)
                 
            } else if(ch == '#') {
                result += result;   //n -> 2*n duplicate kar dena  O(m)

            } else if(ch == '%') { 
                reverse(begin(result), end(result));  //O(m)

            } else {
                result += ch;
            }
        }

        return result;
    }
};



class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (ch == '*') {
                if (!result.empty())
                    result.pop_back();
            }
            else if (ch == '#') {
                result += result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
            else {
                result += ch;
            }
        }

        return result;
    }
};