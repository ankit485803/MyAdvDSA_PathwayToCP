


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