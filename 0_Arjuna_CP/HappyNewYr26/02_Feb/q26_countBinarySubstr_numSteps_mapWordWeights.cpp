



/*


26th Feb 2026 (Thursday)


qno 696  https://leetcode.com/problems/count-binary-substrings/?envType=daily-question&envId=2026-02-25


696. Count Binary Substrings
Easy
Topics

Companies
Hint
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
364,530/518.7K
Acceptance Rate
70.3%
Topics
Staff
Two Pointers
String



Count consecutive characters and form group sizes.
ans += min(groups[i], groups[i-1])

*/


class Solution {
public:
    int countBinarySubstrings(string s) {
        // Count consecutive characters and form group sizes.
        // ans += min(groups[i], groups[i-1])

        int prev = 0;
        int curr = 1;  //curr groupLeng
        int count = 0;

        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        count += min(prev, curr);
        return count;  //tc=O(n), sc=O(1)
    }
};






/*


qno 1404  https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2026-02-26


1404. Number of Steps to Reduce a Number in Binary Representation to One
Medium
Topics

Companies
Hint
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.

 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
Example 3:

Input: s = "1"
Output: 0
 

Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'
 
Discover more
LeetCode Training Programs
Seen this question in a real interview before?
1/5
Yes
No
Accepted
164,010/266K
Acceptance Rate
61.7%
Topics
Senior
String
Bit Manipulation
Simulation
Weekly Contest 183


*/






class Solution {
private:
    bool isEven(int num) {
        if(num < 2) return false;
        
        for(int i=2; i<=num; i++) {
            if(num % 2 == 0) {
                return true;
            }
        }
    }
    // bool isOdd(int num) {
    //     //not explicity create this funct because if num is not even then already odd
    // }   


public:
    int numSteps(string s) {
        int count = 0;  //count the reqSteps

        //step1: convert binaryStr into int num
        s.length can be up to 500
That means the number can be extremely large
❌ You cannot convert it to int / long long
✅ You must simulate operations directly on the binary strin


        //step2: if isEven(num) divide by 2 ; count++

        //step3: if odd then num+1; count++  til num==1

        return count;
    }
};




class Solution {
public:
    int numSteps(string s) {  //tc=O(n) sc=O(1)
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (ignore first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // odd → +1 and divide
                steps += 2;
                carry = 1;
            } else {
                // even → divide
                steps += 1;
                // carry remains same
            }
        }

        // If carry remains at MSB
        return steps + carry;
    }
};




/*


qno 3838   https://leetcode.com/problems/weighted-word-mapping/


3838. Weighted Word Mapping
Easy
Topics

Companies
Hint
You are given an array of strings words, where each string represents a word containing lowercase English letters.

You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.

The weight of a word is defined as the sum of the weights of its characters.

For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

Return a string formed by concatenating the mapped characters for all words in order.

 

Example 1:

Input: words = ["abcd","def","xyz"], weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]

Output: "rij"

Explanation:

The weight of "abcd" is 5 + 3 + 12 + 14 = 34. The result modulo 26 is 34 % 26 = 8, which maps to 'r'.
The weight of "def" is 14 + 1 + 2 = 17. The result modulo 26 is 17 % 26 = 17, which maps to 'i'.
The weight of "xyz" is 7 + 7 + 2 = 16. The result modulo 26 is 16 % 26 = 16, which maps to 'j'.
Thus, the string formed by concatenating the mapped characters is "rij".

Example 2:

Input: words = ["a","b","c"], weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

Output: "yyy"

Explanation:

Each word has weight 1. The result modulo 26 is 1 % 26 = 1, which maps to 'y'.

Thus, the string formed by concatenating the mapped characters is "yyy".

Example 3:

Input: words = ["abcd"], weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]

Output: "g"

Explanation:​​​​​​​

The weight of "abcd" is 7 + 5 + 3 + 4 = 19. The result modulo 26 is 19 % 26 = 19, which maps to 'g'.

Thus, the string formed by concatenating the mapped characters is "g".

 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 10
weights.length == 26
1 <= weights[i] <= 100
words[i] consists of lowercase English letters.
 
Discover more
Computer science textbooks
Seen this question in a real interview before?
1/5
Yes
No
Accepted
43,459/51.1K
Acceptance Rate
85.0%
Topics
Mid Level
Array
String
Simulation
Biweekly Contest 176


*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (const string& word : words) {
            int sum = 0;

            // Calculate total weight of word
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int mod = sum % 26;

            // Reverse alphabetical mapping
            char mappedChar = 'z' - mod;

            result += mappedChar;
        }

        return result;
    }
};