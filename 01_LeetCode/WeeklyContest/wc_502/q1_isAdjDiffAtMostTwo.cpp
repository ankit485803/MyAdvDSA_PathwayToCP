

/*

17th May 2026 (Sunday) LeetCode weekly contest 502 

https://leetcode.com/contest/weekly-contest-502/

q1 https://leetcode.com/contest/weekly-contest-502/problems/check-adjacent-digit-differences/description/
probNo 3931 https://leetcode.com/problems/check-adjacent-digit-differences/description/



Q1. Check Adjacent Digit Differences
Easy
3 pt.
You are given a string s consisting of digits.

Return true if the absolute difference between every pair of adjacent digits is at most 2, otherwise return false.

The absolute difference between a and b is defined as abs(a - b).

 

Example 1:

Input: s = "132"

Output: true

Explanation:

The absolute difference between digits at s[0] and s[1] is abs(1 - 3) = 2.
The absolute difference between digits at s[1] and s[2] is abs(3 - 2) = 1.
Since both differences are at most 2, the answer is true.
Example 2:

Input: s = "129"

Output: false

Explanation:

The absolute difference between digits at s[0] and s[1] is abs(1 - 2) = 1.
The absolute difference between digits at s[1] and s[2] is abs(2 - 9) = 7, which is greater than 2.
Therefore, the answer is false.
 

Constraints:

2 <= s.length <= 100
s consists only of digits.



*/


class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {  //myFirstAttempt approach
        //step1: convert str to int
        int num = stoi(s);
        vector<int> arr;

        //step2: put digits into arr
        while(num > 0) {
            int lastD = num % 10;
            arr.push_back(lastD);
            num /= 10;  //removeLastD
        }

        //step3: check absDiff
        for(int i=0; i < arr.size(); i++) {
            if(abs(arr[i] - arr[i+1]) <= 2) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {

        for(int i=0; i < s.length() - 1; i++) {
            int curr = s[i] - '0';
            int next = s[i + 1] - '0';

            if(abs(curr - next) > 2) {
                return false;
            }
        }

        return true;
    }
};




class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {  //tc=O(n), sc=O(1)
        
        for(int i = 1; i < s.length(); i++) {
            if(abs(s[i] - s[i-1]) > 2) return false;
        }
        return true;
    } 
};