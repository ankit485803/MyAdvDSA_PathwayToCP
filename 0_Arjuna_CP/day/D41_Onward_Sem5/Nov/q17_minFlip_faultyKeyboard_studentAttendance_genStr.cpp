


/*

25th Nov 2025 (Tuesday)


qno 3750  https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/


3750. Minimum Number of Flips to Reverse Binary String
Easy

Companies
Hint
You are given a positive integer n.

Let s be the binary representation of n without leading zeros.

The reverse of a binary string s is obtained by writing the characters of s in the opposite order.

You may flip any bit in s (change 0 → 1 or 1 → 0). Each flip affects exactly one bit.

Return the minimum number of flips required to make s equal to the reverse of its original form.

 

Example 1:

Input: n = 7

Output: 0

Explanation:

The binary representation of 7 is "111". Its reverse is also "111", which is the same. Hence, no flips are needed.

Example 2:

Input: n = 10

Output: 4

Explanation:

The binary representation of 10 is "1010". Its reverse is "0101". All four bits must be flipped to make them equal. Thus, the minimum number of flips required is 4.


Constraints:

1 <= n <= 109



where we convert into binaryForm
we don't explicitly convert the integer into a binary string, but we manipulate the bits directly to compare the binary digits. 
In C++, this is done through bitwise operations. So, you don't need to manually convert the integer into a binary string; the process of comparing the bits is handled by shifting the bits and checking their values.


*/


class Solution {
public:
    int minimumFlips(int n) {
        //As we know every int or str store in pc BINARY FORM
        int countF = 0;  //flipCount

        int bitLeng = log2(n)-1; // Find no of bits req to represent 'n'

        for(int i=0; i<bitLeng / 2; ++i) {
            int lBit = (n >> i) & 1;  //leftBit - Get the i-th bit from left SHIFT
            int rBit = (n >> (bitLeng - i-1)) & 1;

            //if bits diff, needToFlip
            if(lBit != rBit) {
                countF++;
            }
        }

        return countF;

        
    }
};





class Solution {
public:
    int minimumFlips(int n) {  //TC=O(logN), SC=O(1)
        int countF = 0;  //flipCount

        int bitLeng = floor(log2(n)) + 1; 

        for(int i=0; i<bitLeng; i++) {
            int sBit = (n >> (bitLeng - 1 - i)) & 1;  //bit from LEFT
            int revBit = (n >> i) & 1;   //bit from right

            if(sBit != revBit) {
                countF++;   // must flip s[i]
            }
        }

        return countF;

        
    }
};



/*

qno 2810  https://leetcode.com/problems/faulty-keyboard/description/

2810. Faulty Keyboard
Easy
Topics

Companies
Hint
Your laptop keyboard is faulty, and whenever you type a character 'i' on it, it reverses the string that you have written. Typing other characters works as expected.

You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.

Return the final string that will be present on your laptop screen.

 

Example 1:

Input: s = "string"
Output: "rtsng"
Explanation: 
After typing first character, the text on the screen is "s".
After the second character, the text is "st". 
After the third character, the text is "str".
Since the fourth character is an 'i', the text gets reversed and becomes "rts".
After the fifth character, the text is "rtsn". 
After the sixth character, the text is "rtsng". 
Therefore, we return "rtsng".
Example 2:

Input: s = "poiinter"
Output: "ponter"
Explanation: 
After the first character, the text on the screen is "p".
After the second character, the text is "po". 
Since the third character you type is an 'i', the text gets reversed and becomes "op". 
Since the fourth character you type is an 'i', the text gets reversed and becomes "po".
After the fifth character, the text is "pon".
After the sixth character, the text is "pont". 
After the seventh character, the text is "ponte". 
After the eighth character, the text is "ponter". 
Therefore, we return "ponter".
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.
s[0] != 'i'

*/

class Solution {
public:
    string finalString(string s) {  //TC=O(n) = SC
        
        string ans = "";

        for(char c : s) {
            if(c == 'i') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += c;
            }
        }

        return ans;
    }
};




/*

qno  551   https://leetcode.com/problems/student-attendance-record-i/


551. Student Attendance Record I
Easy
Topics

Companies
You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
The student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Return true if the student is eligible for an attendance award, or false otherwise.

 

Example 1:

Input: s = "PPALLP"
Output: true
Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.
Example 2:

Input: s = "PPALLL"
Output: false
Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
 

Constraints:

1 <= s.length <= 1000
s[i] is either 'A', 'L', or 'P'.



*/



class Solution {
public:
    bool checkRecord(string s) {  //TC=O(n), SC=O(1)
        
        //myApraoch: 1. count Freq of eachChar and 2. apply elgibileCriteria - if(A <= 2 && L<= 3)
        int countA = 0;
        int consecutiveL = 0;

        for(char c : s) {
            if(c == 'A') {
                countA++;
                if(countA >= 2) return false;
                consecutiveL = 0; //reset L streak

            } else if(c == 'L') {
                consecutiveL++;
                if(consecutiveL >= 3) return false;

            } else {  // p
                consecutiveL = 0;
            }
        }
        return true;

    }
};




/*

qno 1374  https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/


1374. Generate a String With Characters That Have Odd Counts
Easy
Topics

Companies
Hint
Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  

 

Example 1:

Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
Example 2:

Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
Example 3:

Input: n = 7
Output: "holasss"
 

Constraints:

1 <= n <= 500


*/


class Solution {
public:
    string generateTheString(int n) {  //tc=O(n) = sc, space used to store the result strin
        string result = "";
        
        // If n is odd, use a single character repeated n times
        if (n % 2 == 1) {
            result = string(n, 'a');  
        }

        // If n is even, alternate between 'a' and 'b'
        else {
            result = string(n - 1, 'a') + "b";  // Fill with 'a's, and add a single 'b'
        }
        
        return result;
    }
};



/*


qno 3754  https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/


3754. Concatenate Non-Zero Digits and Multiply by Sum I
Easy
premium lock icon
Companies
Hint
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

 

Example 1:

Input: n = 10203004

Output: 12340

Explanation:

The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
Therefore, the answer is x * sum = 1234 * 10 = 12340.
Example 2:

Input: n = 1000

Output: 1

Explanation:

The non-zero digit is 1, so x = 1 and sum = 1.
Therefore, the answer is x * sum = 1 * 1 = 1.
 

Constraints:

0 <= n <= 109


*/




class Solution {
public:
    long long sumAndMultiply(int n) {   //TC=O(n, digits)
        long long x = 0;  
        int sum = 0;   


        if (n == 0) {
            return 0; 
        }

        vector<int> nonZeroDigits;


        while (n > 0) {
            int digit = n % 10;  // Get the last digit of n
            n /= 10;             // Remove the last digit from n

            if (digit != 0) {    
                nonZeroDigits.push_back(digit); 
                sum += digit;            
            }
        }

        // Build x by concatenating digits in the correct order
        for (int i = nonZeroDigits.size() - 1; i >= 0; --i) {
            x = x * 10 + nonZeroDigits[i];  
        }


        return x * sum;
    }
};




/*


qno 1408  https://leetcode.com/problems/string-matching-in-an-array/description/



Code
Testcase
Testcase
Test Result
1408. String Matching in an Array
Easy
Topics

Companies
Hint
Given an array of string words, return all strings in words that are a substring of another word. You can return the answer in any order.

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.


*/


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {  
        

        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            
            // Inner loop to check if the current word is a substring of any other word
            for (int j = 0; j < words.size(); j++) {
                
                if (i != j) {
                    if (words[j].find(words[i]) != string::npos) {
                    
                        result.push_back(words[i]);
                        break;
                    }
                }
            }
        }

        return result;
    }
};
