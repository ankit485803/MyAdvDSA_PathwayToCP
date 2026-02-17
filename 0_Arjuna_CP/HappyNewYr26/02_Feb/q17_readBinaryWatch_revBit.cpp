



/*


17th Feb 2026 (Tuesday)


qno 190  https://leetcode.com/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-17

190. Reverse Bits
Solved
Easy
Topics

Companies
Reverse bits of a given 32 bits signed integer.

 

Example 1:

Input: n = 43261596

Output: 964176192

Explanation:

Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000
Example 2:

Input: n = 2147483644

Output: 1073741822

Explanation:

Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110
 

Constraints:

0 <= n <= 231 - 2
n is even.
 

Follow up: If this function is called many times, how would you optimize it?

 
Discover more
Online coding bootcamps
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,283,410/1.9M
Acceptance Rate
67.6%
Topics
Divide and Conquer
Bit Manipulation


*/


class Solution {
public:
    int reverseBits(int n) { //tc=O(1)=sc bruteForce, but optimized using BitManipulation


        //step1: convert n str into binary
        string result = bitset<32>(n).to_string();

        //step2: revBits
        reverse(result.begin(), result.end());

        //step3: return as in decaimlForm
        return bitset<32>(result).to_ulong();
    }
};






/*


qno 



401. Binary Watch
Easy
Topics

Companies
Hint
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

For example, the below binary watch reads "4:51".


Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".
 

Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
Example 2:

Input: turnedOn = 9
Output: []
 

Constraints:

0 <= turnedOn <= 10
 
Discover more
Watch
watch
Seen this question in a real interview before?
1/5
Yes
No
Accepted
190,386/324.6K
Acceptance Rate
58.6%
Topics
Junior
Backtracking
Bit Manipulation


*/




class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {  //tc=O(1) sc=O(dependOn outputSize)
        vector<string> result;
        
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                
                // count total 1-bits in hour and minute
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    
                    // format time correctly
                    string time = to_string(h) + ":";
                    
                    if (m < 10)
                        time += "0";   // ensure 2-digit minute
                    
                    time += to_string(m);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};
