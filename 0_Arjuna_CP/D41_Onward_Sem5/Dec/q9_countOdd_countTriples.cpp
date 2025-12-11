


/*


11th Dec 2025 (Thursday)

qno 1523  https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/



1523. Count Odd Numbers in an Interval Range
Easy
Topics

Companies
Hint
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
 

Constraints:

0 <= low <= high <= 10^9




*/


class Solution {
public:
    int countOdds(int low, int high) {  //tc=O(n), sc=O(1)
        int count = 0;
        int i = 0; // as a index

        i = low;
        while(i <= high) {
            if(i % 2 == 1) {  //ODD conditon remainer 1
                count++;
            }
            i++;
        }

        return count;
    }
};



//Optimal Logic (Mathematical)
class Solution {
public:
    int countOdds(int low, int high) {  //tc = O(1) = sc
        // If both low and high are even.
        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;
        
        // Otherwise, at least one is odd → add one more.
        return (high - low) / 2 + 1;
    }
};





class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};






/*

qno 1925  https://leetcode.com/problems/count-square-sum-triples/description/








*/