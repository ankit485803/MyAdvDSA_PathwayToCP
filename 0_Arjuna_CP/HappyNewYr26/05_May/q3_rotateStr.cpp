#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // Rotate left by 2 positions (30 becomes the first element)
    rotate(v.begin(), v.begin() + 2, v.end());

    // Result: 30, 40, 50, 10, 20
    for (int n : v) cout << n << " ";

    return 0;
}


// Rotate right by 2 positions
rotate(v.rbegin(), v.rbegin() + 2, v.rend());




/*

3rd May 2026 (Sunday)

qno 796  https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2026-05-03

In C++, the most common way to rotate elements is using std::rotate, which is part of the algorithm header. It rearranges elements in a range so that a specific element becomes the new first element

This function performs a left rotation in-place on any container that supports forward iterators, such as std::vector, std::list, or primitive arrays. 
Syntax: std::rotate(first, middle, last);
first: Iterator to the start of the range.
middle: Iterator to the element that should become the new first element.
last: Iterator to the end of the range (one past the last element).
Returns: An iterator to the new position of the original first element. 
 Left Rotation
Rotating a vector {10, 20, 30, 40, 50} so that 30 becomes the first element:




796. Rotate String
Solved
Easy
Topics

Companies
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
874,381/1.3M
Acceptance Rate
66.1%
Topics
Mid Level
String
String Matching
Weekly Contest 75

*/


class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if (m != n) 
            return false;

        // Try all possible rotations of the string
        for (int rotationCount = 1; rotationCount <= m; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end()); //it says that I want (s.begin()+1)th character to become the first character now. i.e. shifting left by one
            if (s == goal) 
                return true;
        }
        return false;
    }
};



class Solution {
public:
    bool rotateString(string s, string goal) {  //tc=O(n^2) nestedWork, sc=O(1)
        int m = s.length(); 
        int n = goal.length();

        if(m != n) {
            return false;
        }

        //bruteForceally check all possible rotation
        for(int rotationCount = 1; rotationCount <= m; rotationCount++) {
            //using STL c++ 
            rotate(s.begin(), s.begin() + 1, s.end());

            if(s == goal) {
                return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() &&
               (s + s).find(goal) != string::npos;
    }
};




//Approach-2 (Concatenation with itself contains all possible rotations)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        
        if(m == n && (s+s).find(goal) != string::npos)
            return true;
        
        return false;
    }
};