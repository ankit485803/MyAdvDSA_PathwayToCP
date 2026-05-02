

/*

2nd May 2026 (Saturday)

qno 788  https://leetcode.com/problems/rotated-digits/?envType=daily-question&envId=2026-05-02

788. Rotated Digits
Solved
Medium
Topics

Companies
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Example 2:

Input: n = 1
Output: 0
Example 3:

Input: n = 2
Output: 1
 

Constraints:

1 <= n <= 104
 
Discover more
Programming
Mathematics
Math
Seen this question in a real interview before?
1/6
Yes
No
Accepted
167,389/276.6K
Acceptance Rate
60.5%
Topics
Senior
Math
Dynamic Programming
Weekly Contest 73


*/

class Solution {
public:
    
    bool isGood(int num) {  //O(logm Num)
        bool changed = false;

        while(num > 0) {
            int digit = num % 10;

            if(digit == 3 || digit == 4 || digit == 7) return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) changed = true;

            num /= 10;  //removeLastD
        }
        return changed;
    }


    int rotatedDigits(int n) {  //tc=O(n * logNum), sc=O(1)
        int count = 0;

        for(int i = 1; i <= n; i++) {  //O(n)
            if(isGood(i)) {
                count++;
            }
        }
        return count;
    }
};


//Approach-1 (Brute Force SImulation)
//T.C : O(n)
//S.C : O(n* log10(num))
class Solution {
public:

    bool isGood(int num) {
        bool changed = false;

        while(num > 0) {
            int digit = num%10;

            if(digit == 3 || digit == 4 || digit == 7) return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) changed = true;

            num /= 10;
        }
        return changed;
    }

    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {
            if(isGood(i)) {
                count++;
            }
        }
        return count;
    }
};



//Approach-2 (Recursion Memo)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> t;

    int solve(int num) {
        if(t[num] != -1)
            return t[num];

        if(num == 0)
            return t[num] = 0;
        
        int remain = solve(num/10);
        if(remain == 2)
            return t[num] = 2;

        int digit_check;
        int d = num%10;

        if (d == 0 || d == 1 || d == 8) 
            digit_check = 0;       // same
        else if (d == 2 || d == 5 || d == 6 || d == 9) 
            digit_check = 1;       // good
        else 
            return t[num] = 2;     // invalid


        if(remain == 0 && digit_check == 0) {
            return t[num] = 0;
        }

        return t[num] = 1;
        
    }

    int rotatedDigits(int n) {
        int count = 0;
        t.resize(n+1, -1);

        //0 : same
        //1 : Good
        //2 : invalid
        for(int i = 1; i <= n; i++) {
            if(solve(i) == 1) {
                count++;
            }
        }

        return count;
    }
};


//Approach-3 (Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> t(n+1, -1);

        t[0] = 0;
        int count= 0;

        for(int i = 1; i <= n; i++) {
            int remain = t[i/10]; //solve(num/10)

            if(remain == 2) {
                t[i] = 2;
                continue;
            }

            int d = i%10;
            int digit_check;

            if (d == 0 || d == 1 || d == 8) 
                digit_check = 0;       // same
            else if (d == 2 || d == 5 || d == 6 || d == 9) 
                digit_check = 1;       // good
            else {
                t[i] = 2;              // invalid
                continue;
            }

            if(remain == 0 && digit_check == 0)
                t[i] = 0;
            else
                t[i] = 1;

            if(t[i] == 1) {
                count++;
            }
        }

        return count;
    }
};

