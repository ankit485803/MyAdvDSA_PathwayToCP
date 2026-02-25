


/*

25th Feb 2026 (Wednesday)


qno 1356   https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2026-02-25


1356. Sort Integers by The Number of 1 Bits
Easy
Topics

Companies
Hint
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
271,192/342.6K
Acceptance Rate
79.2%
Topics
Mid Level
Array
Bit Manipulation
Sorting
Counting
Biweekly Contest 20




__builtin_popcount(x) is a built-in function provided by the GCC (GNU Compiler Collection) and Clang compilers that 
returns the number of set bits (bits with a value of 1, also known as the 
"population count" or Hamming weight) in the binary representation of an unsigned integer




*/


myBruteForce approach:
step1: store count of 1's bit each arr[elem] 
step2: sort arr w.r.t count value in ascendingOrder
step3: return sortedArr


__builtin_popcount(x)


#include <iostream>

int main() {
    int n = 13; // Binary: 1101
    // The compiler implicitly converts int to unsigned int for this function
    std::cout << "Count of 1s in binary of " << n << " is " << __builtin_popcount(n) << std::endl;
    return 0;
}
// Output: Count of 1s in binary of 13 is 3





class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {  //tc=O(nlogN), sc=O(1)
        sort(arr.begin(), arr.end(), [](int a, int b) {

            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);

            if(countA == countB) {
                return a < b;  //sort by value if bit same
            }

            return countA < countB;  //sort by bitCount
        });

        return arr;
    }
};






/*


qno 762  https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/?envType=daily-question&envId=2026-02-25


762. Prime Number of Set Bits in Binary Representation
Solved
Easy
Topics

Companies
Hint
Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.
 

Example 1:

Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
Example 2:

Input: left = 10, right = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.
 

Constraints:

1 <= left <= right <= 106
0 <= right - left <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
249,915/318K
Acceptance Rate
78.6%
Topics
Junior
Math
Bit Manipulation
Weekly Contest 67


*/



class Solution {
private:
    bool isPrime(int n) {
        if(n < 2) return false;

        for(int i=2; i*i <=n; i++) {
            if(n % i == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {  //tc=O(n), sc=O(1)
        int count = 0;

        for(int num = left; num <= right; num++) {
            int bits = __builtin_popcount(num);  //total 1s bit
            if(isPrime(bits)) {
                count++;
            }
        }

        return count;
    }
};






/*


qno 693  https://leetcode.com/problems/binary-number-with-alternating-bits/?envType=daily-question&envId=2026-02-25


693. Binary Number with Alternating Bits
Easy
Topics

Companies
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
 

Constraints:

1 <= n <= 231 - 1
 
Discover more
Algorithm visualization software
Seen this question in a real interview before?
1/5
Yes
No
Accepted
294,723/422.5K
Acceptance Rate
69.8%
Topics
Mid Level
Bit Manipulation


*/



class Solution {
public:
    bool hasAlternatingBits(int n) {  //tc=O(1)=sc using bitManipulation approach
        // XOR the number with the right-shifted version of itself
        int shifted = n ^ (n >> 1);
        
        // Check if the result is all 1s (i.e., shifted should be of the form 111...111)
        return (shifted & (shifted + 1)) == 0;
    }
};




#include <bitset>

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Convert integer to binary string (using bitset for a 32-bit representation)
        string num = bitset<32>(n).to_string(); 

        // Trim leading zeros (unnecessary part for comparison)
        num = num.substr(num.find('1'));

  
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] == num[i + 1]) {
                return false;  
            }
        }

        return true; 
    }
};