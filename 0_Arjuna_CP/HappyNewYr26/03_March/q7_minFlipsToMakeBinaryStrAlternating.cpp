

/*


7th March 2026 (Satursday)


qno 1888   https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/?envType=daily-question&envId=2026-03-07


1888. Minimum Number of Flips to Make the Binary String Alternating
Medium
Topics

Companies
Hint
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
72,572/152.1K
Acceptance Rate
47.7%
Topics
Staff
String
Dynamic Programming
Sliding Window
Weekly Contest 244


*/



//Approach-1 (Sliding Window + modifying input s = s+s)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2 and s+=s
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = INT_MAX;

        while(j < 2*n) {

            // expand window
            if(s[j] != s1[j]) result1++;
            if(s[j] != s2[j]) result2++;

            // shrink if window exceeds n
            if(j - i + 1 > n) {
                if(s[i] != s1[i]) result1--;
                if(s[i] != s2[i]) result2--;
                i++;
            }

            // window size exactly n
            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};


//Approach-2 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = INT_MAX;

        while(j < 2*n) {
            
            // expand window
            if(s[j%n] != s1[j]) 
                result1++;
            if(s[j%n] != s2[j]) 
                result2++;

            // shrink if window exceeds n
            if(j - i + 1 > n) {
                if(s[i%n] != s1[i]) 
                    result1--;
                if(s[i%n] != s2[i]) 
                    result2--;
                i++;
            }

            // window size exactly n
            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};



//Approach-3 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        //khandani sliding window
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n) {

            char expectedCharS1 = (j%2) ? '1' : '0';
            char expectedCharS2 = (j%2) ? '0' : '1';

            if(s[j%n] != expectedCharS1) {
                flip1++;
            }

            if(s[j%n] != expectedCharS2) {
                flip2++;
            }

            if(j-i+1 > n) { //shrink the window from left
                expectedCharS1 = (i%2) ? '1' : '0';
                expectedCharS2 = (i%2) ? '0' : '1';

                if(s[i%n] != expectedCharS1) {
                    flip1--;
                }

                if(s[i%n] != expectedCharS2) {
                    flip2--;
                }

                i++;
            }

            if(j-i+1 == n) {
                result = min({result, flip1, flip2});
            }

            j++;

        }
        return result;
    }
};
