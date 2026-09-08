

/*

8th Sep 2026 (Tuesday)

qno 3870  https://leetcode.com/problems/count-commas-in-range/?envType=daily-question&envId=2026-09-08

You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.
 

Example 1:
Input: n = 1002
Output: 3
Explanation:

The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

Example 2:
Input: n = 998
Output: 0
Explanaion:
All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

 

Constraints:
1 <= n <= 105

*/


class Solution {
public:
    int countCommas(int n) {  
        //by observation tc=O(no of digits in range), sc=O(1) Ankit
        int count = 0;
        
        for(int i = 999; i < n; i++) {
            count++;
        }

        return count;
    }
};



class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        int i = 999;  //intilize
        while(i < n) {
            count++;
            i++;
        }

        return count;
    }
};



//Approach-1 (Simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countCommas(int n) {
        int result = 0;
        for (int num = 1; num <= n; num++) {
            if (num > 999) {
                result += 1;
            }
        }

        return result;
    }
};



//Approach-2 (Simple observation)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int countCommas(int n) {
        return max(n-999, 0);
    }
};