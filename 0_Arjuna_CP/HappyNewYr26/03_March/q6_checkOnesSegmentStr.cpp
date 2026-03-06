

/*

6th March 2026 (Friday)


qno 1784   https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/?envType=daily-question&envId=2026-03-06


1784. Check if Binary String Has at Most One Segment of Ones
Attempted
Easy
Topics

Companies
Hint
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
Example 2:

Input: s = "110"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
71,475/172K
Acceptance Rate
41.5%
Topics
Mid Level
String
Weekly Contest 231


*/



class Solution {
public:
    bool checkOnesSegment(string s) { //tc=O(n), sc=O(1)  my wrongAns in first approach
        int count = 0;  //counts contiguous ONES
        int idx = 0;

        while(idx < s.size()) {
            if(s[idx] == '1' && s[idx + 1] == '1') {  //next two
                count++;
                idx++;
            }
        }

        //conditions
        if(count >= 1) {
            return true;
        } else {
            return false;
        }
    }
};


/*
2. Infinite loop
idx is only incremented inside the if.
If the condition is false, idx never increases → infinite loop.
3. Out-of-bounds access
s[idx + 1] may exceed the string length when idx == s.size() - 1.


The easiest trick is:
If "01" appears, that means a zero ended a segment of 1 and another 1 started later → multiple segments.


*/


class Solution {
public:
    bool checkOnesSegment(string s) {
        int segments = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                segments++;
            }
        }

        return segments <= 1;
    }
};



class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};



class Solution {
public:
    bool checkOnesSegment(string s) {
        int segmentS = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                segmentS++;
            }
        }

        //return segmentS <= 1;
        if(segmentS <= 1) {
            return true;
        } else {
            return false;
        }
    }
};