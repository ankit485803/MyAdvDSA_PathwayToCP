



/*

16th Feb 2026 (Monday)


qno 190  https://leetcode.com/problems/reverse-bits/?envType=daily-question&envId=2026-02-16


190. Reverse Bits
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

 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,224,201/1.8M
Acceptance Rate
66.7%
Topics
Divide and Conquer
Bit Manipulation


*/


class Solution {
public:
    int reverseBits(int n) {
        if(n == 0) return 0;  //edgeCase
        if(n == 1) return 1;

        //step1: convert n into binaryForm 32 bit

        //step2: revBinary

        //step3: return in decialForm

    }
};



class Solution {
public:
    int reverseBits(int n) {  //AnkitFirstApproach
        string bin = bitset<32>(n).to_string();  // step1
        
        reverse(bin.begin(), bin.end());         // step2
        
        return bitset<32>(bin).to_ulong();       // step3
    }
};








class Solution {
public:
    int reverseBits(int n) {  //method2: noManuallyConvert - BitManipulation tc=O(32)=sc = O(constant)
        uint32_t result = 0;
        
        for(int i = 0; i < 32; i++) {
            result <<= 1;          // make space for next bit
            result |= (n & 1);     // add last bit of n
            n >>= 1;               // shift n right
        }
        
        return result;
    }
};



| Operator | Meaning                |
| -------- | ---------------------- |
| `<<`     | Left shift             |
| `>>`     | Right shift            |
| `<<=`    | Left shift and assign  |
| `>>=`    | Right shift and assign |
